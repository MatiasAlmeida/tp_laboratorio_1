#include "ArrayEmployees.h"

int main()
{
    sEmployee *arrayEmployees;
    unsigned int auxId=0;
    char auxName[CHARSIZE];
    char auxLastName[CHARSIZE];
    float auxSalary;
    int auxSector;
    char opcion;
    int flag=0;
    int ret=0;
    int retEmployee=0;

    ret=initEmployees(arrayEmployees,STRUCTARRAY);

    if(ret!=0){
        printf("\nError. Algo salio mal.\n");
        return ret;
    }

    do{
        printf("1. ALTAS.\n2. MODIFICAR.\n3. BAJAS.\n4. INFORMAR.\n\nIngrese opcion: ");
        scanf("%c",&opcion);
        fflush(stdin);

        if(flag==0 && (opcion=='2' || opcion=='3' || opcion=='4')){
            printf("\nError. No hay ningun empleado cargado.\n");
            continue;
        }

        switch(opcion){
            case '1':
                //if(id)
                printf("Ingrese nombre: ");
                getStructString(auxName, CHARSIZE);
                printf("\nIngrese apellido: ");
                getStructString(auxLastName, CHARSIZE);
                printf("\nIngrese salario: ");
                auxSalary=getFloat(auxSalary);
                printf("\nIngrese sector: ");
                auxSector=getInt(auxSector,CHARSIZE);
                auxId=generateId(auxId);
                retEmployee=addEmployees(arrayEmployees,auxId,auxName,auxLastName,auxSalary,auxSector);
                flag=1;
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            default:
                if(opcion!='5')
                    printf("\nError. Ingrese una opcion perteneciente al menu.\n\n");
                break;
        }


    }while(opcion!='5');

    return ret;
}
