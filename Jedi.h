#pragma once
#include "Planet.h"

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
   Planet planet;

   void copy(const Jedi& other_jedi);
   void erase();

public:
   Jedi();
   //add constructor with parameteres
   Jedi(const Jedi& other_jedi);
   Jedi& operator=(const Jedi& other_jedi);
   ~Jedi();

   //setters
   void set_jedi_name(const char* other_name);
   void set_rank(const Rank other_rank);
   void set_age(const int other_age);
   void set_saber_color(const char* other_saber_color);
   void set_strenght(const double other_strenght);
   void set_planet(const Planet other_planet);

   //getters
   char* get_jedi_name();
   Rank get_rank();
   int get_age();
   char* get_saber_color();
   double get_strenght();
   Planet get_planet();

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