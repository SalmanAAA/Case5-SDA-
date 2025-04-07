#ifndef LIST_H
#define LIST_H

typedef struct Person {
    char name[50];
    struct Person* next;
} Person;

typedef struct City {
    char name[50];
    Person* peopleHead;
} City;

void addPersonToCity(City* city, const char* personName);
void printCityList(City* cities, int cityCount);

#endif
