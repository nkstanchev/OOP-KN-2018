#include "FmiStudent.h"

FmiStudent::FmiStudent() {
    firstName = new char[1];
    strcpy(firstName, "");
    lastName = new char[1];
    strcpy(lastName, "");
    birthTown = new char[1];
    strcpy(birthTown, "");
    age = 0;
    facultyNum = 0;
}
void FmiStudent::copy(const FmiStudent& other) {
    firstName = new char[strlen(other.firstName)];
    strcpy(firstName, other.firstName);
    lastName = new char[strlen(other.firstName)];
    strcpy(lastName, other.lastName);
    birthTown = new char[strlen(other.firstName)];
    strcpy(birthTown, other.birthTown);
    age = other.age;
    facultyNum = other.facultyNum;
}
void FmiStudent::erase() {
    delete[] firstName;
    delete[] lastName;
    delete[] birthTown;
}
FmiStudent::FmiStudent(const FmiStudent& other) {
    copy(other);
}
FmiStudent& FmiStudent::operator=(const FmiStudent& other) {
    if (this != &other) {
        erase();
        copy(other);
    }
    return *this;
}
FmiStudent::~FmiStudent() {
    erase();
}
char * FmiStudent::getFirstName() {
    return firstName;
}
void FmiStudent::setFirstName(char*) {
    delete[] this->firstName;
    this->firstName = new char[strlen(firstName)];
    strcpy(this->firstName, firstName);
}
char * FmiStudent::getLastName() {
    return lastName;
}
void FmiStudent::setLastName(char* lastName) {
    delete[] this->lastName;
    this->lastName = new char[strlen(lastName)];
    strcpy(this->lastName, lastName);
}
int FmiStudent::getAge() {
    return age;
}
void FmiStudent::setAge(int age) {
    if (age > 0) {
        this->age = age;
    }
}
int FmiStudent::getFacultyNum() {
    return facultyNum;
}
void FmiStudent::setFacultyNum(int facultyNum) {
    if (facultyNum > 0) {
        this->facultyNum = facultyNum;
    }
}