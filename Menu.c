#include<stdio.h>

typedef struct{
    int dia;
    int ano;
}calendario; //Estructura donde almacenar los 2 datos de la fecha

typedef struct{
    calendario fecha;
    double hidraulica;
    double turbinacion; //Turbinación bombeo
    double nuclear;
    double carbon;
    double fuel_gas;
    double motores; //Motores diésel
    double tGas; //Turbina de gas
    double tVapor; //Turbina de vapor
    double cicloc; //Ciclo combinado
    double hidroeolica;
    double eolica;
    double sFotovoltaica; //Solar fotovoltaica
    double sTermica; //Solar térmica
    double otrasRenovables;
    double cogeneracion;
    double residuosNo; //residuos no renovables
    double residuosRenovables; //residuos renovables
    double generacion; //generación total
}datos;

//FUNCIONES
void menu(); //Función donde realizar el menu
void leerfichero (datos []); //Función para leer el fichero y guardar la información en la estructura datos
void tabla(); //Función para poner lo datos de una fecha en formato tabla/matriz
void datoconcreto(); //Función para pedir un dato concreto de una fecha concreta



int main()
{
    menu();
    return 0;
}

void menu()
{
    datos energia[24]; //Vector estructura para almacenar los datos de las energias de cada fecha
    leerfichero (energia);
    printf("Bienvenid@ al menu. Elige la opción que desees: \n");
}

void leerfichero (datos x[])
{
    FILE *fichero;
}
