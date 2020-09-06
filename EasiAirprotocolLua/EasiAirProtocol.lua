do
    --协议名称为EasiAirProtocol，在Packet Details窗格显示为seewo.pinco.EasiAirProtocol
    local p_EasiAirProtocol = Proto("EasiAirProtocol","seewo.pinco.EasiAirProtocol")
    
    --协议的各个字段
    local f_length = ProtoField.uint32("EasiAirProtocol.iength","Length")
    local f_version = ProtoField.uint8("EasiAirProtocol.version","Version")
    local f_sequence = ProtoField.uint32("EasiAirProtocol.sequence","Sequence")
    local f_cmdType = ProtoField.uint8("EasiAirProtocol.cmdType","CmdType")
    local f_cmdNumber = ProtoField.uint8("EasiAirProtocol.cmdNumber","CmdNumber")
    local f_data = ProtoField.bytes("EasiAirProtocol.data","Data")

    p_ScoreBoard.fields = { f_length, f_version, f_sequence, f_cmdType, f_cmdNumber, f_data }

    local data_dis = Dissector.get("data")
    local function EasiAirProtocol_dissector(buf,pkt,root)
        local buf_len = buf:len();
        --先检查报文长度，太短的不是我的协议
        if buf_len < 11 
        then 
            return false
        end
        
        --取得前16字节identifier字段的值
        local v_identifier = buf(0,16)
        
        --验证identifier是否正确
        if ((buf(0,1):uint()~=226) or (buf(1,1):uint()~=203) or (buf(2,1):uint()~=181)
            or (buf(3,1):uint()~=128) or (buf(4,1):uint()~=203) or (buf(5,1):uint()~=9)
            or (buf(6,1):uint()~=78) or (buf(7,1):uint()~=186) or (buf(8,1):uint()~=163)
            or (buf(9,1):uint()~=107) or (buf(10,1):uint()~=246) or (buf(11,1):uint()~=7)
            or (buf(12,1):uint()~=206) or (buf(13,1):uint()~=149) or (buf(14,1):uint()~=63)
            or (buf(15,1):uint()~=43))
            --不正确就不是我的协议
            then return false end
        --取得operator的值
        local v_operator = buf(16,1)
        local i_operator = v_operator:uint()
        --现在知道是我的协议了，放心大胆添加Packet Details
        local t = root:add(p_ScoreBoard,buf)
        --在Packet List窗格的Protocol列也可以“做个小广告”
        pkt.cols.protocol = "ScoreBoard"
        t:add(f_identifier,v_identifier)
        t:add(f_operator,v_operator)
        if ((i_operator == 1) or (i_operator == 128)) and (buf_len >= 25) then
            --把存在的字段逐个添加进去
            t:add(f_left,buf(17,4))
            t:add(f_right,buf(21,4))
        elseif ((i_operator == 17) or (i_operator == 144)) and (buf_len >= 20) then
            t:add(f_red,buf(17,1))
            t:add(f_green,buf(18,1))
            t:add(f_blue,buf(19,1))
        end
        return true
    end
    function p_ScoreBoard.dissector(buf,pkt,root) 
        if ScoreBoard_dissector(buf,pkt,root) then
            --valid ScoreBoard diagram
        else
            --data这个dissector几乎是必不可少的；当发现不是我的协议时，就应该调用data
            data_dis:call(buf,pkt,root)
        end
    end
    local udp_encap_table = DissectorTable.get("udp.port")
    --只需要处理UDP1127端口就可以了
    udp_encap_table:add(1127,p_ScoreBoard)
end