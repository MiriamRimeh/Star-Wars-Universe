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

   //insert getters and setters if needed if not delete them and think of a way to avoid them
   const char* get_name() const;
   Rank& get_rank();
   int get_age();
   const char* get_colour() const;
   double get_strength();

   void set_name(char* name);
   void set_rank(Rank rank);
   void set_age(int age);
   void set_colour(char* colour);
   void set_strength(double strength);

   //operators >> and <<
   friend std::ostream& operator<<(std::ostream& out, const Jedi& other);

   //might not need >>
   friend std::istream& operator>>(std::istream& in, Jedi& other);

};