#include "Vector.h"

int main () {
   Vector<int> vec;
   vec.push_back(1);
   vec.push_back(2);
   vec.push_back(3);
   vec.push_back(4);
   vec.push_front(0);
   vec.pop_back();
   vec.print();
}