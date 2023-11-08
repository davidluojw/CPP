#pragma once
#include <iostream>

class MyTime
{
    int hours;
    int minutes;
  public:
    MyTime(): hours(0), minutes(0)
    {
        std::cout << "Constructor MyTime()" << std::endl;
    }
    MyTime(int m): hours(0), minutes(m)
    {
        std::cout << "Constructor MyTime(int)" << std::endl;
        this->hours +=  this->minutes / 60;
        this->minutes %= 60;
    }
    MyTime(int h, int m): hours(h), minutes(m)
    {
        std::cout << "Constructor MyTime(int,int)" << std::endl;
    }

    // prefix increment
    MyTime& operator++()
    {
        std::cout << "operator prefix increment" << std::endl;
        this->minutes++;
        this->hours += this->minutes / 60;
        this->minutes = this->minutes % 60;
        return *this; 
    }
 
    // postfix increment
    MyTime operator++(int)
    {
        std::cout << "operator postfix increment" << std::endl;
        MyTime old = *this; // keep the old value
        operator++();  // prefix increment
        return old; 
    }

    friend std::ostream & operator<<(std::ostream & os, const MyTime & t)
    {
        std::string str = std::to_string(t.hours) + " hours and " 
                        + std::to_string(t.minutes) + " minutes.";
        os << str;
        return os;
    }
};
