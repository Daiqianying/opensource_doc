# 在指定目录下寻找头文件和动态库文件的位置，可以指定多个目标路径

set(PC_CURL_INCLUDE_DIRS 
    "${CMAKE_CURRENT_LIST_DIR}/../libcurl-vc-x86-debug-dll-ipv6-sspi-winssl/include"
)

find_path(CURL_INCLUDE_DIR 
    NAMES curl/curl.h
    HINTS ${PC_CURL_INCLUDE_DIRS}
) 
#设定变量是高级的，用来覆盖别人
mark_as_advanced(${CURL_INCLUDE_DIR})

set(PC_CURL_LIBRARY_DIRS
    "${CMAKE_CURRENT_LIST_DIR}/../libcurl-vc-x86-debug-dll-ipv6-sspi-winssl/lib"
    "${CMAKE_CURRENT_LIST_DIR}/../libcurl-vc-x86-release-dll-ipv6-sspi-winssl/lib"
)

find_library(CURL_LIBRARY_RELEASE 
    libcurl
    HINTS ${PC_CURL_LIBRARY_DIRS}
)
mark_as_advanced(CURL_LIBRARY_RELEASE)
message(${CURL_LIBRARY_RELEASE})

find_library(CURL_LIBRARY_DEBUG
    libcurl_debug
    HINTS ${PC_CURL_LIBRARY_DIRS}
)
mark_as_advanced(CURL_LIBRARY_DEBUG)
message(${CURL_LIBRARY_DEBUG})

#调用CMake脚本设置一些变量，具体可参考文档 
#相当于使用绝对路径 SelectLibraryConfigurations.cmake
include(SelectLibraryConfigurations)
select_library_configurations(CURL)

if (CURL_INCLUDE_DIR AND CURL_LIBRARY_DEBUG)
    set(CURL_FOUND TRUE)
endif()

