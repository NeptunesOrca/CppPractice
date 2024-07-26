#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "scheduler.hpp"

//#include "course.hpp"

bool compare_course_ends(Course c1, Course c2) { return c1.end < c2.end; }

Scheduler::Scheduler(std::vector<Course> const &classes) {
    available_classlist = classes;
    random_engine_is_seeded = false;
}

int Scheduler::maxClasses(int start_time, int end_time) {
    //heuristic: course with earliest finish time

    //trim classlist
    std::vector<Course> classlist = available_classlist; //makes a copy of the available classes to alter for the test
    trim_classlist(classlist, start_time, end_time);
    print_classlist(classlist);

    //sort by end time
    Scheduler::shuffle(classlist);
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


    int max_index = classlist.size() - 1;
    std::cout << max_index;
    int rand_index;

    for (int i = 0; i < max_index; i++) {
        rand_index = Scheduler::get_random_num(max_index, i);
        /*std::cout << "    - Swapping indices " << i << " and " << rand_index << " : ";
        Scheduler::print_course(classlist[i]);
        std::cout << " and ";
        Scheduler::print_course(classlist[rand_index]);
        std::cout << "\n";*/
        Scheduler::swap_courses(classlist[i], classlist[rand_index]);
    }
}

int Scheduler::get_random_num(int max, int min = 0) {
    if (!random_engine_is_seeded) {
        srand(time(NULL));
        random_engine_is_seeded = true;
    }
    
    int random_num = (rand() % (max+1)) + min;
    return random_num;
}

void Scheduler::swap_courses(Course c1, Course c2) {
    int temp_start = c1.start;
    int temp_end = c1.end;

    c1.start = c2.start;
    c1.end = c2.end;
    c2.start = temp_start;
    c2.end = temp_end;
}