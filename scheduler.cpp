#include <iostream>
#include <vector>

#include "scheduler.hpp"

//#include "course.hpp"

Scheduler::Scheduler(std::vector<Course> const &classes) {
    available_classlist = classes;
}

int Scheduler::maxClasses(int start_time, int end_time) {
    //heuristic: course with earliest finish time

    //trim classlist
    std::vector<Course> classlist = available_classlist;
    print_classlist(classlist);
    trim_classlist(classlist, start_time, end_time);
    print_classlist(classlist);

    //
    
    return 0;
}

void Scheduler::trim_classlist(std::vector<Course> &classlist, int start, int end) {
    for (int i = 0; i < classlist.size(); i++) {
        Course current = classlist[i];
        if (current.start < start || current.end > end) {
            classlist.erase(classlist.begin()+i);
        }
    }
}

//for testing purposes
void Scheduler::print_classlist(std::vector<Course> &classlist) {
    std::cout << "[";
    for (Course current : classlist) {
        std::cout << " (" << current.start << ", " << current.end << ") ,";
    }
    std::cout << "]\n";
}