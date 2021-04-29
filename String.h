#include <iostream>
#include <cstring>

//https://github.com/stefan50/MyCalendar/blob/master/String.hpp

class String {
private:
   size_t size;
   char* data;

public:
   String();
   String(const String&);
   String &operator=(const String&);
   String(size_t size);
   String(const char* data);
   String(const char* data);
   ~String();

   size_t getSize() const; //Връща размера на низа
	String& concat(const String&); // -- Конкатенира два низа (низ1 = "а", низ2 = "b", низ1.concat(низ2) = "ab")
	String* split(const char* delimiter); // -- Разделя низа по подаден символ или низ
	String& reverse(); // -- Обръща елементите на низа
	void clear(); //Изчиства елементите на низа
	bool empty(); //Проверява дали низа е празен

   String& operator[](int index); // -- Връща символ от низа
   String& String::operator[](int index) const;
   String& operator+=(const String&); // -- Добавя към един низ друг
   String& operator+(const String&); // -- Събира два низа и връща нов низ
   void append(const String&); // -- Добавя към един низ друг
   void pushBack(char); //Добавя символ в края на низа
   void popBack(); //Премахва символ от края на низа
   size_t find(const char*); //Търси и връща първия индекс, на който се среща подадения низ или символ. Ако не съществува такъв индекс връща -1;
   void compare(const String&); //Сравнява два низа лексикографски
   void swap(const String&); //Разменя стойностите на два низа
   void print(); //Извежда на стандартния изход низ

   friend std::istream& operator>>(std::istream& in, String& other) {
      in>>other.size; 
      in.getline(other.data, other.size);
      return in;
   }
   friend std::ostream& operator<<(std::ostream& out, const String& other) { // friend sme go zapisali s cel vse edno this = other
      for(size_t i = 0; i < other.size; ++i) {
         out<<other.data[i];
      }
      return out;
   }
};