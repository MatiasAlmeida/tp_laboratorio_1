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

    if(fgets(pString,len,stdin)!=NULL && strlen(pString)<len-1){
        if((p=strchr(pString,'\n')))///check exist newline
            *p='\0';
        else{
            scanf("%*[^\n]");
            scanf("%*c");///clear upto newline
        }

        pString[0]=toupper(pString[0]);

    }else if(strlen(pString)==len-1)///ahora veo que hago con este else if

    valString(pString, p, len);
}

void valString(char *pString, char *p, int len){
    while(atoi(pString)!=0 || searchSpace(pString, len)!=0){
        if(fgets(pString,len,stdin)!=NULL){
            if((p=strchr(pString,'\n')))///check exist newline
                *p='\0';
            else{
                scanf("%*[^\n]");
                scanf("%*c");///clear upto newline
            }
        }
    }
}

int searchSpace(char *pString, int len){
    int i;
    int cont=0;
    int ret=-1;

    for(i=0;i<len-1;i++){
        if(isspace(pString[i])!=0){
            cont++;
        }
    }

    if(cont==0)
        ret=0;

    return ret;
}

int generateId(int id, int len){
    while(id+1<=len){
        id++;
        break;
    }

    return id;
}
