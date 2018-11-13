#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado.
     4. Modificar datos de empleado.
     5. Baja de empleado.
     6. Listar empleados.
     7. Ordenar empleados.
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir.
*****************************************************/


int main(){
    int option = 0;
    int state = 0;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    int flag4 = 0;
    LinkedList* employeeList = ll_newLinkedList();

    do{
        printf("Menu de empleados:\n\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
        printf("3. Alta de empleado.\n4. Modificar datos de empleado.\n5. Baja de empleado.\n");
        printf("6. Listar empleados.\n7. Ordenar empleados.\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir.");

        printf("\n\nIngrese una opcion: ");
        option = controller_getIntMenu(option,OPTIONSIZE);

        if(controller_flagState(option,&flag1,&flag2,&flag3,&flag4,employeeList)==1){
            continue;
        }

        switch(option){
            case 1:
                system("cls");
                state = controller_loadFromText("data.csv",employeeList);
                chargeIsSuccesful(state);
                break;
            case 2:
                system("cls");
                state = controller_loadFromBinary("data.csv",employeeList);
                chargeIsSuccesful(state);
                break;
            case 3:
                system("cls");
                state = controller_addEmployee(employeeList);
                chargeIsSuccesful(state);
                break;
            case 4:
                system("cls");
                state = controller_editEmployee(employeeList);
                chargeIsSuccesful(state);
                break;
            case 5:
                system("cls");
                state = controller_removeEmployee(employeeList);
                deleteIsSuccesful(state);
                break;
            case 6:
                system("cls");
                state = controller_ListEmployee(employeeList);
                chargeIsSuccesful(state);
                break;
            case 7:
                system("cls");
               // state = controller_sortEmployee();
                sortIsSuccesful(state);
                break;
            case 8:
                system("cls");
                state = controller_saveAsText("data.csv",employeeList);
                saveIsSuccesful(state);
                break;
            case 9:
                system("cls");
                state = controller_saveAsBinary("data.csv",employeeList);
                saveIsSuccesful(state);
                break;
            default:
                if(option!=10){
                    printf("\nError. Ingrese una opcion perteneciente al menu.\n");
                    system("pause");
                    system("cls");
                }
                break;
        }
    }while(option != 10);

    return 0;
}
