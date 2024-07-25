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

    public:
    Scheduler(std::vector<Course> const &classes);

    int maxClasses(int start_time, int end_time);
};