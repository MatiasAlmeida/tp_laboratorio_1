#include "ArrayEmployees.h"

int initEmployees(sEmployee *list, int len){
    int i;
    int ret=-1;

    if(list!=NULL){
        for(i=0;i<len;i++){
            if(list[i].isEmpty!=1){
                list[i].isEmpty=1;
            }
        }

        if(i==len)
            ret=0;
    }

    return ret;
}

int freeSlot(sEmployee *list, int len){
    int i;
    int index=-1;

    for(i=0;i<len;i++){
        if(list[i].isEmpty==1){
            index=i;
            break;
        }
    }

    return index;
}

int addEmployee(sEmployee *list, int len, int id, char *name, char *lastName, float salary, int sector){
    int index;

    index=freeSlot(list,len);

    if(index!=-1){
        printf("Ingrese nombre: ");
        getString(name, CHARSIZE);
        puts(name);
        printf("\nIngrese apellido: ");
        getString(lastName, CHARSIZE);
        puts(lastName);
        printf("\nIngrese salario: ");
        salary=getFloat(salary, CHARSIZE);
        printf("\n%f\n",salary);
        printf("\nIngrese sector: ");
        sector=getInt(sector, CHARSIZE);
        printf("\n%d\n",sector);
        generateId(&id, INTSIZE);
        printf("\n%d\n",INTSIZE);
        printf("\n%d\n",id);

        list[index].id=id;
        strcpy(list[index].name, name);
        strcpy(list[index].lastName, lastName);
        list[index].salary=salary;
        list[index].sector=sector;
        list[index].isEmpty=0;
    }

    return index;
}

void getString(char *pString,int len){
    char *p;

    if(fgets(pString,len,stdin)!=NULL){
        if((p=strchr(pString,'\n')))///check exist newline
            *p='\0';
        else{
            scanf("%*[^\n]");
            scanf("%*c");///clear upto newline
        }
    }

    valString(pString, p, len);
}

void valString(char *pString, char *p, int len){
    while(searchNoAlpha(pString)!=0 || pString[0]=='\0' || isspace(pString[0])!=0 || twoWords(pString)!=0){
        printf("\nError. No puede ingresar numeros o mas de un espacio.\nIngrese de nuevo: ");
        if(fgets(pString,len,stdin)!=NULL){
            if((p=strchr(pString,'\n')))///check exist newline
                *p='\0';
            else{
                scanf("%*[^\n]");
                scanf("%*c");///clear upto newline
            }
        }
    }

    toUpperChars(pString);
}

void toUpperChars(char *pString){
    int i;

    strlwr(pString);
    pString[0]=toupper(pString[0]);

    for(i=0;pString[i]!='\0';i++){
        if(isspace(pString[i])==1)
            pString[i+1]=toupper(pString[i+1]);
    }
}

int twoWords(char *pString){
    int i;
    int ret=0;
    int cont=0;

    for(i=0;pString[i]!='\0';i++){
        if(cont<2){
            if(pString[i]==' '){
                cont++;
            }
        }else{
            ret=-1;
            break;
        }
    }

    return ret;
}

int searchNoAlpha(char *pString){
    int i;
    int ret=0;

    for(i=0;pString[i]!='\0';i++){
        if(isalpha(pString[i])==0 && pString[i]!=' '){
            ret=-1;
            break;
        }
    }

    return ret;
}

int searchSpace(char *pString){
    int i;
    int ret=0;

    for(i=0;i!='\0';i++){
        if(isspace(pString[i])!=0){
            ret=-1;
            break;
        }
    }

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
    while(searchCharacterFloat(pString)!=0 || searchSpace(pString)!=0 || pString[0]=='\0' ){
        printf("\nError. No puede ingresar letras, simbolos o espacios.\nIngrese de nuevo: ");
        if(fgets(pString,len,stdin)!=NULL){
            if((pChar=strchr(pString,'\n')))///check exist newline
                *pChar='\0';
            else{
                scanf("%*[^\n]");
                scanf("%*c");///clear upto newline
            }
        }
    }

    salary=atof(pString);

    return salary;
}

int searchCharacterFloat(char *pString){
    int i;
    int ret=0;
    int cont=0;

    for(i=0;pString[i]!='\0';i++){
        if(cont<2 && (pString[0]!='.' || pString[0]!=',')){
            if(pString[i]==','){
                pString[i]='.';
                cont++;
            }else if(isalnum(pString[i])==0 || isalpha(pString[i])!=0){
                ret=-1;
                break;
            }
        }else{
            ret=-1;
            break;
        }
    }

    return ret;
}

int getInt(int sector, int len){
    char auxSector[len];
    char *p;

    if(fgets(auxSector,len,stdin)!=NULL){
        if((p=strchr(auxSector,'\n')))///check exist newline
            *p='\0';
        else{
            scanf("%*[^\n]");
            scanf("%*c");///clear upto newline
        }
    }

    sector=valInt(auxSector,sector,p,len);

    return sector;
}

int valInt(char *pString, int sector, char *pChar, int len){
    while(searchCharacterInt(pString)!=0 || searchSpace(pString)!=0 || pString[0]=='\0'){
        if(fgets(pString,len,stdin)!=NULL){
            if((pChar=strchr(pString,'\n')))///check exist newline
                *pChar='\0';
            else{
                scanf("%*[^\n]");
                scanf("%*c");///clear upto newline
            }
        }
    }

    sector=atoi(pString);

    return sector;
}

int searchCharacterInt(char *pString){
    int i;
    int ret=0;

    for(i=0;pString[i]!='\0';i++){
        if(isalnum(pString[i])==0 || isalpha(pString[i])!=0){
            ret=-1;
            break;
        }
    }

    return ret;
}

void generateId(int *id, int len){
    int flag=1;

    while(flag==1){
        if(*id<=len){
            ++(*id);
            printf("\n%d\n",*id);
            break;
        }
    }
    printf("\n%d\n",*id);
    ///return id;

}

char getChar(char option){
    printf("\nDesea ingresar otro empleado? S/N: ");
    option=getchar();
    fflush(stdin);
    option=toupper(option);

    valChar(option);

    return option;
}

void valChar(char option){
    while(option!='S' && option!='N'){
        printf("\nError. Ingrese S si quiere ingresar otro empleado o N si quiere volver al menu.\nIngrese S/N: ");
        option=getchar();
        fflush(stdin);
        option=toupper(option);
    }
}
