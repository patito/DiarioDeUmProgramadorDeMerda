#include <stdio.h>

#include "person.h"

int main()
{
    Person *father = person_new("Jose", "Rico", 65);
    Person *mother = person_new("Beth", "Perigueti", 21);
   
    person_print(father);
    person_print(mother);

    person_ref(father);
    person_unref(father);
  
    /* New method - Unref */ 
    person_unref(father);    
    person_unref(mother);
    
    return 0;
} 
