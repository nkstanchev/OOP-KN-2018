#include "Song.h"
/*
NB!: strlen, strcpy са дефинирани чрез #include <cstring>
NB!: За хората с Visual Studio, в зависимост от настройките на компилатора
     може да се наложи да ползвате strcpy_s вижте повече за него в интернет
*/

Song::Song() {
    /* NB!:  Възможно е да се инициализират и с nullptr
             например name = nullptr;
             Тогава обаче при всяко извикване на delete трябва да проверяваме
             затова е по-лесно така 
     */
    name = new char[1];
    strcpy(name, "");
    genre = POP;
    durationInMinutes = 0;
}
Song::Song(char *name, Genre genre, float durationInMinutes) {
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->genre = genre;
    this->durationInMinutes = durationInMinutes;

}
void Song::copy(const Song& other) {
    
    name = new char[strlen(other.name)]; // Заделяме динамична памет
    strcpy(name, other.name); // Копираме съдържанието на единия char* в другия
    durationInMinutes = other.durationInMinutes;
    genre = other.genre;
}
void Song::erase() {
    /* Изтриваме само динамично задалената памет */
    delete[] name; // [] защото е указател, ако беше само char => delete name;
}
Song::Song(const Song& other) {
    copy(other);
}
Song& Song::operator =(const Song& other) {
    if (this != &other) {
        erase();
        copy(other);
    }
    return *this; // позволява навързване(chaining) от вида на a = b = c
}
Song::~Song() {
    erase();
}
std::ostream& operator <<(std::ostream& os, const Song& song) {
    os << song.name << std::endl;
    os << song.genre << std::endl;
    os << song.durationInMinutes << std::endl;
    return os;
}
std::istream& operator>>(istream& is, Song& song) {
    delete[] song.name;
    delete[] song.artist;

    char* buffer = new char[SIZE];

    is.getline(buffer, SIZE);
    song.artist = new char[strlen(buffer) + 1];
    strcpy(song.artist, buffer);

    is.getline(buffer, SIZE);
    song.name = new char[strlen(buffer) + 1];
    strcpy(song.name, buffer);

    is >> song.duration;
    is.ignore();

    is.getline(buffer, SIZE);
    song.genre = new char[strlen(buffer) + 1];
    strcpy(song.genre, buffer);

    delete[] buffer;
    return is;
}
