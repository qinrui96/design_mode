#include<iostream>
#include "component.h"
int main()
{
    Component *item1 = new Leaf;
    Component *tree = new Composit;
    Component *branch = new Composit;

    Component *item3 = new Leaf;
    Component *item2 = new Leaf;
    branch->add(item2);
    branch->add(item3);
    tree->add(item1);
    tree->add(branch);
    (*tree)();
    delete item1;
    delete tree;
    delete branch;
}