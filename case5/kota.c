#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define MAX_CITY 100

void inputCitiesAndPeople() {
    int cityCount;
    printf("Masukkan jumlah kota: ");
    scanf("%d", &cityCount);
    getchar();

    City cities[MAX_CITY];

    for (int i = 0; i < cityCount; i++) {
        printf("Nama kota ke-%d: ", i + 1);
        fgets(cities[i].name, sizeof(cities[i].name), stdin);
        cities[i].name[strcspn(cities[i].name, "\n")] = 0; // hapus newline
        cities[i].peopleHead = NULL;

        int personCount;
        printf("  Masukkan jumlah orang di %s: ", cities[i].name);
        scanf("%d", &personCount);
        getchar();

        for (int j = 0; j < personCount; j++) {
            char personName[50];
            printf("    Nama warga ke-%d: ", j + 1);
            fgets(personName, sizeof(personName), stdin);
            personName[strcspn(personName, "\n")] = 0;
            addPersonToCity(&cities[i], personName);
        }
    }

    printCityList(cities, cityCount);
}
