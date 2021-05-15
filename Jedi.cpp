#include "Jedi.h"

void Jedi::copy(const Jedi& other) {
   this->jedi_name = new char[strlen(other.jedi_name) + 1];
   strcpy(this->jedi_name, other.jedi_name);

   this->rank = other.rank;

   this->age = other.age;
   
   this->saber_colour = new char[strlen(other.saber_colour) + 1];
   strcpy(this->saber_colour, other.saber_colour);
   
   this->strength = other.strength;
}

void Jedi::erase() {
   delete[] jedi_name;
   delete[] saber_colour;
}

Jedi::Jedi() {
   this->jedi_name = nullptr;
   this->rank = Rank::YOUNGLING;
   this->age = 0;
   this->saber_colour = nullptr;
   this->strength = 0;
}

Jedi::Jedi(const Jedi& other) {
   copy(other);
}

Jedi& Jedi::operator=(const Jedi& other) {
   if(this != &other) {
      erase();
      copy(other);
   }

   return *this;
}

Jedi::~Jedi() {
   erase();
}

Jedi::Jedi(const char* name, Rank rank, int age, const char* saber_colour, double strength) {
   this->jedi_name = new char[strlen(name) + 1];
   strcpy(this->jedi_name, name);

   this->rank = rank;

   this->age = age;

   this->saber_colour = new char[strlen(saber_colour) + 1];
   strcpy(this->saber_colour,saber_colour);

   this->strength = strength;
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

void Jedi::set_name(const char* name) {
   if(name != nullptr) {
      delete[] this->jedi_name;

      this->jedi_name = new char[strlen(name) + 1];
      strcpy(this->jedi_name, name);
   }
}

void Jedi::set_rank(Rank rank) {
   this->rank = rank;
}

void Jedi::set_age(int age) {
   this->age = age;
}

void Jedi::set_colour(const char* colour) {
   if(colour != nullptr) {
      delete[] this->saber_colour;

      this->saber_colour = new char[strlen(colour) + 1];
      strcpy(this->saber_colour, colour);
   }
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