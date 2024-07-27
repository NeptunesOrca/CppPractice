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
    rng = std::mt19937(time(NULL));
}

int Scheduler::maxClasses(int start_time, int end_time) {
    //heuristic: course with earliest finish time

    //trim classlist
    std::vector<Course> classlist = available_classlist; //makes a copy of the available classes to alter for the test
    trim_classlist(classlist, start_time, end_time);
    print_classlist(classlist);

    //sort by end time
    Scheduler::quicksort(classlist);
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
        print_course(current);
        std::cout << " , ";
    }
    std::cout << "]\n";
}

void Scheduler::print_course(Course c1) {
    std::cout << "(" << c1.start << ", " << c1.end << ")";
}

void Scheduler::quicksort(std::vector<Course> &classlist) {
    //Random Quicksort
    shuffle(classlist);

    //Quicksort recursion
    qsort_recurse(classlist, 0, (classlist.size()-1));
}

void Scheduler::qsort_recurse(std::vector<Course> &classlist, int p, int r) {
    if (p == r) {
        // array of size 1, no further sorting needed
        return;
    }
    
    // q the index of the pivot in it's final position
    int q = qsort_partition(classlist, p, r);
    print_classlist(classlist);

    qsort_recurse(classlist, p, q-1);
    qsort_recurse(classlist, q+1, r);
    return;
}

int Scheduler::qsort_partition(std::vector<Course> &classlist, int p, int r) {
    int pivot = r;
    int pivot_end_val = classlist[r].end;

    int i = p-1;
    int j = p;

    //sort into partitions
    while (j < r) {
        if (classlist[j].end <= pivot_end_val) {
            std::iter_swap(classlist.begin()+j, classlist.begin()+i+1);      
            i++;
        }
        j++;
    }

    //put pivot in correct location
    std::iter_swap(classlist.begin()+i+1, classlist.begin()+r);
    return i+1;
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