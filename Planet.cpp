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
   std::fstream file;
   file.open("planets.txt", std::ios::in | std::ios::out | std::ios::app);

   char search_planet[32];

   if(file.is_open()) {
      while(file.getline(search_planet, 32)) {
         if(strcmp(search_planet, planet_name) == 0) {
            std::cout << "Planet " << planet_name << " already exists!";
            break;
         }
         else {
            file << planet_name << std::endl ;
            std::cout << "Planet added successfully!";
         }
      }
      file.close();
   }
   else {
      std::cout << "Failed to open file";
   }
}

//function doesn't work if we're trying to see if jedi exists
void Planet::create_jedi(const char* planet_name, const char* jedi_name, Rank jedi_rank, int jedi_age, const char* saber_colour, double jedi_strength) {
   std::fstream file;
   file.open("jedis.txt", std::ios::in | std::ios::out | std::ios::app);

   char search_jedi[32];

   if(file.is_open()) {
      file << planet_name << std::endl
                 << jedi_name << std::endl
                 << jedi_rank << std::endl
                 << jedi_age << std::endl
                 << saber_colour << std::endl
                 << jedi_strength << std::endl;

         std::cout << "Jedi was successfully created!";
   /*    while(file.getline(search_jedi, 32)) {
         if(strcmp(search_jedi, jedi_name) == 0) {
            std::cout << "Jedi " << jedi_name << " already exists!";
            break;
         }
         else { 
            file << planet_name << std::endl
                 << jedi_name << std::endl
                 << jedi_rank << std::endl
                 << jedi_age << std::endl
                 << saber_colour << std::endl
                 << jedi_strength << std::endl;

         std::cout << "Jedi was successfully created!";
         }
      } */
      file.close();
   }
   else {
      std::cout << "Failed to open file!";
   }
}

/*void Planet::remove_jedi(const char* jedi_name, const char* planet_name) {
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
   //how to cast enum to int?

   //if this can't be done because of the Rank, think of another way to read through the file
   Jedi* jedi = new Jedi();
   char buffer[64];
   while(!inf.eof()) { //eof -> end of file
      inf.getline(buffer, 64);
      jedi->set_name(buffer);
      
      inf.getline(buffer, 64);
      jedi->set_rank(static_cast<Rank&>(atoi(buffer)));

   } 

   inf.close();
   outf.close();
}*/

/*
void Planet::get_strongest_jedi(const char* planet_name) {
   //open file planets.txt
   //check if planet exists -> if no, print error message, if yes, continue
   //open jedis.txt
   //get each jedi strength
   //compare strengths
   //print jedi with the biggest strength
   //close file

   std::fstream file;
   file.open("planets.txt", std::ios::in | std::ios::out | std::ios::app);

   char search_planet[32];

   if(file.is_open()) {
      while(file.getline(search_planet, 32)) {
         if(strcmp(search_planet, planet_name) != 0) {
            std::cout << "Planet " << planet_name << " doesn't exists! Please create a planet first!";
            break;
         }
         else {
            continue;
         }
      }
      file.close();
   }
   
   file.open("jedis.txt", std::ios::in | std::ios::out | std::ios::app);

   if(file.is_open()) {

   }
   
}
*/


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