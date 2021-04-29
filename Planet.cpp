#include "Planet.h"

Planet::Planet() {
   this->jedi = nullptr;

   this->planet_name = new char[1];
   this->planet_name[0] = '\n';
}

Planet::Planet(const Planet& other_planet) {
   this->jedi = other_planet.jedi;

   this->planet_name = new char[strlen(other_planet.planet_name) + 1];
   strcpy(this->planet_name, other_planet.planet_name);
}

Planet& Planet::operator=(const Planet& other_planet) {
   if (this != &other_planet) {
      delete[] this->planet_name;

      this->planet_name = other_planet.planet_name;
      this->jedi = other_planet.jedi;
   }

   return *this;
}

Planet::~Planet() {
   delete[] this->planet_name;
}