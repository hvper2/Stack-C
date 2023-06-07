#ifndef STACK_H
#define STACK_H

typedef struct
{
    char *name;
    int birthYear;
    int direction;
} Student;

typedef struct Node
{
    Student student;
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

void initStack(Stack *stack);
void freeStack(Stack *stack);
void addStudent(Stack *stack, const char *name, int birthYear, int direction);
void removeStudent(Stack *stack);
void printStudents(Stack *stack);
void saveStackToFile(Stack *stack, const char *filename);
void loadStackFromFile(Stack *stack, const char *filename);

#endif
