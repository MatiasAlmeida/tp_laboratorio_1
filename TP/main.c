#include "ArrayEmployees.h"

int main()
{
    sEmployee arrayEmployees[STRUCTARRAY];
    int id=1;
    char name[CHARSIZE];
    char lastName[CHARSIZE];
    float salary=0;
    int sector=0;
    char option1;
    char option2;
    int flag=0;
    int ret=0;
    int retEmployee=0;
    int index=0;
    int auxId=0;

    ret=initEmployees(arrayEmployees,STRUCTARRAY);

    if(ret!=0){
        printf("\nError. Algo salio mal.\n");
        return ret;
    }

    do{
        printf("1. ALTAS.\n2. MODIFICAR.\n3. BAJAS.\n4. INFORMAR.\n5. SALIR.\n\nIngrese opcion: ");
        scanf("%c",&option1);
        fflush(stdin);

        if(flag==0 && (option1=='2' || option1=='3' || option1=='4')){
            printf("\nError. No hay ningun empleado cargado.\n");
            continue;
        }

        switch(option1){
            case '1':
                do{
                    retEmployee=addEmployee(arrayEmployees,STRUCTARRAY,id,name,lastName,salary,sector);
                    if(retEmployee!=-1){
                        flag=1;
                        if(id<=INTSIZE){
                            id++;
                        }else{
                            printf("\nEl numero id llego a su limite.\n");
                            break;
                        }
                    }else{
                        printf("\nError. No hay mas espacio.\n");
                        break;
                    }
                    printf("\nDesea ingresar otro empleado? S/N: ");
                    option2=getChar(option2);
                }while(option2=='S');
                break;
            case '2':
                do{
                    index=findEmployeeById(arrayEmployees,STRUCTARRAY,auxId);
                    if(index!=-1){
                        if(modifyEmployee(arrayEmployees,STRUCTARRAY,index)!=0)
                            break;
                    }else{
                        printf("\nLa ID ingresada no existe.\n");
                        break;
                    }
                    printf("\nDesea ingresar otro empleado? S/N: ");
                    option2=getChar(option2);
                }while(option2=='S')
                break;
            case '3':
                do{
                    index=findEmployeeById(arrayEmployees,STRUCTARRAY,auxId);
                    if(index=-1){

                    }else{
                        printf("\nLa ID ingresada no existe.\n");
                        break;
                    }
                }while(option2=='S')
                break;
            case '4':
                break;
            default:
                if(option1!='5')
                    printf("\nError. Ingrese una opcion perteneciente al menu.\n\n");
                break;
        }


    }while(option1!='5');

    return ret;
}
