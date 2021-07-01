/**
 * @file Observe.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<iostream>
#include<memory>
#include<vector>

class Observable;

class Observer: public std::enable_shared_from_this<Observer>{
public:
    virtual ~Observer();
    virtual void update() = 0;

    void observe(Observable* s);
protected:
    Observable *subject_;
};

class Observable{
public:
    void Register(std::weak_ptr<Observer> x);

    void Notify()
    {
        Iterator it = my_list.begin();
        while(it != my_list.end())
        {
            std::shared_ptr<Observer> obj(it->lock());
            if(obj)
            {
                obj->update();
                ++it;
            }
            else
            {
                std::cout << "Notify Observe erase\n";
                it = my_list.erase(it);
            }
        }
    }
private:
    std::vector<std::weak_ptr<Observer>> my_list;
    using Iterator = std::vector<std::weak_ptr<Observer>>::iterator;
};

Observer::~Observer()
{

}

void Observer::observe(Observable* s)
{
    s->Register(shared_from_this());
    subject_ = s;
}

void Observable::Register(std::weak_ptr<Observer> x)
{
    my_list.push_back(x);
}

class Foo:public Observer
{
    void update()
    {
        std::cout << "Foo::update\n";
    }
};

int main()
{
    Observable subject;
    {
        std::shared_ptr<Foo> p(new Foo);
        p->observe(&subject);
        subject.Notify();
    }
    subject.Notify();
}
