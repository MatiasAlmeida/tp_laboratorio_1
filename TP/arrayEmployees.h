#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STRUCTARRAY 3
#define CHARSIZE 51
#define UNSGINT

typedef struct{
    int id;
    char name[CHARSIZE];
    char lastName[CHARSIZE];
    float salary;
    int sector;
    int isEmpty;
}sEmployee;

int initEmployees(sEmployee *, int);

void freeSpace(sEmployee *, int);

int addEmployee(sEmployee *, int, int, char *, char *, float, int);

char valCases(int, char);

void getStructString(char *, int);

void valString(char *, char *, int);

int searchSpace(char *);

float getFloat(float, int);

float valFloat(char *, float, char *, int);

int getInt(int, int);

int valInt(char *, int, char *, int);

int searchCharacter(char *);

unsigned int generateId(unsigned int);
