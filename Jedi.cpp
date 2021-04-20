#include "Jedi.h"

void Jedi :: copy (const Jedi& other_jedi) {
   
}

Jedi :: Jedi () { // check if I need to put this-> in front of the variables
   jedi_name = "Default";
   jedi_rank = YOUNGLING; // default is YOUNGLING because when creating a jedi they should be the lowest rank possible unless stated otherwise
   jedi_age = 0;
   saber_color = "Default";
   jedi_strenght = 0;
   //planet = "default";
}