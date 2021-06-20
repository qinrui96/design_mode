#pragma once
#include "logo.h"
#include "Nikeshoes.h"

class Nike:public Logo{
public:
    Nike() = default;
    Shoes* creator() { return new Nikeshoes(); }
};