#pragma once
#include "Rank.h"
#include <iostream>
#include <ostream>
#include <istream>
#include <cstring>


class Jedi {
private:
   char* jedi_name;
   Rank rank;
   int age;
   char* saber_colour;
   double strength;

public:
   Jedi();
   Jedi(const Jedi& other);
   Jedi& operator=(const Jedi& other);
   ~Jedi();

   void print() const;

   Jedi& operator<(Jedi& other);

   //insert getters and setters if needed

   //operators >> and <<
   friend std::ostream& operator<<(std::ostream& out, const Jedi& other);

   //might not need >>
   friend std::istream& operator>>(std::istream& in, Jedi& other);

};