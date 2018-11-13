#include "Employee.h"

Employee* employee_newParametros(char* idStr,char* nameStr,char* workTimeStr,char* salaryStr){
    Employee* aux;
    int id;
    int workTime;
    int salary;

    aux = (Employee*) malloc(sizeof(Employee));
    aux->name = (char*) malloc(sizeof(char)*STR_CHARSIZE);

    if(aux!=NULL && aux->name!=NULL){
        id = atoi(idStr);
        workTime = atoi(workTimeStr);
        salary = atoi(salaryStr);

        aux->id = id;
        strcpy(aux->name,nameStr);
        aux->workTime = workTime;
        aux->salary = salary;
    }else if(aux->name == NULL){
        aux = NULL;
    }

    return aux;
}

Employee* employee_new(int largestId){
    Employee* aux;
    int id;
    char* name;
    int workTime = 0;
    int salary = 0;

    aux = (Employee*) malloc(sizeof(Employee));
    aux->name = (char*) malloc(sizeof(char)*STR_CHARSIZE);
    name = (char*) malloc(sizeof(char)*STR_CHARSIZE);

    if(aux!=NULL && aux->name!=NULL && name!=NULL){
        id = employee_generateId(largestId);
        printf("Ingrese nombre: ");
        name = employee_setStringName(name,STR_CHARSIZE);
        printf("Ingrese cantidad de horas trabajadas: ");
        workTime = employee_getInt(workTime,STR_CHARSIZE);
        printf("Ingrese salario: ");
        salary = employee_getInt(salary,STR_CHARSIZE);

        if(workTime != -1 && salary != -1){
            aux->id = id;
            strcpy(aux->name,name);
            aux->workTime = workTime;
            aux->salary = salary;
        }else{
            aux = NULL;
        }
    }else{
        aux = NULL;
    }

    free(name);

    return aux;
}

int employee_generateId(int largestId){
    static int id = 0;

    id = largestId;

    id++;

    return id;
}


char* employee_setStringName(char *pString,int len){
    char* pChar;

    if(fgets(pString,len,stdin)!=NULL){
        if((pChar = strchr(pString,'\n')))
            *pChar = '\0';
        else{
            scanf("%*[^\n]");
            scanf("%*c");
        }
    }

   pString = employee_valStringName(pString,pChar,len);

   return pString;
}

char* employee_valStringName(char *pString, char *pChar, int len){
    while(employee_searchNoAlpha(pString)!=0 || *pString=='\0' || isspace(*pString)!=0){
        printf("\nError. Deben ser solo letras.\nIngrese de nuevo: ");

        if(fgets(pString,len,stdin)!=NULL){
            if((pChar = strchr(pString,'\n')))
                *pChar = '\0';
            else{
                scanf("%*[^\n]");
                scanf("%*c");
            }
        }
    }

    strlwr(pString);
    *pString = toupper(*pString);

    return pString;
}

int employee_searchNoAlpha(char *pString){
    int i;
    int state = 0;

    for(i=0 ; *(pString + i)!='\0' ; i++){
        if(isalpha(*(pString + i))==0 && *(pString + i)!=' '){
            state = -1;
            break;
        }
    }

    return state;
}

int employee_getInt(int entero, int len){
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

        entero = employee_valInt(auxEntero,entero,pChar,len);
    }else{
        entero = -1;
    }

    free(auxEntero);

    return entero;
}

int employee_valInt(char *pString, int entero, char *pChar, int len){
    while(employee_searchCharacterInt(pString)!=0 || employee_searchSpace(pString)!=0 || *pString=='\0'){
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

int employee_searchCharacterInt(char *pString){
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

int employee_searchSpace(char *pString){
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

int employee_selectModification(LinkedList* pArrayListEmployee,Employee* this){
    int* pId;
    char* pName;
    int* pWorkTime;
    int* pSalary;
    int option = 0;
    int state = 0;

    pId = (int*) malloc(sizeof(int));
    pName = (char*) malloc(sizeof(char)*STR_CHARSIZE);
    pWorkTime = (int*) malloc(sizeof(int));
    pSalary = (int*) malloc(sizeof(int));

    do{
        system("cls");
        printf("\nEmpleado encontrado:\n");
        printf("%10s %15s %15s %25s %15s\n\n","Indice","ID","Nombre","Cant. horas trabajadas","Salario");
        printf("%10d %15d %15s %25d %15d\n",ll_indexOf(pArrayListEmployee,this) + 1,this->id,this->name,this->workTime,this->salary);

        printf("\nMenu de modificaciones:\n\n1. Modificar ID.\n2. Modificar nombre.\n");
        printf("3. Modificar cant. de horas trabajadas.\n4. Modificar salario.\n5. Salir.");

        printf("\n\nIngrese una opcion: ");
        option = employee_getIntMenu(option,OPTIONSIZE);

        switch(option){
            case 1:
                if(employee_getId(this,pId)==0){
                    printf("\nID actual: %d",*pId);
                    state = employee_setId(this,*pId);
                }
                break;
            case 2:
                if(employee_getNombre(this,pName)==0){
                    printf("\nNombre actual: %s",pName);
                    state = employee_setNombre(this,pName);
                }
                break;
            case 3:
                if(employee_getHorasTrabajadas(this,pWorkTime)==0){
                    printf("\nCant. de horas trabajadas actuales: %d",*pWorkTime);
                    state = employee_setHorasTrabajadas(this,*pWorkTime);
                }
                break;
            case 4:
                if(employee_getSueldo(this,pSalary)==0){
                    printf("\nSalario actual: %d",*pSalary);
                    state = employee_setSueldo(this,*pSalary);
                }
                break;
            default:
                if(option != 5){
                    printf("\nError. Ingrese una opcion perteneciente al menu.\n");
                    system("pause");
                    system("cls");
                }
                break;
            }
    }while(option != 5);

    free(pId);
    free(pName);
    free(pWorkTime);
    free(pSalary);

    return state;
}

int employee_setId(Employee* this,int id){
    int state = 0;
    char confirm = '\0';

    printf("\n\nIngrese ID nuevo: ");
    id = employee_getInt(id,STR_CHARSIZE);
    printf("\nEsta seguro de realizar el cambio? S/N: ");
    confirm = employee_getChar(confirm);

    if(confirm == 'S'){
        this->id = id;
    }

    return state;
}

int employee_getId(Employee* this,int* id){
    int state = 0;

    if(id!=NULL){
        *id = this->id;
    }else{
        state = 1;
    }

    return state;
}

int employee_setNombre(Employee* this,char* name){
    int state = 0;
    char confirm = '\0';

    if(name!=NULL){
        printf("\n\nIngrese nombre nuevo: ");
        name = employee_setStringName(name,STR_CHARSIZE);
        printf("\nEsta seguro de realizar el cambio? S/N: ");
        confirm = employee_getChar(confirm);

        if(confirm == 'S'){
            strcpy(this->name,name);
        }
    }else{
        state = 1;
    }

    return state;
}

int employee_getNombre(Employee* this,char* name){
    int state = 0;

    if(name!=NULL){
        strcpy(name,this->name);
    }else{
        state = 1;
    }

    return state;
}

int employee_setHorasTrabajadas(Employee* this,int workTime){
    int state = 0;
    char confirm = '\0';

    printf("\n\nIngrese nueva cant. de horas trabajadas: ");
    workTime = employee_getInt(workTime,STR_CHARSIZE);
    printf("\nEsta seguro de realizar el cambio? S/N: ");
    confirm = employee_getChar(confirm);

    if(confirm == 'S'){
        this->workTime = workTime;
    }

    return state;
}

int employee_getHorasTrabajadas(Employee* this,int* workTime){
    int state = 0;

    if(workTime!=NULL){
        *workTime = this->workTime;
    }else{
        state = 1;
    }

    return state;
}

int employee_setSueldo(Employee* this,int salary){
    int state = 0;
    char confirm = '\0';

    printf("\n\nIngrese ID nuevo: ");
    salary = employee_getInt(salary,STR_CHARSIZE);
    printf("\nEsta seguro de realizar el cambio? S/N: ");
    confirm = employee_getChar(confirm);

    if(confirm == 'S'){
        this->salary = salary;
    }

    return state;
}

int employee_getSueldo(Employee* this,int* salary){
    int state = 0;

    if(salary!=NULL){
        *salary = this->salary;
    }else{
        state = 1;
    }

    return state;
}

int employee_getIntMenu(int entero, int len){
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

        entero = employee_valIntMenu(auxEntero,entero);
    }else{
        entero = -1;
    }

    free(auxEntero);

    return entero;
}

int employee_valIntMenu(char *pString, int entero){
    if(employee_searchCharacterInt(pString)!=0 || employee_searchSpace(pString)!=0 || *pString=='\0' || strlen(pString)>2){
        strcpy(pString,"0");
    }

    entero=atoi(pString);

    return entero;
}

char employee_getChar(char option){
    option=getchar();
    fflush(stdin);
    option=toupper(option);   ///El toupper tambien es opcional.

    option=employee_valChar(option);  ///Para validar. El prototipo de esta funcion va sin el valChar.

    return option;
}

char employee_valChar(char option){
    while(option!='S' && option!='N'){
        printf("\nError.Ingrese S o N: ");
        option=getchar();
        fflush(stdin);
        option=toupper(option);
    }

    return option;
}
