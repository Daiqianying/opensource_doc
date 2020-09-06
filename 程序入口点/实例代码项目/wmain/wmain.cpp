// wmain.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <thread>

#include <Windows.h>

#include "../TestDLLMain/TestDllMainExport.h"

int wmain(int argc, wchar_t* argv[])
{
    SayHello();

    std::thread my(SayHello);
    my.join();

    std::cout << "Hello World wmain!\n";
    return 0;
}
