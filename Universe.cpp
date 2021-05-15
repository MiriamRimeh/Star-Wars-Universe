#include "Universe.h"

void Universe::copy(const Universe& other) {
   this->path = new char[strlen(other.path) + 1];
   strcpy(this->path, other.path);
}

void Universe::erase() {
   delete[] this->path;
}
Universe::Universe() {
   this->path = nullptr;
}

Universe::Universe(const Universe& other) {
   copy(other);
}

Universe& Universe::operator=(const Universe& other) {
   if(this != &other) {
      erase();
      copy(other);
   }

   return *this;
}

Universe::~Universe() {
   erase();
}


bool Universe::can_change_rank() const {
   Jedi jedi;
   if(jedi.get_rank() == YOUNGLING || jedi.get_rank() == GRAND_MASTER) {
      std::cout << "Jedi's rank can't be changed!";
      return false;
   }
   return true;
}

void Universe::add_planet(const char* planet_name) {
   std::ifstream inf("planets.txt");

   char search[32];
   while(!inf.eof()) {
      inf >> search;
      if(strcmp(planet_name, search) == 0) {
         std::cout << "Planet " << planet_name << " already exists!";
         inf.close();
         return;
      }
   }
   inf.close();

   std::ofstream outf("planets.txt", std::ios::app);

   if(outf.is_open()) {
      outf << planet_name << std::endl;
      std::cout << "Planet was added successfully!";
   }
   else {
      std::cout << "Couldn't open file!";
   }

   outf.close();
}

void Universe::create_jedi(const char* planet_name, const char* jedi_name, Rank rank, int age, const char* saber_colour, double strength) {
   std::ifstream inf("jedis.txt");

   char search[32];
   //if(inf)
   while(!inf.eof()) {
      inf.getline(search, 32);
      if(strcmp(jedi_name, search) == 0) {
         std::cout << "Jedi already exists!";
         inf.close();
         return;
      }
   }
   inf.close();

   std::ofstream outf("jedis.txt", std::ios::app);
   Jedi jedi(jedi_name, rank, age, saber_colour, strength);
   outf << planet_name << std::endl
        << jedi.get_name() << std::endl
        << jedi.get_rank() << std::endl
        << jedi.get_age() << std::endl
        << jedi.get_colour() << std::endl
        << jedi.get_strength() << std::endl;
   
   std::cout << "Jedi was created successfuly!";
   outf.close();
} 

/* void Universe::remove_jedi(const char* jedi_name, const char* planet_name) {
   //TODO: check if jedi / planet exists
   //      check if jedi lives on planet

   std::ifstream inf("jedis.txt");
   std::ofstream outf("tempfile.txt", std::ios::app);

   char search[32];
   while(!inf.eof()) {
      inf.getline(search, 32);
      if(strcmp(jedi_name, search) == 0) {}
   }
} */

void Universe::promote_jedi(const char* jedi_name, double multiplier) {
   std::ifstream inf("jedis.txt");

   char search[32];
   while(!inf.eof()) {
      inf.getline(search, 32);
      if(strcmp(jedi_name, search) == 0) {
         std::cout << "Jedi already exists!";
         inf.close();
         return;
      }
   }
   inf.close();

   std::ofstream outf("temp.txt", std::ios::app);

}

//fix
std::ostream& operator<<(std::ostream& out, const Universe& other) {
   out << other;
   return out;
}
