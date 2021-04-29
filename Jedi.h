#pragma once
#include <iostream>
#include <cstring>

enum Rank {
   YOUNGLING, INITIATE, PADAWAN, KNIGHT_ASPIRANT, KNIGHT, MASTER, BATTLE_MASTER, GRAND_MASTER
};

class Jedi {
private:
   char* jedi_name;
   Rank jedi_rank;
   int jedi_age;
   char* saber_color;
   double jedi_strenght;

public:
   Jedi();
   //add constructor with parameteres
   Jedi(const Jedi& other_jedi);
   Jedi& operator=(const Jedi& other_jedi);
   ~Jedi();

   void promote_jedi(const char* jedi_name, double multiplier);
   void demote_jedi(const char* jedi_name, double multiplier);

   /*
    * TODO:
    * get_strongest_jedi(planet_name) -> class Planet(?)
    * get_most_used_saber_color(planet_name, jedi_rank) -> class Planet(?)
    * get_youngest_jedi(planet_name, jedi_rank)
   */
   
};