#pragma once
#include <iostream>
#include <ostream>
#include <istream>

enum Rank {
   YOUNGLING = 0, INITIATE, PADAWAN, KNIGHT_ASPIRANT, KNIGHT, MASTER, BATTLE_MASTER, GRAND_MASTER
};

//displays the ranks as a string instead of integers
std::ostream& operator<<(std::ostream& out, const Rank& other) {
   switch(other) {
      case YOUNGLING:
         out << "Youngling";
         break;
      case INITIATE:
         out << "Initiate";
         break;
      case PADAWAN:
         out << "Padawan";
         break;
      case KNIGHT_ASPIRANT:
         out << "Knight-Aspirant";
         break;
      case KNIGHT:
         out << "Knight";
         break;
      case MASTER:
         out << "Master";
         break;
      case BATTLE_MASTER:
         out << "Battle-Master";
         break;
      case GRAND_MASTER:
         out << "Grand-Master";
         break;
   }
   return out;
}

//checks if the user's input matches the possible entries
std::istream& operator>>(std::istream& in, Rank& other) {
   int value;

   if(in >> value) {
      switch(value) {
         case YOUNGLING:
         case INITIATE:
         case PADAWAN:
         case KNIGHT_ASPIRANT:
         case KNIGHT:
         case MASTER:
         case BATTLE_MASTER:
         case GRAND_MASTER:
            other = Rank(value);
            break;
         default:
            std::cout << "Invalid entry";
      }
   }
   return in;
}