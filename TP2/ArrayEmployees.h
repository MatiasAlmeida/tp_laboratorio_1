#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STRUCTARRAY 3
#define CHARSIZE 51
#define INTSIZE 65535

typedef struct{
    int id;
    char name[CHARSIZE];
    char lastName[CHARSIZE];
    float salary;
    int sector;
    int isEmpty;
}sEmployee;

int initEmployees(sEmployee *, int);

int freeSlot(sEmployee *, int);

int addEmployee(sEmployee *, int, int, char *, char *, float, int);

char valCases(int, char);

void getString(char *, int);

void valString(char *, char *, int);

int twoWords(char *);

int searchSpace(char *);

float getFloat(float, int);

float valFloat(char *, float, char *, int);

int getInt(int, int);

int valInt(char *, int, char *, int);

int searchCharacterFloat(char *);

int searchCharacterInt(char *);

int searchNoAlpha(char *);

void generateId(int *, int);

char getChar(char);

void valChar(char);

void toUpperChars(char *);
