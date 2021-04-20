#pragma once
#include <iostream>
#include "Jedi.h"

class Planet {
private:
   char* planet_name;
   Jedi jedi;

   void copy(const Planet& other_planet);
   void erase();
   
public:
   Planet();
   Planet(const Planet& other_planet);
   Planet& operator=(const Planet& other_planet);
   ~Planet();

   //setters
   void set_planet_name(const char* other_planet);
   void set_jedi(const Jedi other_jedi);

   //getters
   char* get_planet_name();
   Jedi get_jedi();

};