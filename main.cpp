#include "Vector.h"
#include "Planet.h"
#include "Jedi.h"
#include "Universe.h"


int main () {

  std::cout << "*** Welcome to Star Wars Universe! ***" << std::endl
            << std::endl; 

  
  Universe universe;
  //program.help();
  //program.add_planet("Mars");
  //universe.create_jedi("Jupiter", "Joey", YOUNGLING, 20, "green", 89.9);
  universe.add_planet("Venus");

  //use a switch case for the commands(?)
  //if user tries to input an invalid command print an error message

   return 0;
  
}


#include "Jedi.cpp"
#include "Universe.cpp"