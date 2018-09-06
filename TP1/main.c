/*******************************************************************
* Programa: Calculadora (Trabajo Practico N°1)
*
* Objetivo:
   Ingresar dos valores numericos reales, hacer operaciones matema-
   ticas basicas e imprimirlas por pantalla.
       x (Primer valor)
       y (Segundo valor)

*
* Version: 0.1 del 05 septiembre de 2018
* Autor: Matias Almeida
*
********************************************************************/

#include "funciones.h"

int main()
{
    int flag = 0; /** Flag de estado inicializada en 0 para evitar que se muestre basura en el case 4. */
    int aux1, aux2, aux3; /** Auxiliares para almacenar los retornos de error de las funciones division y factorial. */
    long factA, factB; /** Variables en long para almacenar el resultado de los factoriales. */
    float x = 0, y = 0; /** Variables de los operandos A y B inicializadas en 0. */
    float sumaResult, restaResult, multpResult, divnResult; /** Variables para almacenar los resultados de las funciones restantes. */
    char opt; /** Variable char para elegir las opciones del menu dentro de switch. */

    while(1){
        /** Menu de opciones. */
        printf("A=%.6f, B=%.6f\n\n1-Ingresar primer operando(A): ",x , y);
        printf("\n2-Ingresar segundo operando(B): ");
        printf("\n3-Cacular todas las operaciones(A+B, A-B, A*B, A/B, A! y B!).");
        printf("\n4-Mostrar el resultado de las operaciones(A+B, A-B, A*B, A/B, A! y B!).");
        printf("\n5-Salir del programa.\n\nIngrese una opcion: ");
        opt=getch();

        /** Algoritmo de flag de estado para comprobar que calcule antes de mostrar. */
        if(flag == 0 && opt == '4'){
            printf("\n\nPrimero debe ingresar la opcion 3 para calcular las operaciones con los operandos actuales.\n\n");
            system("pause");
            system("cls");
            continue;
        }

        system("cls");

        switch(opt){
            case '1':
                /** Ingresar primer operando */
                printf("(Tener en cuenta que en caso de ingresar un numero con decimales,");
                printf(" se calculara el factorial de la parte entera)");
                printf("\n\nIngrese el valor de A: ");
                scanf("%f", &x);
                fflush(stdin);
                system("cls");
                flag=0;
                break;
            case '2':
                /** Ingresar segundo operando. */
                printf("(Tener en cuenta que en caso de ingresar un numero con decimales,");
                printf(" se calculara el factorial de la parte entera)");
                printf("\n\nIngrese el valor de B: ");
                scanf("%f", &y);
                fflush(stdin);
                system("cls");
                flag=0;
                break;
            case '3':
                /** Llamar a las funciones de calculo. */
                flag=1;                                     /// Al calcular los datos, flag es igual a 1.
                sumaResult=add(x, y);                       /// Variable que guarda el resultado de la suma.
                restaResult=subtract(x, y);                 /// Variable que guarda el resultado de la resta.
                multpResult=multiplicate(x, y);             /// Variable que guarda el resultado de la multiplicacion.
                aux1=divide(x, y, &divnResult);             /// Variable que guarda el resultado del retorno de division.
                aux2=factorial(x, &factA);                  /// Variable que guarda el resultado del retorno del factorial de A.
                aux3=factorial(y, &factB);                  /// Variable que guarda el resultado del retorno del factorial de B.
                printf("Datos calculados exitosamente.\n\n");
                system("pause");
                system("cls");
                break;
            case '4':
                /** Mostrar el resultado de los calculos. */
                printf("La operacion %f + %f es: %f.", x, y, sumaResult);
                printf("\nLa operacion %f - %f es: %f.", x, y, restaResult);
                printf("\nLa operacion %f * %f es: %f.", x, y, multpResult);

                /** If que compara el retorno devuelto en la funcion division para verificar si se divide por 0. */
                if(aux1==0)
                    printf("\nLa operacion %f / %f es: %f", x, y, divnResult);
                else
                    printf("\nLa operacion %f / %f es: Indeterminado(no se puede dividir por 0).", x, y);

                /** If que compara el retorno devuelto en la funcion factorial para saber si la parte entera de A es negativa. */
                if(aux2==0)
                    printf("\nLa operacion %d! es: %ld.", (int)x, factA);
                else
                    printf("\nNo existe el factorial de un numero entero negativo.");

                /** If que compara el retorno devuelto en la funcion factorial para saber si la parte entera de B es negativa. */
                if(aux3==0)
                    printf("\nLa operacion %d! es: %ld.\n\n", (int)y, factB);
                else
                    printf("\nNo existe el factorial de un numero negativo.\n\n");

                system("pause");
                system("cls");
                break;
            case '5':
                /** Salir del programa*/
                system("cls");
                printf("Salio del programa.\n");
                return 0;
            default:
                /** Case para validar que se ingresen las opciones definidas en el menu. */
                printf("La opcion ingresada no corresponde a las del menu, ingrese de nuevo.\n\n");
                system("pause");
                system("cls");
                break;
        }
    }
}
