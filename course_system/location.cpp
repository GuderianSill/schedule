#include "location.h"

void Campus::addBuilding(unique_ptr<Building> building)
{
    buildings.push_back(std::move(building));
}

const vector<unique_ptr<Building>>& Campus::getBuildings()
{ return buildings; }

void Building::addClassroom(unique_ptr<Classroom> classroom)
{
    classrooms.push_back(std::move(classroom));
}

const std::vector<unique_ptr<Classroom>>& Building::getClassrooms() const
{ return classrooms; }

Campus* Building::getCampus() const
{ return campus; }

int Classroom::getCapacity() const
{ return capacity; }

Building* Classroom::getBuilding() const
{ return building; }

void Classroom::printDetails() const
{
    std::cout << "Classroom: " << getName() << ", Capacity: " << capacity
              << ", Building: " << building->getName()
              << ", Campus: " << building->getCampus()->getName() << std::endl;
}
