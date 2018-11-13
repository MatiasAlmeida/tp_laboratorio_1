#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){
    Employee *pEmployee;
    char* pId;
    char* pName;
    char* pWorkTime;
    char* pSalary;
    int state = 0;

    pId = (char*) malloc(sizeof(char)*STR_CHARSIZE);
    pName = (char*) malloc(sizeof(char)*STR_CHARSIZE);
    pWorkTime = (char*) malloc(sizeof(char)*STR_CHARSIZE);
    pSalary = (char*) malloc(sizeof(char)*STR_CHARSIZE);
    pEmployee = (Employee*) malloc(sizeof(Employee));

    if(pId!=NULL && pName!=NULL && pWorkTime!=NULL && pSalary!=NULL && pEmployee!=NULL){

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",pId,pName,pWorkTime,pSalary);

        printf("%10s %15s %25s %15s\n\n","ID","Nombre","Cant. horas trabajadas","Salario");

        while(!feof(pFile)){
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",pId,pName,pWorkTime,pSalary);

            pEmployee = employee_newParametros(pId,pName,pWorkTime,pSalary);
            state = ll_add(pArrayListEmployee,pEmployee);

            if(state == 1){
                state = ll_clear(pArrayListEmployee);

                if(state == 0){
                    state = 1;
                }

                break;
            }

            printf("%10d %15s %25d %15d\n",pEmployee->id,pEmployee->name,pEmployee->workTime,pEmployee->salary);
        }

        printf("\nCantidad de elementos: %d\n",ll_len(pArrayListEmployee));
    }else{
        state = 1;
    }

    free(pId);
    free(pName);
    free(pWorkTime);
    free(pSalary);
    free(pEmployee);

    return state;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee){
    Employee *pEmployee;
    char* string;
    int state = 0;

    pEmployee = (Employee*) malloc(sizeof(Employee));
    string = (char*) malloc(sizeof(char)*STR_CHARSIZE);

    if(pEmployee!=NULL && string!=NULL){

        fread(string,sizeof(char)*STR_CHARSIZE,1,pFile);

        printf("%s\n\n",string);

        while(!feof(pFile)){
            fread(pEmployee,sizeof(Employee),1,pFile);

            state = ll_add(pArrayListEmployee,pEmployee);

            if(state == 1){
                state = ll_clear(pArrayListEmployee);

                if(state == 0){
                    state = 1;
                }

                break;
            }

            printf("%10d %15s %25d %15d\n",pEmployee->id,pEmployee->name,pEmployee->workTime,pEmployee->salary);
        }

        printf("\nCantidad de elementos: %d\n",ll_len(pArrayListEmployee));
    }else{
        state = 1;
    }

    free(pEmployee);

    return state;
}
