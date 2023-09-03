#include <iostream>
#include "easyhttp.cpp"

int main(int, char **)
{
        EasyHTTP http;

        /*
                Usage:
                http.get(url)
                        .then(lambda function)
                        .catchErr(lambda function)
        */

        // Get req demo
        http.get("https://httpbin.org/get")
            .then([](const cpr::Response &response)
                  {
                std::cout << response.status_code << std::endl;
                std::cout << response.text << std::endl; })
            .catchErr([](const cpr::Error &error)
                      { std::cout << "Request failed with error: " << error.message << std::endl; });

        // Post req with error demo
        http.post("https://tpbin.org/post",
                  {{"Content-Type", "application/json"}},
                  {{"key1", "value1"}, {"key2", "value2"}})
            .then([](const cpr::Response &response)
                  {
                std::cout << response.status_code << std::endl;
                        std::cout << response.text << std::endl; })
            .catchErr([](const cpr::Error &error)
                      { std::cout << "Request failed with error: " << error.message << std::endl; });

        return 0;
}