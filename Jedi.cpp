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

const char* Jedi::get_name() const {
   return this->jedi_name;
}

Rank& Jedi::get_rank() {
   return this->rank;
}

int Jedi::get_age() {
   return this->age;
}

const char* Jedi::get_colour() const {
   return this->saber_colour;
}

double Jedi::get_strength() {
   return this->strength;
}

void Jedi::set_name(char* name) {
   this->jedi_name = name;
}

void Jedi::set_rank(Rank rank) {
   this->rank = rank;
}

void Jedi::set_age(int age) {
   this->age = age;
}

void Jedi::set_colour(char* colour) {
   this->saber_colour = colour;
}

void Jedi::set_strength(double strength) {
   this->strength = strength;
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