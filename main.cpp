#include "Vector.h"
#include "Planet.h"
#include "Jedi.h"
#include "Program.cpp"


int main () {

  std::cout << "*** Welcome to Star Wars Universe! ***" << std::endl
            << std::endl; 

  
  Program program;
  //program.help();
  //program.add_planet("Mars");
  program.create_jedi("Jupiter", "Joey", YOUNGLING, 20, "green", 89.9);

  //use a switch case for the commands(?)
  //if user tries to input an invalid command print an error message

   return 0;
  
}