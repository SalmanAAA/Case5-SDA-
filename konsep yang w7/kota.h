#ifndef KOTA_H
#define KOTA_H

#include "list.h"

typedef struct City {
    char name[50];
    struct City* prev;
    struct City* next;
    Person* peopleHead;
} City;

City* createCity(const char* name);
City* addCity(City* head, const char* name);
void printAll(City* head);

#endif
