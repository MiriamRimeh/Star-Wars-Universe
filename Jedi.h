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

   void copy(const Jedi& other);
   void erase();
   
public:
   Jedi();
   Jedi(const char* name, Rank rank, int age, const char* saber_colour, double strength);
   Jedi(const Jedi& other);
   Jedi& operator=(const Jedi& other);
   ~Jedi();

  // void print() const;

   const char* get_name() const;
   Rank& get_rank();
   int get_age();
   const char* get_colour() const;
   double get_strength();

   void set_name(const char* name);
   void set_rank(Rank rank);
   void set_age(int age);
   void set_colour(const char* colour);
   void set_strength(double strength);

   friend std::ostream& operator<<(std::ostream& out, const Jedi& other);
   //TODO: operator>>

};