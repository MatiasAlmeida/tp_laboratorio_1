#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/** \brief Suma los dos operandos recibidos.
 *
 * \param number1 float Recibe el primer operando.
 * \param number2 float Recibe el segundo operando.
 * \return float Retorna el resultado de la suma.
 *
 */
float add(float number1, float number2);

/** \brief Resta el segundo operando al primer operando.
 *
 * \param number1 float Recibe el primer operando.
 * \param number2 float Recibe el segundo operando.
 * \return float Retorna el resultado de la resta.
 *
 */
float subtract(float number1, float number2);

/** \brief Multiplica los dos operandos recibidos.
 *
 * \param number1 float Recibe el primer operando.
 * \param number2 float Recibe el segundo operando.
 * \return float Retorna el producto de los dos operandos.
 *
 */
float multiplicate(float number1, float number2);

/** \brief Divide el primer operando por el segundo operando y guarda el resultado
 *         en una variable puntero, por lo que la funcion retorna una variable int que
 *         indica error cuando se divide por 0 o la valida si es distinto de 0.
 *
 * \param number1 float Recibe el primer operando.
 * \param number2 float Recibe el segundo operando.
 * \param divisionResult float* Recibe el puntero al resultado.
 * \return int Retorna una variable de estado que indica 1 para error y 0 si es valida.
 *
 */
int divide(float number1, float number2, float *pDivisionResult);

/** \brief Calcula el factorial del entero positivo ingresado o de su parte entera
 *         si es un numero real, guarda el resultado en una variable puntero al re-
 *         sultado y retorna una variable int que indica error si es un numero ne-
 *         gativo o la valida si es positivo o cero.
 *
 * \param number float Recibe el operando al que se le calcula el factorial.
 * \param factorialResult long* Recibe el puntero al resultado.
 * \return int Retorna una variable de estado que indica 1 para error y 0 si es valida.
 *
 */
int factorial(float number, double *pFactorialResult);


