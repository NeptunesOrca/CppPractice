//#include "course.hpp"
class Course {
    public:
    int start;
    int end;
    Course(int start_time, int end_time){
        start = start_time;
        end = end_time;
    };
};

class Scheduler {
    std::vector<Course> available_classlist;
    std::mt19937 rng;

    void Scheduler::print_classlist(std::vector<Course> &classlist);
    void Scheduler::trim_classlist(std::vector<Course> &classlist, int start, int end);
    void Scheduler::quicksort(std::vector<Course> &classlist);
    void Scheduler::shuffle(std::vector<Course> &classlist);
    int Scheduler::get_random_num(int max, int min);
    void Scheduler::print_course(Course c1);

    public:
    Scheduler(std::vector<Course> const &classes);

    int maxClasses(int start_time, int end_time);
};