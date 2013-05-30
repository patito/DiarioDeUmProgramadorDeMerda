#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "person.h"

Person *person_new (char *first_name, char *last_name, unsigned int age)
{
        if (NULL == first_name) {
            printf("Invalid first_name!\n");
            return NULL;
        }

        if (NULL == last_name) {
            printf("Invalid last_name!\n");
            return NULL;
        }

        Person *obj = (Person *)malloc(sizeof(Person));
        if (NULL == obj) {
                printf("%s Out of Memory!\n", __FUNCTION__);
                return NULL;
        }

	obj->first_name = strdup(first_name);
	obj->last_name = strdup(last_name);
        obj->age = age;
	obj->ref = 1; 	/*  Reference Counting */

        printf("Creating object[%p] Person\n", obj);
	return obj;
}

void person_ref(Person *obj)
{
    if (NULL == obj) {
       printf("Person Obj is NULL");
       return;
    }
    obj->ref++; /*  Incrementando nosso contador */
}

static void _person_destroy(Person *obj)
{
    if (NULL == obj) {
        printf("Person object is NULL!\n");
        return;
    }
    
    if (NULL != obj->first_name) {
        free(obj->first_name);
    }

    if (NULL != obj->last_name) {
        free(obj->last_name);
    }

    free(obj);
}

void person_unref(Person *obj)
{
    if (NULL == obj) {
       printf("Person Obj is NULL");
       return;
    }

    /*  Decrementa o contador e 
     *  verifica se esta igual a 0 
     */
    if (--obj->ref == 0) {
        printf("Memory Release obj[%p]\n", obj);
        _person_destroy(obj);
    }
}

void person_print(Person *obj)
{
    if (NULL == obj) {
       printf("Person Obj is NULL");
       return;
    }

    printf("Obj[%p] Name = %s %s Age = %d\n", obj, 
                                              obj->first_name, 
                                              obj->last_name, 
                                              obj->age);
}


