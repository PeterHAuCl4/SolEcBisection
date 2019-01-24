/*
 * Pedro José Bailón Soto
 * Realizado en Qt Creator 4.8.0, basado en Qt 5.12.0 (GCC 8.2.1 20181127, 64 bit)
 * Bisection method applied to f(x) = x³ + 4x² - 10
 * Realizado el día 22 - 01 - 2019
 *
 * */
#include <iostream>
#include <cmath> //Para utilizar abs() con cualquier número
#include <iomanip> //Agregar la presición deseada
#include <time.h> //Para medir el tiempo de ejecución del programa
#define e 0.0001 //Se maneja el error como una constante que no puede cambiar


using namespace std;

static double calcular(double p_i_aux, double a, double b); //Función recursiva para calcular P_n
static double f(double equis); //Función para ejecutar la función  f(x) = x³ + 4x² - 10
int sumar(int* i); //Función para agregar números al contador 'i'
static int i = 1; //Se declara la variable de forma global para que se pueda llamar desde cualquier función

int main(){

    clock_t start = clock();
    double a = 1, b = 2 , p_i_aux = 0;

    calcular(p_i_aux, a, b);

    cout << "Tiempo transcurrido: " << clock()-start << endl;
    }

double calcular(double p_i_aux, double a, double b){

    /* La variable p_i es P_n y p_i_aux es P_(n-1), absol es la variable que contiene el error
     *
     * */
    double p_i = (a + b)/2;

    double absol = abs(p_i - p_i_aux)/abs(p_i); //Aquí se calcula el error relativo

    cout << setprecision(7) << "i: " << i << " a: " << a << " b: " << b << " Pn: " << p_i
         << " f(an): " << f(a) << " f(Pn): " << f(p_i)<< " Err: " << absol << endl;

    if(absol < e){
        return p_i; //Es para salir de la función
    }else{

        if(f(p_i)*f(a) > 0){ //Si los valores de la función evaluada en P_n y 'a' son positivos, 'a' se convierte en P_n
            a = p_i;
        }else{ //De lo contrario 'b' se convierte en P_n
         b = p_i;
        }
        p_i_aux = p_i; // Se asigna el valor de P_n a P_(n-1)
        i+=1;
        return calcular(p_i_aux, a, b); //En caso de que no se cumpla la condición, se genera la recursividad.
    }
}

double f(double equis){
    return pow(equis , 3) + 4*pow(equis, 2) - 10;
}
int sumar(int* i){
    *i+=1;
    return *i;
}
