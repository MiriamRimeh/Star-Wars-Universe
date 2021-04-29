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

   void print(const char* jedi_name) const;

   /*
    * TODO:
    * print(jedi_name)
    * create_jedi(planet_name, jedi_name, jedi_rank, jedi_age, saber_color, jedi_strenght)
    * promote_jedi(jedi_name, multiplier)
    * demote_jedi(jedi_name, multiplier)
    * get_strongest_jedi(planet_name) -> class Planet(?)
    * get_most_used_saber_color(planet_name, jedi_rank) -> class Planet(?)
    * get_youngest_jedi(planet_name, jedi_rank)
   */
   
};