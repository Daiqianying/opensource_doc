#include <iostream>

#include <curl/curl.h>

int main()
{
    std::cout << ::curl_version();
    std::cout << std::endl;
    return 0;
}
