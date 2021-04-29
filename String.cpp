#include "String.h"

String::String(){
   this->size=0;
   this->data=nullptr;
}

String::String(const String& other) {
   this->size = other.size;
   this->data = new char[this->size];
   strcpy(this->data, other.data);
}

String &String::operator=(const String& other) {
   if(this!= &other) {
      this->size = other.size;
      delete[] this->data;
      this->data= new char[this->size];
      strcpy(this->data, other.data);
   }

   return *this;
}

String::String(size_t size) {
   this->size = size;
   this->data = new char[this->size];
}

String::String(const char* data) {
   this->size = strlen(data);
   this->data = new char[this->size];
   strcpy(this->data, data);
}

String::~String() {
   delete[] this->data;
}

//https://github.com/Werewolfgenesis/OOP-2020-2021/blob/main/Week8/String.h