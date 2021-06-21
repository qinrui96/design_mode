#pragma once

template <typename T>
class Singleton{
public:
    Singleton& operator=(const Singleton& item) = delete;
    Singleton& operator=(Singleton&& item) = delete;
    Singleton(const Singleton& item) = delete;
    Singleton(Singleton&& item) = delete;

    static T& GetInstance()
    {
        static T instance;
        return instance;
    }
protected:
    Singleton();
};