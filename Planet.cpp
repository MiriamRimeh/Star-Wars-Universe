#include "Planet.h"

Planet::Planet() {
   this->planet_name = nullptr;
   //this->citizens = Vector<Jedi>::Vector<Jedi>(); //calling the default constructor of class Vector with type Jedi
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

void Planet::add_planet(const char* planet_name) {
   std::ofstream outf;
   outf.open("planets.txt", std::ios::app);

   if(outf.is_open()) {
      outf << planet_name << std::endl;
      std::cout << "Planet added successfully!";
      outf.close();
   }
   else {
      std::cout << "Failed to open file";
   }
}

void Planet::create_jedi(const char* planet_name, const char* jedi_name, Rank jedi_rank, int jedi_age, const char* saber_colour, double jedi_strength) {
   
   std::ofstream outf;
   
   outf.open("jedis.txt");

   if(outf.is_open()) {
      outf << planet_name << std::endl
           << jedi_name << std::endl
           << jedi_rank << std::endl
           << jedi_age << std::endl
           << saber_colour << std::endl
           << jedi_strength << std::endl;
      std::cout << "Jedi was successfully created!";
      outf.close();
   }
   else {
      std::cout << "Failed to open file!";
   }
}

void Planet::remove_jedi(const char* jedi_name, const char* planet_name) {
   std::ifstream inf;
   inf.open("jedis.txt");

   std::ofstream outf;
   outf.open("temp.txt", std::ios::app);

   //open jedis.txt and a temp file
   //scan through the file by comparing each line does it match the name and the planet or not
   //copy everything except the jedi and his info
   //how to delete info not mentioned in the arguments of the function?
   //can i delete a text between two words?
   //should i make setters and getters for the jedi variables?

/*    if(in.is_open()) {
      if()
   } */

   inf.close();
   outf.close();
}

//comment this section if you can't think of an solution tomorrow and move on to the functions that can be done without it

std::ostream& operator<<(std::ostream& out, const Planet& other) {
   out << "Name: " << other.planet_name << std::endl
       << "Jedis: " << std::endl;
   
   for(size_t i = 0; i < other.citizens.get_size(); ++i) {
      other.citizens[i].print();
   }

   return out;
}

/* std::istream& operator>>(std::istream& in, Planet& other) {
   std::cout << "Name: ";
   in >> other.planet_name;
   std::cout << "Jedis: ";
   in >> other.citizens;

   return in;
} */