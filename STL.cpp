#include <iostream>
#include <queue>
#include <string>

int main() {
    std::queue<std::string> presidents;
    std::string names[] = {"Washington", "Lincoln", "Roosevelt", "Kennedy"};

    // Enqueue presidents with a slightly different message
    for (const auto& president : names) {
        std::cout << "Adding to queue: " << president << std::endl;
        presidents.push(president);
    }

    // Display the queue contents
    std::cout << "Queue contents after additions: ";
    std::queue<std::string> copy = presidents;  
    while (!copy.empty()) {
        std::cout << copy.front() << " ";
        copy.pop();
    }
    std::cout << "\n";

    // Dequeue and display each president
    while (!presidents.empty()) {
        std::cout << "Removing from queue: " << presidents.front() << std::endl;
        presidents.pop();
    }

    return 0;
}

