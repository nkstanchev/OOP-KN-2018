#pragma once
#include <iostream>
#include <cstring>
enum Genre {
    POP, RAP, POPFOLK
};

class Song {
    char *name;
    float durationInMinutes;
    Genre genre;
    void copy(const Song&);
    void erase();
public:
    Song();
    Song(char *,Genre,float);
    Song(const Song&);
    Song& operator =(const Song&);
    ~Song();
    friend std::ostream& operator <<(std::ostream& os, const Song& song);
};