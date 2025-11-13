#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <numeric>
#include <cmath>

class Student {
private:
    std::pair<int, int> name;
    bool vaccinated;

public:
    Student(std::pair<int, int> n, bool v) : name(n), vaccinated(v) {}

    auto get_name() const { return name; }
    auto is_vaccinated() const { return vaccinated; }

    bool operator==(const Student& p) const {
        return this->name == p.name;
    }

    bool operator<(const Student& p) const {
        return this->name < p.name;
    }

    bool operator>(const Student& p) const {
        return this->name > p.name;
    }
};

Student generate_random_Student(int max);
bool needs_vaccination(Student P, std::vector<Student>& people);
void search_test(int size, Student p);

#endif
