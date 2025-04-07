#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kota.h"
#include "list.h"

int main() {
    City* head = NULL;
    int choice;
    char cityName[50], personName[50];

    while (1) {
        printf("\nMENU\n");
        printf("pilih 1 Tambah Kota\n");
        printf("pilih 2 Tambah Orang ke Kota\n");
        printf("pilih 3 Tampilkan Semua Data\n");
        printf("pilih 0 Untuk Keluar\n");
        printf("Pilih: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nama Kota: ");
                fgets(cityName, sizeof(cityName), stdin);
                cityName[strcspn(cityName, "\n")] = 0;
                head = addCity(head, cityName);
                break;

            case 2:
                printf("Masukkan nama kota tujuan: ");
                fgets(cityName, sizeof(cityName), stdin);
                cityName[strcspn(cityName, "\n")] = 0;
                {
                    City* temp = head;
                    while (temp != NULL && strcmp(temp->name, cityName) != 0)
                        temp = temp->next;
                    if (temp == NULL) {
                        printf("Kota tidak ditemukan.\n");
                    } else {
                        printf("Nama Orang: ");
                        fgets(personName, sizeof(personName), stdin);
                        personName[strcspn(personName, "\n")] = 0;
                        addPerson(temp, personName);
                    }
                }
                break;

            case 3:
                printAll(head);
                break;

            case 0:
                printf("Terima kasih!\n");
                exit(0);

            default:
                printf("Pilihan tidak valid!\n");
        }
    }

    return 0;
}
