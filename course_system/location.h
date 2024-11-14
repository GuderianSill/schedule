#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
using std::string;
using std::vector;
using std::unique_ptr;

class Building;
class Classroom;

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
    vector<unique_ptr<Building>> buildings;
public:
    Campus(int id, string name): Location(id, std::move(name)) {}
    void addBuilding(unique_ptr<Building>);
    const vector<unique_ptr<Building>>& getBuildings();
};

//教学楼
class Building : public Location
{
private:
    vector<unique_ptr<Classroom>> classrooms;
    Campus* campus;
public:
    Building(int id, string name, Campus* campus): Location(id, std::move(name)), campus(campus){}

    void addClassroom(unique_ptr<Classroom> classroom);

    const vector<unique_ptr<Classroom>>& getClassrooms() const;
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
