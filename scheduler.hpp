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

    void Scheduler::print_classlist(std::vector<Course> &classlist);
    void Scheduler::trim_classlist(std::vector<Course> &classlist, int start, int end);

    public:
    Scheduler();
    Scheduler(std::vector<Course> const &classes);

    int maxClasses(int start_time, int end_time);
};