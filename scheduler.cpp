#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <stdlib.h>
#include <time.h>

#include "scheduler.hpp"

//#include "course.hpp"

bool compare_course_ends(Course c1, Course c2) { return c1.end < c2.end; }

Scheduler::Scheduler(std::vector<Course> const &classes) {
    available_classlist = classes;
    rng = std::mt19937(std::random_device());
}

int Scheduler::maxClasses(int start_time, int end_time) {
    //heuristic: course with earliest finish time

    //trim classlist
    std::vector<Course> classlist = available_classlist; //makes a copy of the available classes to alter for the test
    trim_classlist(classlist, start_time, end_time);
    print_classlist(classlist);

    //sort by end time
    std::shuffle(classlist.begin(), classlist.end(), rng);
    //Scheduler::shuffle(classlist);
    print_classlist(classlist);

    //
    
    return 0;
}

void Scheduler::trim_classlist(std::vector<Course> &classlist, int start, int end) {
    int i = 0;
    while (i < classlist.size()) {
        Course current = classlist[i];
        if (current.start < start || current.end > end) {    
            classlist.erase(classlist.begin()+i);
        } else {
            i++;
        }
    }
}

//for testing purposes
void Scheduler::print_classlist(std::vector<Course> &classlist) {
    std::cout << "[ ";
    for (Course current : classlist) {
        Scheduler::print_course(current);
        std::cout << " , ";
    }
    std::cout << "]\n";
}

void Scheduler::print_course(Course c1) {
    std::cout << "(" << c1.start << ", " << c1.end << ")";
}

void Scheduler::quicksort(std::vector<Course> &classlist) {
    //Random Quicksort
    Scheduler::shuffle(classlist);
    
}

void Scheduler::shuffle(std::vector<Course> &classlist) {
    //skip trivial cases
    if (classlist.size() <= 1) {
        return;
    }

    //Using the std lib shuffle, because mine doesn't work and I know how to make the std lib one work now
    std::shuffle(classlist.begin(), classlist.end(), rng);
}

int Scheduler::get_random_num(int max, int min = 0) {
    /*
    Note on std::mt19937 :
    To get a random number, we use the .operator() function on the object.
    However, this is called not by doing *mt_name*.operator(), but instead by calling *mt_name*()
    It's whack, but that's C++ for you. It's also kina cool
    */
    int random_num = (rng() % (max+1)) + min;
    return random_num;
}