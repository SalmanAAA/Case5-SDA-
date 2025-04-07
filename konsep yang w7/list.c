#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "kota.h"

Person* createPerson(const char* name) {
    Person* newPerson = (Person*)malloc(sizeof(Person));
    strcpy(newPerson->name, name);
    newPerson->next = NULL;
    return newPerson;
}

void addPerson(City* city, const char* name) {
    Person* newPerson = createPerson(name);
    if (city->peopleHead == NULL) {
        city->peopleHead = newPerson;
    } else {
        Person* temp = city->peopleHead;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newPerson;
    }
}

void printPeople(Person* head) {
    int i = 1;
    while (head != NULL) {
        printf("  [%d] %s\n", i++, head->name);
        head = head->next;
    }
}
