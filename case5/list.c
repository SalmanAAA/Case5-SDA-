#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void addPersonToCity(City* city, const char* personName) {
    Person* newPerson = (Person*)malloc(sizeof(Person));
    strcpy(newPerson->name, personName);
    newPerson->next = NULL;

    if (city->peopleHead == NULL) {
        city->peopleHead = newPerson;
    } else {
        Person* temp = city->peopleHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newPerson;
    }
}

void printCityList(City* cities, int cityCount) {
    for (int i = 0; i < cityCount; i++) {
        printf("Kota: %s\n", cities[i].name);
        Person* current = cities[i].peopleHead;
        int personNum = 1;
        while (current != NULL) {
            printf("  Warga %d: %s\n", personNum++, current->name);
            current = current->next;
        }
        printf("\n");
    }
}
