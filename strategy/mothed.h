#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
class Strategy{
public:
    Strategy() = default;
    virtual void Do(std::vector<int> &arr) = 0;
};

class Context{
public:
    Context(std::vector<int> a):arr(a) {}
    void SetStrategy(Strategy *s) { delete my_strategy; my_strategy = s; }
    void DoStrategy() { my_strategy->Do(arr);}
private:
    Strategy *my_strategy = nullptr;
    std::vector<int> arr;
};

class Strategy1 : public Strategy{
public:
    Strategy1() = default;
    void Do(std::vector<int> &arr) { 
        std::cout << "从大到小\n";
        sort(arr.begin(), arr.end(), std::greater<int>());
        std::for_each(arr.begin(), arr.end(), [](const int &a){ std::cout << a << " "; }); 
        std::cout << std::endl;
    }
};


class Strategy2 : public Strategy{
public:
    Strategy2() = default;
    void Do(std::vector<int> &arr) {
        sort(arr.begin(), arr.end(), std::less<int>());
        std::cout << "从小到大\n"; 
        std::for_each(arr.begin(), arr.end(), [](const int &a){ std::cout << a << " "; });
        std::cout << std::endl;
    }
};