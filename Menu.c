#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int meses;
    int ano;
} calendario; //Estructura donde almacenar los 2 datos de la fecha


typedef struct{
        char tipo_energia[40];
        float x[24];//donde se van a recoger los valores numericos de cada ipo de energia
        calendario fecha[24];
} energia;


//FUNCIONES
void menu(energia E[]); //Funcion donde realizar el menu
void leerfichero(energia E[]); //Funcion para leer el fichero y guardar la información en la estructura datos
void tabla(); //Función para poner lo datos de una fecha en formato tabla/matriz
void datoconcreto(); //Función para pedir un dato concreto de una fecha concreta
void estadistica(); //Función que realiza opciones estadisticas
void crearfichero(); //Pide al usuario un dato y lo muestra en un fichero generado por el programa
void ordenarvalores(); //Ordena los valores de mayor a menor

#define N 18
int main()
{

    energia E[N]; //Vector estructura para almacenar los datos de las energias de cada fecha
    menu(E);
    //printf("EL DATOS ES: %f", E[6].x[1]); //Comprobación de que la estructura ha recogido bien los datos
    return 0;
}

void menu(energia E[])
{
    int i, opcion;
    leerfichero(E);
    //printf("LA FECHA ES: %d, %d", E[0].fecha[6].meses, E[0].fecha[6].ano);
    printf("Bienvenido/a al menu. Elige la opcion que desees: \n");
    printf("1- Buscar dato concreto\n2- Crear tabla\n3- Buscar estadistica\n4- Poner dato en fichero\n5- Ordenar valores\n6- Salir\n");
    scanf("%d", &opcion);
    switch(opcion)
    {
    case 1:
        datoconcreto();
        break;
    case 2:
        tabla();
        break;
    case 3:
        estadistica();
        break;
    case 4:
        crearfichero();
        break;
    case 5:
        ordenarvalores();
        break;
    case 6:
        printf("\n\nFIN DEL PROGRAMA");
        break;
    }
}

void leerfichero (energia E[])
{
    int i, j, z;
    float valor=0.0;
    char linea[1000], titulo[30], cadnum[30];
    float numero;
    FILE *fichero=NULL;

    //fichero=fopen("C:\\doc\\per\\pruebac\\prueba.txt","rt");
    fichero=fopen(".\\generacion_por_tecnologias_21_22_puntos.csv","rt"); //Abrimos el fichero en modo lectura
    if(fichero==NULL)
        printf("No se pudo abrir el archivo");

    fgets(linea, 1000, fichero); // Saltar las cuatro primeras líneas (títulos)
    //printf("\n%s\n", linea);

    fgets(linea, 1000, fichero);
    fgets(linea, 1000, fichero);
    fgets(linea, 1000, fichero);
    fgets(linea, 1000, fichero); //Recoge la quinta linea (la de las fechas)
    //printf("\n%s\n", linea);
    char *separar1 = strtok(linea, ","); //Va escogiendo los valores/caracteres de la linea separados por comas
    //printf("\n%s\n", separar1);
    sscanf(separar1, "%s", &titulo);
    //printf("El titulo es %s", titulo);
    for (i=0, j=0; j<24; j++) //Bucle para recoger las fechas (se almacenan todas en el vector E[0]
    {
        separar1 = strtok(NULL, ",");
        //puts(separar1);
        int m, a;
        sscanf(separar1, "%d\/%d",&m, &a);
        //printf("TEST %d, %d\t", m, a);
        E[i].fecha[j].meses = m;
        E[i].fecha[j].ano = a;
    }


    for(i=1;i<19;i++) //Bucle para recoger los datos numericos (se almacenan del vector E[1] al E[19]
    {
     fgets(linea, 1000, fichero); //Va recogiendo las líneas de los datos
     //printf("\n%s\n", linea);
     char *separar = strtok(linea,","); //Va escogiendo los valores/caracteres de la linea separados por comas
     sscanf(separar,"%s",E[0].tipo_energia); //Recoge el título
     //printf("%s\n",E[0].tipo_energia);
     for(j=0;j<24;j++)
     {
      separar = strtok(NULL,",");
      //puts(separar);
      float test;
      sscanf(separar, "\"%f",&test);
      //printf("TEST %f\n", test);
      E[i].x[j] = test;
     }
     //getchar();
    }
    //system("pause");

    //getchar();
    //Los getchar() estan para cuando quiero probar si recoge bien un dato, hasta que le doy a enter no salta al siguiente
    fclose(fichero);
}

