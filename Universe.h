#pragma once
#include "Jedi.h"
#include "Planet.h"
#include <iostream>
#include <fstream>
#include <cstring>

class Universe {
private:
   char* path;

   void copy(const Universe& other);
   void erase();

public:
   Universe();
   Universe(const Universe& other);
   Universe& operator=(const Universe& other);
   ~Universe();

   bool can_change_rank() const;

   void add_planet(const char* planet_name);
   void create_jedi(const char* planet_name, const char* jedi_name, Rank rank, int age, const char* saber_colour, double strength); 
   void remove_jedi(const char* jedi_name, const char* planet_name);    
   void promote_jedi(const char* jedi_name, double multiplier);   
   void demote_jedi(const char* jedi_name, double multplier); //<jedi_name> <multiplier>   
   void get_strongest_jedi(const char* planet_name) const; //<planet_name>
   void get_youngest_jedi(const char* planet_name, Rank jedi_rank); //<planet_name> <jedi_rank>
   void get_most_used_saber_colour(const char* planet_name, Rank rank); //<planet_name> <jedi_rank>
   void get_most_used_saber_colour(const char* planet_name); //<planet_name>
   void print(const char* planet); //<planet_name>
   void print(const char* jedi_name); //<jedi_name>
   //planet + planet

   friend std::ostream& operator<<(std::ostream& out, const Universe& other);
   friend std::istream& operator>>(std::istream& in, Universe& other);
};