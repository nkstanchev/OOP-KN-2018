#pragma once
#include <iostream>
#include <cstring>
class FmiStudent {
    char * firstName, * lastName, * birthTown;
    int age, facultyNum;
    void erase();
    void copy(const FmiStudent&);
public:
    FmiStudent();
    FmiStudent(const FmiStudent& other);
    FmiStudent& operator=(const FmiStudent& other);
    ~FmiStudent();
    char * getFirstName();
    void setFirstName(char*);
    char * getLastName();
    void setLastName(char*);
    int getAge();
    void setAge(int);
    int getFacultyNum();
    void setFacultyNum(int);
};