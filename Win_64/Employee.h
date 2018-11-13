#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STR_CHARSIZE 128
#define OPTIONSIZE 8

typedef struct
{
    int id;
    char* name;
    int workTime;
    int salary;
}Employee;

Employee* employee_new(int largestId);
Employee* employee_newParametros(char* idStr,char* nameStr,char* workTimeStr,char* salaryStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* name);
int employee_getNombre(Employee* this,char* name);

int employee_setHorasTrabajadas(Employee* this,int workTime);
int employee_getHorasTrabajadas(Employee* this,int* workTime);

int employee_setSueldo(Employee* this,int salary);
int employee_getSueldo(Employee* this,int* salary);

int employee_generateId(int largestId);

char* employee_setStringName(char *pString,int len);
char* employee_valStringName(char *pString, char *pChar, int len);
int employee_searchNoAlpha(char *pString);

int employee_getInt(int entero, int len);
int employee_valInt(char *pString, int entero, char *pChar, int len);
int employee_searchCharacterInt(char *pString);
int employee_searchSpace(char *pString);

int employee_getIntMenu(int entero, int len);
int employee_valIntMenu(char *pString, int entero);

int employee_selectModification(LinkedList* pArrayListEmployee, Employee* this);

char employee_getChar(char option);
char employee_valChar(char option);

#endif // employee_H_INCLUDED
