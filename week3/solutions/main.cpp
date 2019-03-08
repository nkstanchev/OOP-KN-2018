#include <iostream>
#include "Movie.h"
#include "Song.h"
int main()
{
    Movie m("2 Fast 2 Furious", "nz", 1.5);
    std::cout << m;
    Song s("Cry me a river", POP, 3.5);
    std::cout << s;
    return 0;
}