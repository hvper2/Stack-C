#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stacck.h"
#include "error_handling.h"

void initStack(Stack* stack) {
    stack->top = NULL;
}

void freeStack(Stack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp->student.name);
        free(temp);
    }
}

void addStudent(Stack* stack, const char* name, int birthYear, int direction) {
    Student student;
    student.name = malloc(strlen(name) + 1);
    if (student.name == NULL) {
        handleError("Blad alokacji pamieci.");
    }
    strcpy_s(student.name, strlen(name) + 1, name);
    student.birthYear = birthYear;
    student.direction = direction;

    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        handleError("Blad alokacji pamieci.");
    }
    newNode->student = student;
    newNode->next = stack->top;

    stack->top = newNode;

    printf("Dodano studenta.\n");
}


void removeStudent(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stos jest pusty.\n");
        return;
    }

    Node* topNode = stack->top;
    stack->top = topNode->next;

    printf("Usunieto studenta.\n");

    free(topNode->student.name);
    free(topNode);
}

void printStudents(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stos jest pusty.\n");
        return;
    }

    Node* current = stack->top;
    while (current != NULL) {
        printf("Imie i nazwisko: %s\n", current->student.name);
        printf("Rok urodzenia: %d\n", current->student.birthYear);
        printf("Kierunek studiow: %d\n", current->student.direction);
        printf("\n");
        current = current->next;
    }
}

void saveStackToFile(Stack* stack, const char* filename) {
    FILE* file;
    if (fopen_s(&file, filename, "wb") != 0) {
        handleError("Nie mozna otworzyc pliku do zapisu.");
    }

    Node* current = stack->top;
    while (current != NULL) {
        if (fwrite(&current->student, sizeof(Student), 1, file) != 1) {
            handleError("Blad zapisu do pliku.");
        }
        current = current->next;
    }

    fclose(file);
    printf("Stos zostal zapisany do pliku.\n");
}


void loadStackFromFile(Stack* stack, const char* filename) {
    FILE* file;
    if (fopen_s(&file, filename, "rb") != 0) {
        handleError("Nie mozna otworzyc pliku do odczytu.");
    }

    freeStack(stack);

    Student student;
    while (fread(&student, sizeof(Student), 1, file) == 1) {
        addStudent(stack, student.name, student.birthYear, student.direction);
    }

    fclose(file);
    printf("Stos zostal odczytany z pliku.\n");
}
