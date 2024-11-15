#ifndef TOTAL_H
#define TOTAL_H
#include "location.h"
#include "schedulingentity.h"

class School
{
private:
    string name;
    map<string, Campus*> campuses;
public:
    School(string name = "henu") : name(name) {}
    ~School();
    void addCampus(Campus*);
};

#endif // TOTAL_H
