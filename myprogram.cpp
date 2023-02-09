#include <iostream>
#include <string>
#include <cpr/cpr.h>

void Commands(std::string& command, int& count) {
    if (command == "get") {
        cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/get"));
        std::cout << r.text << "\n";
        command = "unknown";
        count++;
    } else if (command == "post") {
        cpr::Response r = cpr::Post(cpr::Url("http://httpbin.org/post"));
        std::cout << r.text << "\n";
        command = "unknown";
        count++;
    } else if (command == "put") {
        cpr::Response r = cpr::Put(cpr::Url("http://httpbin.org/put"));
        std::cout << r.text << "\n";
        command = "unknown";
        count++;
    } else if (command == "delete") {
        cpr::Response r = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
        std::cout << r.text << "\n";
        command = "unknown";
        count++;
    } else if (command == "patch") {
        cpr::Response r = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
        std::cout << r.text << "\n";
        command = "unknown";
        count++;
    }
}

int main() {
    std::string command = "unknown";
    int count = 0;
    do {
        //std::cout << "Enter one of the commands(\"get\", \"post\", \"put\", \"delete\", \"patch\", \"exit\")" << '\n';
        std::cout << "Enter one of the commands(get/post/put/delete/patch/exit)" << '\n';
        std::cout << ":";
        std::cin >> command;
        if (command != "get" && command != "post" && command != "put" && command != "delete" && command != "patch" && command != "exit") {
            std::cout << "Invalid command, please try again." << '\n';
        } else
            Commands(command, count);

        if (command == "exit" && count == 0 )
            command = "unknown";

    } while(command != "exit");
}
