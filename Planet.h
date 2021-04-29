#pragma once
#include <iostream>
#include "Jedi.h"

class Planet {
private:
   Jedi* jedi;
   char* planet_name;

public:
   Planet();
   Planet(const Planet& other_planet);
   Planet& operator=(const Planet& other_planet);
   ~Planet();

};