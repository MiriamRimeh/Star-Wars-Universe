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
   Vector<Jedi> jedis;

public:
   Planet();
   Planet(const Planet& other);
   Planet& operator=(const Planet& other);
   ~Planet();

   const char* get_planet_name() const;
   void set_planet_name(const char* name);

   const Vector<Jedi>& get_jedis() const;
   void set_jedis(const Vector<Jedi>& other);

   
   friend std::ostream& operator<<(std::ostream& out, const Planet& other);
   friend std::istream& operator>>(std::istream& in, const Planet& other);
   
};
