#pragma once
#include "Jedi.h"
#include "Vector.h"
#include <iostream>
#include <cstring>
#include <fstream>

class Planet {
private:
   char* planet_name;
   Vector<Jedi> jedis;

   void copy(const Planet& other);
   void erase();

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
   friend std::istream& operator>>(std::istream& in, Planet& other);
   
};
