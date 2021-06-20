#pragma once
#include<iostream>
#include<string>
#include<vector>
class Component{
public:
    Component() = default;
    virtual void add(Component* item) {};
    virtual void remove() {};
    Component* GetParent() { return parent_; }
    void SetParent(Component * father) { parent_ = father; }
    virtual void operator() ()= 0;
    virtual ~Component() {}
protected:
    Component* parent_;
};

class Leaf : public Component{
public:
    Leaf() =  default;
    void operator() () { std::cout << "leaf "; }
};

class Composit:public Component{
private:
    std::vector<Component* > member;
public:
    void add(Component* item) { member.push_back(item); item->SetParent(this); }
    void remove() { auto item = member.back(); member.pop_back(); item->SetParent(nullptr); }
    void operator() ();
    ~Composit() { }
};

