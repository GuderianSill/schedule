#include "location.h"

void Campus::addBuilding(unique_ptr<Building> building)
{
    //buildings.push_back(std::move(building));
    if (buildings[building->getName()])
        std::cout << "have this building" << std::endl;
    else
        buildings[building->getName()] = std::move(building);
}

//const vector<unique_ptr<Building>>& Campus::getBuildings()
//{ return buildings; }

void Campus::printAllBuildings() const
{
    cout << getName() << " ";
    std::cout << "have " << buildings.size() << "buildings" << std::endl;
    for (const auto& i : buildings)
        std::cout << i.first << " ";
}

void Building::addClassroom(unique_ptr<Classroom> classroom)
{
    if (classrooms[classroom->getName()])
        cout << "exsit this classroom" << endl;
    else
        classrooms[classroom->getName()] = std::move(classroom);
}

void Building::printAllClassrooms() const
{
    cout << getName() << " ";
    std::cout << "have " << classrooms.size() << "classrooms" << std::endl;
    for (const auto& i : classrooms)
        std::cout << i.first << " ";
}

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
