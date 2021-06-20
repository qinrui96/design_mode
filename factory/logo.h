#pragma once
#include "shoes.h"

class Logo{
public:
    Logo() = default;
    virtual Shoes* creator() = 0;
};