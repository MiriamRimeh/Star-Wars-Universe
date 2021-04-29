#include "Planet.h"

Planet::Planet() {
   this->jedi = nullptr;

   this->planet_name = new char[1];
   this->planet_name[0] = '\n';
}

Planet::Planet(const Planet& other_planet) {
   this->jedi = new Jedi[strlen(other_planet.jedi) + 1];
   strcpy
}