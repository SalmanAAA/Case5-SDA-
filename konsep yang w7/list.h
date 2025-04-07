#ifndef LIST_H
#define LIST_H

typedef struct Person {
    char name[50];
    struct Person* next;
} Person;

struct City;

Person* createPerson(const char* name);
void addPerson(struct City* city, const char* name);
void printPeople(Person* head);

#endif
