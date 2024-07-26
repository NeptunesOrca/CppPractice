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
    bool random_engine_is_seeded;

    void Scheduler::print_classlist(std::vector<Course> &classlist);
    void Scheduler::trim_classlist(std::vector<Course> &classlist, int start, int end);
    //bool Scheduler::compare_course_ends(Course c1, Course c2);
    void Scheduler::quicksort(std::vector<Course> &classlist);
    void Scheduler::shuffle(std::vector<Course> &classlist);
    int Scheduler::get_random_num(int max, int min);
    void Scheduler::swap_courses(Course c1, Course c2);
    void Scheduler::print_course(Course c1);

    public:
    Scheduler(std::vector<Course> const &classes);

    int maxClasses(int start_time, int end_time);
};