#pragma once
#include<iostream>
class Body{
public:
    Body() = default;
    virtual void show() { std::cout << "裸体\n"; }
};

class Decorator:public Body{
protected:
    Body *body;
public:
    Decorator(Body* b):body(b) {}
    virtual void show() { body->show(); }
};


class Decorator1:public Decorator{
public:
    Decorator1(Body* b):Decorator(b) {}
    void show() { std::cout << "半袖\n"; body->show(); }
};

class Decorator2:public Decorator{
public:
    Decorator2(Body* b):Decorator(b) {}
    void show() { std::cout << "长袖\n"; body->show(); }
};