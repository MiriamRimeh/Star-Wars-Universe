#include "Jedi.h"

Jedi::Jedi() {
   this->jedi_name = nullptr;
   this->rank = Rank::YOUNGLING;
   this->age = 0;
   this->saber_colour = nullptr;
   this->strength = 0;
}

Jedi::Jedi(const Jedi& other) {
   this->jedi_name = new char[strlen(other.jedi_name) + 1];
   strcpy(this->jedi_name, other.jedi_name);

   this->rank = other.rank;

   this->age = other.age;

   this->saber_colour = new char[strlen(other.saber_colour) + 1];
   strcpy(this->saber_colour, other.saber_colour);

   this->strength = other.strength;
}

Jedi& Jedi::operator=(const Jedi& other) {
   if(this != &other) {
      delete[] jedi_name;
      delete[] saber_colour;

      this->jedi_name = new char[strlen(other.jedi_name) + 1];
      strcpy(this->jedi_name, other.jedi_name);

      this->rank = other.rank;

      this->age = other.age;

      this->saber_colour = new char[strlen(other.saber_colour) + 1];
      strcpy(this->saber_colour, other.saber_colour);

      this->strength = other.strength;
   }

   return *this;
}

Jedi::~Jedi() {
   delete[] jedi_name;
   delete[] saber_colour;
}

void Jedi::print() const {
   std::cout << "Name: " << this->jedi_name << std::endl
             << "Rank: " << this->rank << std::endl
             << "Age: " << this->age << std::endl
             << "Saber Colour: " << this->saber_colour << std::endl
             << "Strength: " << this->strength << std::endl;
}

Jedi& Jedi::operator<(Jedi& other) {
   if(this > &other) {
      return *this;
   }
   return other;
}

std::ostream& operator<<(std::ostream& out, const Jedi& other) {
   out << "Name: " << other.jedi_name << std::endl
       << "Rank: " << other.rank << std::endl
       << "Age: " << other.age << std::endl
       << "Saber Colour: " << other.saber_colour << std::endl
       << "Strength: " << other.strength <<std::endl;
   
   return out;
}

std::istream& operator>>(std::istream& in, Jedi& other) {
   std::cout << "Name: ";
   in >> other.jedi_name;
   std::cout << "Rank: ";
   in >> other.rank;
   std::cout << "Age: ";
   in >> other.age;
   std::cout << "Saber Colour: ";
   in >> other.saber_colour;
   std::cout << "Strength: ";
   in >> other.strength;

   return in;
}