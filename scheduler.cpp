#include <iostream>
#include <vector>

#include "scheduler.hpp"

#include "course.hpp"

Scheduler::Scheduler(std::vector<Course> const &classes) {
    available_classlist = classes;
}

int Scheduler::maxClasses(int start_time, int end_time) {
    //heuristic: course with earliest finish time

    //trim classlist
    std::vector<Course> classlist = available_classlist;

    //
    
}

void trim_classlist(std::vector<Course> &classlist, int start, int end) {
    for (Course current : classlist) {

    }
}