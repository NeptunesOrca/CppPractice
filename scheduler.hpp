#include "course.hpp"

class Scheduler {
    std::vector<Course> available_classlist;

    public:
    Scheduler(std::vector<Course> const &classes);

    int maxClasses(int start_time, int end_time);
};