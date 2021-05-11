#include "Vector.h"
#include "Planet.cpp"

int main () {
   Vector<int> vec;
   vec.push_back(1);
   vec.push_back(2);
   vec.push_back(3);
   vec.push_back(4);
   vec.push_front(0);
   vec.pop_back();
   vec.print();

  std::cout << std::endl;
   Planet planet;
   //planet.add_planet("Jupiter");
   planet.create_jedi("Saturn", "Skywalker", YOUNGLING, 20, "blue", 65.78);
   //planet.create_jedi("Jupiter", "Loki", KNIGHT, 34, "red", 89.90);
   return 0;
   //std::cout << std::endl;
   
}