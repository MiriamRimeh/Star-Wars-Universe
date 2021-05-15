#pragma once
#include <cstring>
#include <iostream>
#include <fstream>

class Commands {
private:
   char* path;

   void copy(const Commands& other);
   void erase();

public:
   Commands();
   Commands(const Commands& other);
   Commands& operator=(const Commands& other);
   ~Commands();

   void open(const char* path); 
   void close();
   void save();
   void saveas();
   void help();
};