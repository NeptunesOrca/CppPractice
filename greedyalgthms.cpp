#include <iostream>
#include <vector>

#include "scheduler.hpp"
//#include "course.hpp"

/*
    == QUESTION 1: CHAOS UNIVERSITY ==
    - courses don't follow an hourly schedule
    - goal: take as many courses as possible
    - will need to fit all courses between some arbitrary start and end time
    - will need to leave at least 10 time units between courses
    - courses are represented as with two integers between 0 - 99 999, representing the start time and end time
    - scheduler class should be initialized with a classlist
    - scheduler class should have a function to calculate the max classes that can be taken
*/
int main() {
    std::vector<Course> classList1 = {Course(0,50), Course(60,80), Course(0, 20), Course(80, 100), Course(110, 120), Course(10, 30), Course(40, 70), Course(80, 90)};
    Scheduler test(classList1);
    std::cout << test.maxClasses(0, 100) << "\n"; //should be 3
    std::cout << test.maxClasses(10, 30) << "\n"; //should be 1
    std::cout << test.maxClasses(10, 29) << "\n"; //should be 0
    std::cout << test.maxClasses(0, 120) << "\n"; //should be 5
}