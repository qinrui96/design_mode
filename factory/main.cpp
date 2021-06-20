#include<iostream>
#include<memory>
#include "logo.h"
#include "Nike.h"

int main()
{
    std::shared_ptr<Logo> mylogo = std::make_shared<Nike>();
    std::shared_ptr<Shoes> myshoe(mylogo->creator());
    myshoe->show();
}