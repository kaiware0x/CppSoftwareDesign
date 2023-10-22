#ifndef DISTANCES_H
#define DISTANCES_H

#include "Addable.h"
#include "Printable.h"
#include "StrongType.h"
#include "Swappable.h"

template <typename T>
using Meter = StrongType<T, struct MeterTag, Addable, Printable, Swappable>;

template <typename T>
using KiloMeter =
    StrongType<T, struct KiloMeterTag, Addable, Printable, Swappable>;

#endif