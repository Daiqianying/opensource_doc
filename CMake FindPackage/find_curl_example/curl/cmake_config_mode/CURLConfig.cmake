#添加CURL动态库
add_library(CURL SHARED IMPORTED)

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

include(SelectLibraryConfigurations)
select_library_configurations(CURL)

set(CURL_INCLUDE_DIRS 
    "${CMAKE_CURRENT_LIST_DIR}/../libcurl-vc-x86-debug-dll-ipv6-sspi-winssl/include"
)

include_directories(${CURL_INCLUDE_DIRS})
set_target_properties(CURL PROPERTIES IMPORTED_LOCATION "${CURL_LIBRARYS}")

