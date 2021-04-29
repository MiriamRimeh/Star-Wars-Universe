#pragma once
#include <iostream>
#include "Jedi.h"

class Planet {
private:
   Jedi* jedi; //fix -> should it be Jedi jedi or Jedi* jedi? maybe Jedi jedi
   char* planet_name;

public:
   Planet();
   Planet(const Planet& other_planet);
   Planet& operator=(const Planet& other_planet);
   ~Planet();

   void add_planet(const char* planet_name); //opens file with planets and enters the name of the planet
   void create_jedi(const char* planet_name, const Jedi& jedi_name, const Jedi& jedi_rank, const Jedi& jedi_age, const Jedi& saber_color, const Jedi& jedi_strenght);
   void remove_jedi(const char* planet_name, const Jedi& jedi_name);
   Jedi& get_youngest_jedi(const char* planet_name, const Jedi& jedi_rank);
   Jedi& get_strongest_jedi(const char* planet_name);
   Jedi& get_most_used_saber_color(const char* planet_name, const Jedi& jedi_rank);
   Jedi& get_most_used_saber_color(const char* planet_name);
   void print(const char* planet_name) const;
   void print(const char* jedi_name) const;

   //implement functions and test them, make sure the types of the functions are correct

};