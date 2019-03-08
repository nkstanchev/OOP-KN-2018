#include "Movie.h"
/*
NB!: strlen, strcpy са дефинирани чрез #include <cstring>
NB!: За хората с Visual Studio, в зависимост от настройките на компилатора
     може да се наложи да ползвате strcpy_s вижте повече за него в интернет
*/

Movie::Movie() {
    /* NB!:  Възможно е да се инициализират и с nullptr
             например name = nullptr;
             Тогава обаче при всяко извикване на delete трябва да проверяваме
             затова е по-лесно така 
     */
    name = new char[1];
    strcpy(name, "");
    director = new char[1];
    strcpy(name, "");
    durationInHours = 0;
}
Movie::Movie(char *name, char *director, float durationInHours) {
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->director = new char[strlen(director)];
    strcpy(this->director, director);
    this->durationInHours = durationInHours;

}
void Movie::copy(const Movie& other) {
    
    name = new char[strlen(other.name)]; // Заделяме динамична памет
    strcpy(name, other.name); // Копираме съдържанието на единия char* в другия
    director = new char[strlen(other.director)];
    strcpy(name, other.director);
    durationInHours = other.durationInHours;
}
void Movie::erase() {
    /* Изтриваме само динамично задалената памет */
    delete[] name; // [] защото е указател, ако беше само char => delete name;
    delete[] director;
}
Movie::Movie(const Movie& other) {
    copy(other);
}
Movie& Movie::operator =(const Movie& other) {
    if (this != &other) {
        erase();
        copy(other);
    }
    return *this; // позволява навързване(chaining) от вида на a = b = c
}
Movie::~Movie() {
    erase();
}
/*  Забележете, че пред името на функцията няма Movie:: защото тя е 
    приятелска фунцкия, но не и част от класа
*/
std::ostream& operator <<(std::ostream& os, const Movie& movie) {
    os << movie.name << std::endl;
    os << movie.director << std::endl;
    os << movie.durationInHours << std::endl;
    return os;
}