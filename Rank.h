#pragma once
#include <iostream>
#include <ostream>
#include <istream>

enum class Rank {
   YOUNGLING = 0, INITIATE, PADAWAN, KNIGHT_ASPIRANT, KNIGHT, MASTER, BATTLE_MASTER, GRAND_MASTER
};

std::ostream& operator<<(std::ostream& out, const Rank& other) {
   out << "Rank: " << other << std::endl;
   return out;
}

std::istream& operator>>(std::istream& in, Rank& other) {
   std::cout << "Rank: ";
   in >> other;

   return in;
}

