#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main() {
                                                            system("chcp 65001"); //	русские буквы вывода на экран
    std::string command = "unknown";
    do {
        std::cout << "Введите одну из команд(\"get\", \"post\", \"put\", \"delete\", \"patch\")" << '\n';
        std::cout << ":";
        std::cin >> command;
        if (command != "get" && command != "post" && command != "put" && command != "delete" && command != "patch")
            std::cout << "Неверная команда, попробуйте снова." << '\n';
    } while(command != "get" && command != "post" && command != "put" && command != "delete" && command != "patch");

    if (command == "get") {
        cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/get"));
        std::cout << r.text << "\n";
    } else if (command == "post") {
        cpr::Response r = cpr::Post(cpr::Url("http://httpbin.org/post"));
        std::cout << r.text << "\n";
    } else if (command == "put") {
        cpr::Response r = cpr::Put(cpr::Url("http://httpbin.org/put"));
        std::cout << r.text << "\n";
    } else if (command == "delete") {
        cpr::Response r = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
        std::cout << r.text << "\n";
    } else {
        cpr::Response r = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
        std::cout << r.text << "\n";
    }
}
