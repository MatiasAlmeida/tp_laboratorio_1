#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee){
    FILE* pFile;
    int state;

    pFile = fopen(path,"r");

    if(pFile != NULL){
        state = parser_EmployeeFromText(pFile,pArrayListEmployee);
        fclose(pFile);
    }else{
        state = 1;
    }

    return state;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee){
    FILE* pFile;
    int state;

    pFile = fopen(path,"rb");

    if(pFile != NULL){
        state = parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        fclose(pFile);
    }else{
        state = 1;
    }

    return state;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee){
    Employee* pEmployee;
    Employee* pAuxEmployee;
    Node* pNode;
    int largestId = 0;
    int flag = 0;
    int state = 0;

    pEmployee = (Employee*) malloc(sizeof(Employee));
    pAuxEmployee = (Employee*) malloc(sizeof(Employee));
    pNode = (Node*) malloc(sizeof(Node));

    if(pEmployee!=NULL && pAuxEmployee!=NULL && pNode!=NULL){

        if(ll_isEmpty(pArrayListEmployee) == 0){
            pNode = pArrayListEmployee->pFirstNode;
            pAuxEmployee = pNode->pElement;

            while(pNode!=NULL){
                if(flag==0 || largestId < pAuxEmployee->id){
                    largestId = pAuxEmployee->id;
                    flag = 1;
                }

                pNode = pNode->pNextNode;

                if(pNode == NULL){
                    break;
                }

                pAuxEmployee = pNode->pElement;
            }
        }

        pEmployee = employee_new(largestId);
        state = ll_add(pArrayListEmployee,pEmployee);
    }else{
        state = 1;
    }

    return state;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee){
    Employee* pEmployee;
    int index = 0;
    int state = 0;

    if(controller_ListEmployee(pArrayListEmployee)==0){
        printf("\nIngrese el indice del empleado que quiere modificar: ");
        index = controller_getIntId(index,STR_CHARSIZE) - 1;

        pEmployee = ll_get(pArrayListEmployee,index);

        if(pEmployee!=NULL){

            state = employee_selectModification(pArrayListEmployee,pEmployee);

            if(state == 0){
                state = ll_set(pArrayListEmployee,index,pEmployee);
            }
        }else{
            state = 1;
        }
    }else{
        state = 1;
    }

    return state;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee){
    Employee* pEmployee;
    int index = 0;
    int state = 0;
    char confirm = '\0';

    if(controller_ListEmployee(pArrayListEmployee)==0){
        printf("\nIngrese el indice del empleado que quiere eliminar: ");
        index = controller_getIntId(index,STR_CHARSIZE) - 1;

        pEmployee = ll_get(pArrayListEmployee,index);

        if(pEmployee!=NULL){
            system("cls");
            printf("\nEmpleado encontrado:\n");
            printf("%10s %15s %15s %25s %15s\n\n","Indice","ID","Nombre","Cant. horas trabajadas","Salario");
            printf("%10d %15d %15s %25d %15d\n",ll_indexOf(pArrayListEmployee,pEmployee) + 1,pEmployee->id,pEmployee->name,pEmployee->workTime,pEmployee->salary);

            printf("\nDesea eliminar el empleado? S/N: ");
            confirm = controller_getChar(confirm);

            if(confirm == 'S'){
                state = ll_remove(pArrayListEmployee, ll_indexOf(pArrayListEmployee,pEmployee));
            }
        }else{
            state = 1;
        }
    }else{
        state = 1;
    }

    return state;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee){
    Employee* pEmployee;
    Node* pNode;
    int state = 0;

    pNode = (Node*) malloc(sizeof(Node));
    pEmployee = (Employee*) malloc(sizeof(Employee));

    if(pEmployee!=NULL && pNode!=NULL){
        if(ll_isEmpty(pArrayListEmployee) == 0){

            pNode = pArrayListEmployee->pFirstNode;
            pEmployee = pNode->pElement;
            printf("%10s %15s %15s %25s %15s\n\n","Indice","ID","Nombre","Cant. horas trabajadas","Salario");

            while(pNode!=NULL){
                printf("%10d %15d %15s %25d %15d\n",ll_indexOf(pArrayListEmployee,pEmployee) + 1,pEmployee->id,pEmployee->name,pEmployee->workTime,pEmployee->salary);
                pNode = pNode->pNextNode;

                if(pNode == NULL){
                    break;
                }

                pEmployee = pNode->pElement;
            }

            printf("\nCantidad de elementos: %d\n",ll_len(pArrayListEmployee));
        }else{
            state = 1;
        }
    }else{
        state = 1;
    }

    return state;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee){
    int state = 0;
    return state;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee){
    FILE* pEmployeesFile;
    Node* pNode;
    Employee* pEmployee;
    char confirm = '\0';
    int state = 0;

    pNode = (Node*) malloc(sizeof(Node));
    pEmployee = (Employee*) malloc(sizeof(Employee));

    if(pNode!=NULL && pEmployee!=NULL){
        printf("\nEsta seguro que desea guardar los datos actuales? El archivo original sera completamente reescrito.\n");
        printf("S/N: ");
        confirm = controller_getChar(confirm);

        if(confirm == 'S'){
            pEmployeesFile = fopen(path,"w");

            fprintf(pEmployeesFile,"%s,%s,%s,%s\n","id","nombre","horasTrabajadas","sueldo");

            pNode = pArrayListEmployee->pFirstNode;
            pEmployee = pNode->pElement;

            while(pNode!=NULL){
                fprintf(pEmployeesFile,"%d,%s,%d,%d\n",pEmployee->id,pEmployee->name,pEmployee->workTime,pEmployee->salary);
                pNode = pNode->pNextNode;

                if(pNode == NULL){
                    break;
                }

                pEmployee = pNode->pElement;
            }

            fclose(pEmployeesFile);
        }
    }else{
        state = 1;
    }

    return state;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee){
    FILE* pEmployeesFile;
    Node* pNode;
    Employee* pEmployee;
    char confirm = '\0';
    char* string;
    int state = 0;

    pNode = (Node*) malloc(sizeof(Node));
    pEmployee = (Employee*) malloc(sizeof(Employee));
    string = (char*) malloc(sizeof(char)*STR_CHARSIZE);

    if(pNode!=NULL && pEmployee!=NULL && string!=NULL){
        printf("\nEsta seguro que desea guardar los datos actuales? El archivo original sera completamente reescrito.\n");
        printf("S/N: ");
        confirm = controller_getChar(confirm);

        if(confirm == 'S'){
            pEmployeesFile = fopen(path,"wb");

            strcpy(string,"id,nombre,horasTrabajadas,sueldo");

            fwrite(string,sizeof(char)*STR_CHARSIZE,1,pEmployeesFile);

            pNode = pArrayListEmployee->pFirstNode;
            pEmployee = pNode->pElement;

            while(pNode!=NULL){
                fwrite(pEmployee,sizeof(Employee),1,pEmployeesFile);
                pNode = pNode->pNextNode;

                if(pNode == NULL){
                    break;
                }

                pEmployee = pNode->pElement;
            }

            fclose(pEmployeesFile);
        }
    }else{
        state = 1;
    }

    return state;
}

void chargeIsSuccesful(int state){
    if(state == 0){
        printf("\nDatos cargados con exito.\n");
    }else{
        printf("\nSe produjo un error al cargar los datos.\n");
    }

    system("pause");
    system("cls");
}

void deleteIsSuccesful(int state){
    if(state == 0){
        printf("\nDatos eliminados con exito.\n");
    }else{
        printf("\nSe produjo un error al cargar los datos.\n");
    }

    system("pause");
    system("cls");
}

void sortIsSuccesful(int state){
    if(state == 0){
        printf("\nDatos ordenados con exito.\n");
    }else{
        printf("\nSe produjo un error al cargar los datos.\n");
    }

    system("pause");
    system("cls");
}

void saveIsSuccesful(int state){
    if(state == 0){
        printf("\nDatos guardados con exito.\n");
    }else{
        printf("\nSe produjo un error al cargar los datos.\n");
    }

    system("pause");
    system("cls");
}

int controller_getIntId(int entero, int len){
    char* auxEntero;
    char* pChar;

    auxEntero = (char*) malloc(sizeof(char)*len);

    if(auxEntero!=NULL){
        if(fgets(auxEntero,len,stdin)!=NULL){
            if((pChar=strchr(auxEntero,'\n')))
                *pChar='\0';
            else{
                scanf("%*[^\n]");
                scanf("%*c");
            }
        }

        entero = controller_valIntId(auxEntero,entero,pChar,len);
    }else{
        entero = -1;
    }

    free(auxEntero);

    return entero;
}

int controller_valIntId(char *pString, int entero, char *pChar, int len){
    while(controller_searchCharacterIntId(pString)!=0 || controller_searchSpaceId(pString)!=0 || *pString=='\0'){
        printf("\nError. No se pueden poner letras, espacios, simbolos o numeros negativos.\nIngrese de nuevo: ");
        if(fgets(pString,len,stdin)!=NULL){
            if((pChar = strchr(pString,'\n')))
                *pChar = '\0';
            else{
                scanf("%*[^\n]");
                scanf("%*c");
            }
        }

        if(atoi(pString) < 0){
            continue;
        }
    }

    entero = atoi(pString);

    return entero;
}

int controller_searchCharacterIntId(char *pString){
    int i;
    int state = 0;
    int flag = 0;

    for(i=0 ; *(pString + i)!='\0' ; i++){
        if(flag==0 && *pString=='-'){
            flag = 1;
        }
        else if(isalnum(*(pString + i))==0 || isalpha(*(pString + i))!=0){
            state = -1;
            break;
        }
    }

    return state;
}

int controller_searchSpaceId(char *pString){
    int i;
    int state = 0;

    for(i=0 ; *(pString + i)!='\0' ; i++){
        if(isspace(*(pString + i))!=0){
            state = -1;
            break;
        }
    }

    return state;
}

int controller_getIntMenu(int entero, int len){
    char* auxEntero;
    char *pChar;

    auxEntero = (char*) malloc(sizeof(char)*len);

    if(auxEntero!=NULL){
        if(fgets(auxEntero,len,stdin)!=NULL){
            if((pChar=strchr(auxEntero,'\n')))
                *pChar='\0';
            else{
                scanf("%*[^\n]");
                scanf("%*c");
            }
        }

        entero = controller_valIntMenu(auxEntero,entero);
    }else{
        entero = -1;
    }

    free(auxEntero);

    return entero;
}

int controller_valIntMenu(char *pString, int entero){
    if(controller_searchCharacterIntId(pString)!=0 || controller_searchSpaceId(pString)!=0 || *pString=='\0' || strlen(pString)>2){
        strcpy(pString,"0");
    }

    entero=atoi(pString);

    return entero;
}

int controller_flagState(int option,int* flag1, int* flag2, int* flag3, int* flag4, LinkedList* pArrayListEmployee){
    int state = 0;

    if(option>=0 && option<10){
        switch(option){
            case 1:
                if(*flag1!=0){
                    state = ll_clear(pArrayListEmployee);
                }
                *flag1 = 1;

                break;
            case 2:
                if(*flag4 == 0){
                    printf("\nPara cargar un archivo binario primero debe ingresar datos y guardarlos en binario.\n");
                    system("pause");
                    system("cls");
                    state = 1;
                    break;
                }else if(*flag2!=0 || *flag1!=0){
                    state = ll_clear(pArrayListEmployee);
                }
                *flag2 = 1;

                break;
            case 3:
                *flag3 = 1;

                break;
            case 4:
                if(*flag1 == 0 && *flag2 == 0 && *flag3 == 0){
                    printf("\nError. Primero debe cargar datos para hacer otras acciones.\n");
                    system("pause");
                    system("cls");
                    state = 1;
                }

                break;
            case 5:
                if(*flag1 == 0 && *flag2 == 0 && *flag3 == 0){
                    printf("\nError. Primero debe cargar datos para hacer otras acciones.\n");
                    system("pause");
                    system("cls");
                    state = 1;
                }

                break;
            case 6:
                if(*flag1 == 0 && *flag2 == 0 && *flag3 == 0){
                    printf("\nError. Primero debe cargar datos para hacer otras acciones.\n");
                    system("pause");
                    system("cls");
                    state = 1;
                }

                break;
            case 7:
                if(*flag1 == 0 && *flag2 == 0 && *flag3 == 0){
                    printf("\nError. Primero debe cargar datos para hacer otras acciones.\n");
                    system("pause");
                    system("cls");
                    state = 1;
                }

                break;
            case 8:
                if(*flag1 == 0 && *flag2 == 0 && *flag3 == 0){
                    printf("\nError. Primero debe cargar datos para hacer otras acciones.\n");
                    system("pause");
                    system("cls");
                    state = 1;
                }

                break;
            case 9:
                if(*flag1 == 0 && *flag2 == 0 && *flag3 == 0){
                    printf("\nError. Primero debe cargar datos para hacer otras acciones.\n");
                    system("pause");
                    system("cls");
                    state = 1;
                    printf("%d\n",*flag4);
                }
                *flag4 = 1;

                break;
            default:
                break;
        }
    }

    return state;
}

char controller_getChar(char option){
    option = getchar();
    fflush(stdin);
    option = toupper(option);   ///El toupper tambien es opcional.

    option = controller_valChar(option);  ///Para validar. El prototipo de esta funcion va sin el valChar.

    return option;
}

char controller_valChar(char option){
    while(option!='S' && option!='N'){
        printf("\nError.Ingrese S o N: ");
        option = getchar();
        fflush(stdin);
        option = toupper(option);
    }

    return option;
}

