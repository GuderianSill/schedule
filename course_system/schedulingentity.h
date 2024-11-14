#ifndef SCHEDULINGENTITY_H
#define SCHEDULINGENTITY_H
#include "location.h"
using std::pair;

class Course;
class Schedule;

class School_SchedulingEntity
{
protected:
    int id;
    string name;
public:
    School_SchedulingEntity(int id, string name) : id(id), name(name) {}
    virtual ~School_SchedulingEntity() = default;
    string getName() const { return name; };
};

class Teacher : public School_SchedulingEntity
{
private:
    vector<pair<int, int>> busy_time;
    vector<unique_ptr<Course>> course;
public:
    Teacher(int id, string name) : School_SchedulingEntity(id, std::move(name)) {}
    Teacher(int id, string name, vector<pair<int, int>>& busy_time) : School_SchedulingEntity(id, std::move(name)), busy_time(busy_time) {}

};

// 课程类
class Course : public School_SchedulingEntity
{
private:
    int credits;
    int need_time;
    int students_num;
    Teacher* teacher; // 指向老师的指针
    Schedule* schedule;
public:
    Course(int id, string name, int need_time, int credits, int students_num = NULL, Teacher* teacher = nullptr,
            Schedule* schedule = nullptr) : School_SchedulingEntity(id, std::move(name)), credits(credits),
        need_time(need_time), students_num(students_num), teacher(teacher), schedule(schedule) {}

    bool has_teacher() const { return teacher; }

    string getTeacherName() const;

};

// 课程安排类
class Schedule
{
private:
    Course* course; // 指向课程的指针
    Classroom* classroom; // 指向教室的指针
    //上课时间安排，周和课次
    vector<pair<int, int>> timeSlot;
public:
    Schedule(Course* course, Classroom* classroom, vector<pair<int, int>> timeSlot)
        : course(course), classroom(classroom), timeSlot(std::move(timeSlot)) {}

    void printSchedule() const;
};

#endif // SCHEDULINGENTITY_H
