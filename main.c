#include <stdio.h>
#include <stdlib.h>
#include "stacck.h"

int main() {
    Stack stack;
    initStack(&stack);

    int choice;
    unsigned int year;
    char name[64];
    int direction;

    do {
        printf("--------StackMenu-------\n");
        printf("1. Dodaj studenta\n");
        printf("2. Usun studenta\n");
        printf("3. Wypisz studentow\n");
        printf("4. Zapisz stos do pliku\n");
        printf("5. Odczytaj stos z pliku\n");
        printf("0. Wyjdz\n");
        printf("------------------------\n");
        printf("Wybierz opcje: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Podaj nazwisko studenta: ");
            scanf_s("%s", name, (unsigned int)sizeof(name));
            printf("Podaj rok urodzenia studenta: ");
            scanf_s("%u", &year);
            printf("Podaj kierunek studiow (0-4): ");
            scanf_s("%d", &direction);
            addStudent(&stack, name, year, direction);
            break;
        case 2:
            removeStudent(&stack);
            break;
        case 3:
            printStudents(&stack);
            break;
        case 4:
            saveStackToFile(&stack, "stack.bin");
            break;
        case 5:
            loadStackFromFile(&stack, "stack.bin");
            break;
        case 0:
            printf("Koniec programu.\n");
            break;
        default:
            printf("Nieprawidlowa opcja. Sprobuj jeszcze raz.\n");
            break;
        }
        printf("\n");
    } while (choice != 0);

    freeStack(&stack);

    return 0;
}
