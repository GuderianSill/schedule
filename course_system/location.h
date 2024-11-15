#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <map>
//#include "total.h"
using std::string;
using std::vector;
using std::unique_ptr;
using std::map;
using std::cout;
using std::endl;

class Building;
class Classroom;
class School;

class Location
{
public:
    Location(int id, std::string name): id(id), name(name){}
    virtual ~Location() = default;

    int getId() const { return id; }
    std::string getName() const { return name; }
protected:
    int id;
    string name;
};

//校区
class Campus : public Location
{
private:
    //vector<unique_ptr<Building>> buildings;
    map<string, unique_ptr<Building>> buildings;
    School* school;
public:
    Campus(int id, string name, School* school): Location(id, std::move(name)), school(school) {}
    void addBuilding(unique_ptr<Building>);
    //const vector<unique_ptr<Building>>& getBuildings();
    void printAllBuildings() const;
};

//教学楼
class Building : public Location
{
private:
    //vector<unique_ptr<Classroom>> classrooms;
    map<string, unique_ptr<Classroom>> classrooms;
    Campus* campus;
public:
    Building(int id, string name, Campus* campus): Location(id, std::move(name)), campus(campus) {}

    void addClassroom(unique_ptr<Classroom> classroom);

    //const vector<unique_ptr<Classroom>>& getClassrooms() const;
    void printAllClassrooms() const;
    Campus* getCampus() const;
};

class Classroom : public Location
{
private:
    int capacity;
    Building* building; // 指向教学楼的指针
public:
    Classroom(int id, string name, int capacity, Building* building)
        : Location(id, std::move(name)), capacity(capacity), building(building) {}

    int getCapacity() const;

    Building* getBuilding() const;

    void printDetails() const;
};


#endif // LOCATION_H
