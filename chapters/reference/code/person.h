#ifndef _PERSON_H_
#define _PERSON_H_

typedef struct {
    char *first_name;
    char *last_name;
    unsigned int age;
    unsigned ref;
} Person;

/*  Method to create the persong object */
Person* person_new(char *first_name, 
                   char *last_name, 
                   unsigned int age);

/* Retain the object */
void person_ref(Person *obj);

/* Release the object */
void person_unref(Person *obj);

/* Print object information */
void person_print(Person *obj);


#endif /* _PERSON_H_ */
