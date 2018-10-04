#include "ArrayEmployees.h"

int initEmployees(sEmployee *list, int len){
    int i;
    int ret=-1;

    for(i=0;i<len;i++){
        if(list[i].isEmpty!=1)
            list[i].isEmpty=1;
    }

    if(i==len)
        ret=0;

    return ret;
}

int addEmployee(sEmployee *list, int len, int id, char *name, char *lastName, float salary, int sector){

}

void getStructString(char *pString,int len){
    char *p;

    if(fgets(pString,len,stdin)!=NULL){
        if((p=strchr(pString,'\n')))///check exist newline
            *p='\0';
        else{
            scanf("%*[^\n]");
            scanf("%*c");///clear upto newline
        }

        pString[0]=toupper(pString[0]);
    }

    valString(pString, p, len);
}

void valString(char *pString, char *p, int len){
    while(atoi(pString)!=0 || searchSpace(pString, len)!=0){
        printf("\nError. No puede ingresar numeros o espacios.\nIngrese de nuevo: ");
        if(fgets(pString,len,stdin)!=NULL){
            if((p=strchr(pString,'\n')))///check exist newline
                *p='\0';
            else{
                scanf("%*[^\n]");
                scanf("%*c");///clear upto newline
            }

            pString[0]=toupper(pString[0]);
        }
    }
}

int searchSpace(char *pString){
    int i;
    int flag=0;
    int ret=-1;

    for(i=0;i!='\0';i++){
        if(isspace(pString[i])!=0){
            flag=1;
        }
    }

    if(flag==0)
        ret=0;

    return ret;
}

float getFloat(float salary, int len){
    char auxSalary[len];
    char *p;

    if(fgets(auxSalary,len,stdin)!=NULL){
        if((p=strchr(auxSalary,'\n')))///check exist newline
            *p='\0';
        else{
            scanf("%*[^\n]");
            scanf("%*c");///clear upto newline
        }
    }

    salary=valFloat(auxSalary,salary,p,len);

    return salary;
}

float valFloat(char *pString, float salary, char *pChar, int len){
    while(searchCharacter(pString)!=0 || searchSpace(pString)!=0 || pString[0]=='\0'){
        printf("\nError. No puede ingresar letras o espacios.\nIngrese de nuevo: ");
        if(fgets(pString,len,stdin)!=NULL){
            if((pChar=strchr(pString,'\n')))///check exist newline
                *pChar='\0';
            else{
                scanf("%*[^\n]");
                scanf("%*c");///clear upto newline
            }
    }

    salary=atof(pString);

    return salary;
}

int searchCharacter(char *pString){
    int i;
    int flag=0;
    int ret=-1;

    for(i=0;i!='\0';i++){
        if(isalpha(auxSalary[i])!=0)
            flag=1;
    }

    if(flag==0)
        ret=0;

    return ret;
}

int getInt(int sector, int len){
    char auxSector[len];
    char *p

    if(fgets(auxSector,len,stdin)!=NULL){
        if((p=strchr(auxSector,'\n')))///check exist newline
            *p='\0';
        else{
            scanf("%*[^\n]");
            scanf("%*c");///clear upto newline
        }
    }

    sector=valInt(auxSector,len);

    return sector;
}

int valInt(char *pString, int sector, char *pChar, int len){
    while(searchCharacter(pString)!=0 || searchSpace(pString)!=0 || pString[0]=='\0'){
        if(fgets(auxSector,len,stdin)!=NULL){
            if((p=strchr(auxSector,'\n')))///check exist newline
                *p='\0';
            else{
                scanf("%*[^\n]");
                scanf("%*c");///clear upto newline
            }
        }
    }

    sector=atoi(pString);

    return sector;
}

unsigned int generateId(unsigned int id, int len){
    while(id<=len){
        id++;
        break;
    }

    return id;
    ///printf("\n%d",id); ///para probar si funciona bien el id
}
