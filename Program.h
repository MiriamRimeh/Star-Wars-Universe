#pragma once
#include "Jedi.h"
#include "Planet.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <ostream>
#include <istream>

class Program {
private:
   char* path;

public:
   Program();
   Program(const Program& other);
   Program& operator=(const Program& other);
   ~Program();

//comments represent the arguments of the functions; arguments will be added while implementing the functions
   void open(char* path); //<path>
   void close();
   void save();
   void saveas(); //<path>
   void help();
   
   bool can_change_rank();

   void add_planet(const char* planet_name);
   void create_jedi(const char* planet_name, const char* jedi_name, Rank rank, int age, const char* saber_colour, double strength); 
   void remove_jedi(const char* jedi_name, const char* planet_name);    
   void promote_jedi(const char* jedi_name, double multiplier);   
   void demote_jedi(); //<jedi_name> <multiplier>   
   void get_strongest_jedi(); //<planet_name>
   void get_youngest_jedi(); //<planet_name> <jedi_rank>
   void get_most_used_saber_colour(char* planet_name); //<planet_name> <jedi_rank>
   void get_most_used_saber_colour(); //<planet_name>
   void print(char* planet); //<planet_name>
   void print(); //<jedi_name>
   //planet + planet

   friend std::ostream& operator<<(std::ostream& out, const Program& other);
   friend std::istream& operator>>(std::istream& in, const Program& other);
};