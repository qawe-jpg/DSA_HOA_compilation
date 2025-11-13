#include <iostream>
#include <queue>
#include <string>

int main() {
    std::queue<std::string> printerQueue;

    printerQueue.push("Einstein job");
    printerQueue.push("Tesla job");
    printerQueue.push("Curie job");

    std::cout << "Initialize sequence...\n";

    while (!printerQueue.empty()) {
        std::cout << "Executing task: " << printerQueue.front() << std::endl;
        printerQueue.pop();
    }

    std::cout << "Mission accomplished.\n";

    return 0;
}

