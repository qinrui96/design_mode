#pragma once
#include<iostream>
#include "shoes.h"

class Nikeshoes: public Shoes{
public:
    Nikeshoes() = default;
    void show() { std::cout << "nike shoe" << std::endl; }
};