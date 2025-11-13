#include <iostream>
#include <thread>
#include <string>

// Function that the thread will execute
void print(int n, const std::string &str) {
    std::cout << "Printing integer: " << n << std::endl;
    std::cout << "Printing string: " << str << std::endl;
}

int main() {
    // Create a thread that runs the print function
    std::thread t1(print, 10, "T.I.P.");

    // Wait for the thread to finish before exiting main
    t1.join();

    return 0;
}

