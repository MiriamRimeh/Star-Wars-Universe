#include "Commands.h"

void Commands::copy(const Commands& other) {
   this->path = new char[strlen(other.path) + 1];
   strcpy(this->path, other.path);
}

void Commands::erase() {
   delete[] this->path;
}
Commands::Commands() {
   this->path = nullptr;
}

Commands::Commands(const Commands& other) {
   copy(other);
}

Commands& Commands::operator=(const Commands& other) {
   if(this != &other) {
      erase();
      copy(other);
   }
   return *this;
}

Commands::~Commands() {
   erase();
}

void Commands::open(const char* path) {
   char buffer[100];
   strcpy(buffer, path);
   std::fstream io;
   io.getline(buffer, 100);
}




void Commands::help() {
   std::cout << "The following coommands are supported: " << std::endl;
   std::cout << "open <file>        opens <file>" << std::endl
             << "close              closes currently opened file" << std::endl
             << "save               saves the currently open file" << std::endl
             << "saveas <file>      saves the currently opened file in <file>" << std::endl
             << "help               prints helpful information" << std::endl
             << "exit               exits the program" << std::endl; 
}
