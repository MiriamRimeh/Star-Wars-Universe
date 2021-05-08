#pragma once
#include "Jedi.cpp"
#include "Vector.h"
#include <iostream>
#include <cstring>
#include <ostream>
#include <istream>
#include <fstream>

class Planet {
private:
   char* planet_name;
   Vector<Jedi> citizens;

public:
   Planet();
   Planet(const Planet& other);
   Planet& operator=(const Planet& other);
   ~Planet();

   void add_planet(const char* planet_name); //works good
   void create_jedi(const char* planet_name, const char* jedi_name, Rank jedi_rank, int jedi_age, const char* saber_colour, double jedi_strength); //works good
   void remove_jedi(const char* jedi_name, const char* planet_name);

   //you can implement the interface of the main menu with operator <<
   friend std::ostream& operator<<(std::ostream& out, const Planet& other);
   //friend std::istream& operator>>(std::istream& in, Planet& other);
};
