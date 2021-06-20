#include"body.h"

void MyFunc(Body *b)
{
    b->show();
}

int main()
{
    Body* p = new Body();
    Body* p1 = new Decorator1(p);
    Body* p2 = new Decorator2(p1);
    MyFunc(p2);
}