#ifndef PERSON_H
#define PERSON_H

#include <string>

#include "Printable.h"
#include "StrongType.h"
#include "Swappable.h"

using Surname =
    StrongType<std::string, struct SurnameTag, Printable, Swappable>;

#endif