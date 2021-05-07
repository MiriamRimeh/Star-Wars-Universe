#include "Planet.h"

Planet::Planet() {
   this->planet_name = nullptr;
   this->citizens = Vector<Jedi>::Vector<Jedi>(); //calling the default constructor of class Vector with type Jedi
}

Planet::Planet(const Planet& other) {
   this->planet_name = new char[strlen(other.planet_name) + 1];
   strcpy(this->planet_name, planet_name);

   this->citizens = other.citizens;
}

Planet& Planet::operator=(const Planet& other) {
   if(this != &other) {
      delete[] planet_name;

      this->planet_name = new char[strlen(other.planet_name) + 1];
      strcpy(this->planet_name, planet_name);

      this->citizens = other.citizens;
   }

   return *this;
}

Planet::~Planet() {
   delete[] planet_name;
}

std::ostream& operator<<(std::ostream& out, const Planet& other) {
   out << "Name: " << other.planet_name << std::endl
       << "Jedis: " << std::endl;
   
   for(size_t i = 0; i < other.citizens.get_size(); ++i) {
      other.citizens[i].print();
   }

   return out;
}

std::istream& operator>>(std::istream& in, Planet& other) {
   std::cout << "Name: ";
   in >> other.planet_name;
   std::cout << "Jedis: ";
   in >> other.citizens;

   return in;
}