#include "Program.h"

Program::Program() {
   this->path = nullptr;
}

Program::Program(const Program& other) {
   if(&other != nullptr) {
      this->path = new char[strlen(other.path) + 1];
      strcpy(this->path, other.path);
   }
}

Program& Program::operator=(const Program& other) {
   if(this != &other) {
      delete[] path;

      this->path = new char[strlen(other.path) + 1];
      strcpy(this->path, other.path);
   }

   return *this;
}

Program::~Program() {
   delete[] path;
}

void Program::help() {
   std::cout << "The following coommands are supported: " << std::endl;
   std::cout << "open <file>        opens <file>" << std::endl
             << "close              closes currently opened file" << std::endl
             << "save               saves the currently open file" << std::endl
             << "saveas <file>      saves the currently opened file in <file>" << std::endl
             << "help               prints helpful information" << std::endl
             << "exit               exits the program" << std::endl; 
}


bool Program::can_change_rank() {
   Jedi jedi;
   if(jedi.get_rank() == YOUNGLING || jedi.get_rank() == GRAND_MASTER) {
      std::cout << "Jedi's rank can't be changed!";
      return false;
   }
   return true;
}

void Program::add_planet(const char* planet_name) {
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

void Program::create_jedi(const char* planet_name, const char* jedi_name, Rank rank, int age, const char* saber_colour, double strength) {
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

/* void Program::remove_jedi(const char* jedi_name, const char* planet_name) {
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

void Program::promote_jedi(const char* jedi_name, double multiplier) {
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

std::ostream& operator<<(std::ostream& out, const Program& other) {
   out << other;
   return out;
}
