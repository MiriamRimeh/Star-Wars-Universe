#pragma once
#include "Jedi.h"
#include "Planet.h"
#include <iostream>
/* #include <ostream>
#include <istream> */
#include <cstring>
#include <fstream>

//think about types!
//should I write Planet planet_name or const char* planet_name?
void add_planet(const char* planet_name); //should it be Planet* or Planet& ?
void create_jedi(const char* planet_name, const char* jedi_name, Rank jedi_rank, int jedi_age, const char* saber_colour, double jedi_strength);
//void remove_jedi(const char* jedi_name, const char* planet_name);
//void promote_jedi(const char* jedi_name, double multiplier);
//void demote_jedi(const char* jedi_name, double multiplier);
//void get_strongest_jedi(const char* planet_name);
//void get_youngest_jedi(const char* planet_name, Rank jedi_rank);
//void get_most_used_saber_colour(const char* planet_name, Rank jedi_rank);
//void get_most_used_saber_colour(Planet planet_name);
//void print(Planet planet_name);
//void print(Jedi jedi_name);

//here all the funcitons will be potentially written