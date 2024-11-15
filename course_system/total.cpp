#include "total.h"

School::~School()
{
    for (auto& i : campuses)
    {
        delete i.second;
        i.second = nullptr;
    }
}

void School::addCampus(Campus *campus)
{
    if (campuses[campus->getName()])
        cout << "exist" << endl;
    else
        campuses[campus->getName()] = campus;
}
