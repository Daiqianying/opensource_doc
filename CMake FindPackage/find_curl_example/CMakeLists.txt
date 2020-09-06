cmake_minimum_required(VERSION 3.17)

set(LABELNAME curltest)

project(${LABELNAME})
add_executable(${LABELNAME} main.cc)

#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/curl/cmake_module_mode;${CMAKE_MODULE_PATH}")
#find_package(CURL MODULE)
#message("CMAKE_MODULE_PATH is: " ${CMAKE_MODULE_PATH})

set(CURL_DIR "${CMAKE_SOURCE_DIR}/curl/cmake_config_mode")
find_package(CURL NO_MODULE)

message("CURL_LIBRARY is: " ${CURL_LIBRARY})
if(CURL_FOUND)
    target_include_directories(${LABELNAME} PRIVATE ${CURL_INCLUDE_DIR})
    target_link_libraries(${LABELNAME} ${CURL_LIBRARY})
else(CURL_FOUND)
    message(FATAL_ERROR ”CURL library not found”)
endif(CURL_FOUND)
