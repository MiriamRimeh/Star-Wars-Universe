#pragma once
#include "Jedi.h"
#include "Vector.h"
#include <iostream>
#include <cstring>
#include <ostream>
#include <istream>

class Planet {
private:
   char* planet_name;
   Vector<Jedi> citizens;

public:
   Planet();
   Planet(const Planet& other);
   Planet& operator=(const Planet& other);
   ~Planet();

   //you can implement the interface of the main menu with operator <<
   friend std::ostream& operator<<(std::ostream& out, const Planet& other);
   friend std::istream& operator>>(std::istream& in, Planet& other);
};
