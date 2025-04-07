#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kota.h"

City* createCity(const char* name) {
    City* newCity = (City*)malloc(sizeof(City));
    strcpy(newCity->name, name);
    newCity->next = NULL;
    newCity->prev = NULL;
    newCity->peopleHead = NULL;
    return newCity;
}

City* addCity(City* head, const char* name) {
    City* newCity = createCity(name);
    if (head == NULL) {
        return newCity;
    } else {
        City* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newCity;
        newCity->prev = temp;
        return head;
    }
}

void printAll(City* head) {
    int i = 1;
    while (head != NULL) {
        printf("\nKota [%d]: %s\n", i++, head->name);
        printPeople(head->peopleHead);
        head = head->next;
    }
}
