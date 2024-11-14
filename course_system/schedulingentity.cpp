#include "schedulingentity.h"


string Course::getTeacherName() const
{
    if (!has_teacher())
        return "No teacher";
    return this->teacher->getName();
}
