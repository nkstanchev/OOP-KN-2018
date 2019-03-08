#pragma once
#include <iostream>
#include <cstring>
/*
Задача 1

Да се направи клас Филм, който в себе си има полетата име, режисьор и продължителноста на филма. За този клас трябва да се реализират:

    конструктор по подразбиране
    конструктор с параметри
    деструктор
    оператор за присвояване
    оператора за вход
    оператор за изход

*/
class Movie {
    char *name;
    char *director;
    float durationInHours;
    void copy(const Movie&);
    void erase();
public:
    Movie();
    Movie(char *,char *,float);
    Movie(const Movie&);
    Movie& operator =(const Movie&);
    ~Movie();
    friend std::ostream& operator <<(std::ostream&,const Movie&);
};
