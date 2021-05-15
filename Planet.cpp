#include "Planet.h"

void Planet::copy(const Planet& other) {
   this->planet_name = new char[strlen(other.planet_name) + 1];
   strcpy(this->planet_name, planet_name);
   
   this->jedis = other.jedis;
}

void Planet::erase() {
   delete[] this->planet_name;
}

Planet::Planet() {
   this->planet_name = nullptr;
}

Planet::Planet(const Planet& other) {
   copy(other);
}

Planet& Planet::operator=(const Planet& other) {
   if(this != &other) {
      erase();
      copy(other);
   }

   return *this;
}

Planet::~Planet() {
   erase();
}

const char* Planet::get_planet_name() const {
   return this->planet_name;
}

void Planet::set_planet_name(const char* name) {
   if(name != nullptr) {
      delete[] this->planet_name;
      
      this->planet_name = new char[strlen(name) + 1];
      strcpy(this->planet_name, name);
   }
}

void Planet::set_jedis(const Vector<Jedi>& other) {
   this->jedis = other;
}

std::ostream& operator<<(std::ostream& out, const Planet& other) {
   out << "Name: " << other.planet_name << std::endl
       << "Jedis: " << std::endl;
   
   for(size_t i = 0; i < other.jedis.get_size(); ++i) {
      out << other.jedis[i];
   }

   return out;
}

//
std::istream& operator>>(std::istream& in, Planet& other) {
   in >> other; //fix
   return in;
}