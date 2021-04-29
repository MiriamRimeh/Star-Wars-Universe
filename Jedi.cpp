#include "Jedi.h"


Jedi::Jedi () { // check if I need to put this-> in front of the variables
   this->jedi_name = new char[1];
   this->jedi_name[0] = '\n';
   this->jedi_rank = YOUNGLING; // default is YOUNGLING because when creating a jedi they should be the lowest rank possible unless stated otherwise
   this->jedi_age = 0;
   this->saber_color = new char[1];
   this->saber_color[0] = '\n';
   this->jedi_strenght = 0;
}

Jedi::Jedi(const Jedi& other_jedi) {
   this->jedi_name = new char(strlen[other.jedi_name] + 1);
   strcpy(this->jedi_name, other.jedi_name);

   this->jedi_rank = other.jedi_rank;

   this->jedi_age = other.jedi_age;

   this->saber_color = new char(strlen[other.saber_color] + 1);
   strcpy(this->saber_color, other.saber_color);

   this->jedi_strenght = other.jedi_strength;
}

Jedi& Jedi::operator=(const Jedi& other_jedi) {
   if(this != &other_jedi) {
      delete[] this->jedi_name;
      delete[] this->saber_color;

      this->jedi_name = new char(strlen[other.jedi_name] + 1);
      strcpy(this->jedi_name, other.jedi_name);

      this->jedi_rank = other.jedi_rank;

      this->jedi_age = other.jedi_age;

      this->saber_color = new char(strlen[other.saber_color] + 1);
      strcpy(this->saber_color, other.saber_color);

      this->jedi_strenght = other.jedi_strength;
   }

   return *this;
}

Jedi::~Jedi() {
   delete[] this->jedi_name;
   delete[] this->saber_color;
}

void Jedi::print(const char* jedi_name) const {
   std::cout << "Name: " << this->jedi_name << std::endl;
   std::cout << "Rank: " << this->jedi_rank << std::endl;
   std::cout << "Age: " << this->jedi_age << std::endl;
   std::cout << "Saber colour: " << this->saber_color << std::endl;
   std::cout << "Strenght: " << this->jedi_strenght <<std::endl;
}