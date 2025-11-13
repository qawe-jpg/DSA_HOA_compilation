#include <iostream>
#include <thread>
#include <vector>
#include <string>

// Function that each thread will execute
void print(int n, const std::string &str) {
    std::string msg = std::to_string(n) + " : " + str;
    std::cout << msg << std::endl;
}

int main() {
    // Vector of strings to pass as data to each thread
    std::vector<std::string> s = {
        "T.I.P.",
        "Competent",
        "Computer",
        "Engineers"
    };

    // Vector to hold all thread objects
    std::vector<std::thread> threads;

    // Launch a thread for each string in 's'
    for (int i = 0; i < s.size(); i++) {
        threads.push_back(std::thread(print, i, s[i]));
    }

    // Wait for all threads to finish before exiting main
    for (auto &th : threads) {
        th.join();
    }

    return 0;
}

