#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int meses;
    int ano;
} calendario; //Estructura donde almacenar los 2 datos de la fecha


typedef struct{
        char tipo_energia[40];
        char x[24][40];
        } energia;


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
    double generacion; //generacion total
}energia;
*/
//FUNCIONES
void menu(energia E[]); //Funcion donde realizar el menu
void leerfichero(energia E[]); //Funcion para leer el fichero y guardar la información en la estructura datos
void tabla(); //Función para poner lo datos de una fecha en formato tabla/matriz
void datoconcreto(); //Función para pedir un dato concreto de una fecha concreta
void estadistica(); //Función que realiza opciones estadisticas

#define N 18
int main()
{

    energia E[N]; //Vector estructura para almacenar los datos de las energias de cada fecha
    menu(E);
    return 0;
}

void menu(energia E[])
{
    int i;
    leerfichero(E);
    printf("Bienvenido/a al menu. Elige la opcion que desees: \n");
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
    printf("\n%s\n", linea);

    fgets(linea, 1000, fichero);
    fgets(linea, 1000, fichero);
    fgets(linea, 1000, fichero);
    fgets(linea, 1000, fichero);


    for(i=0;i<18;i++)
    {
     fgets(linea, 1000, fichero); //Recoge la quinta linea (la de las fechas)
     printf("\n%s\n", linea);
     char *separar = strtok(linea,","); //Va escogiendo los valores/caracteres de la linea separados por comas
     sscanf(separar,"%s",E[0].tipo_energia);
     printf("%s\n",E[0].tipo_energia);
     for(j=0;j<24;j++)
     {
      separar = strtok(NULL,",");
      puts(separar);
      sscanf(separar,E[i].x[j]);
      printf("%s\n",E[i].x[j]);
     }
     getchar();
    }
    system("pause");

    getchar();
    //printf("El titulo es %s", titulo);
}

    i=0;
    while(separar != NULL ) {
        //printf( "%s\n", separar);
        sscanf(separar, "%d/%d", &x[i-1].fecha.meses, &x[i-1].fecha.ano); //Recoge las fechas en la estructura (se le pone -1 para esten en las posiciones del 0 al 23)
        //printf("\nlas fechas %d son: %d\t%d", i-1, x[i-1].fecha.meses, x[i-1].fecha.ano);
        separar = strtok(NULL, ",");
        i++;
    }


    fgets(linea, 1000, fichero); //Recoge la sexta linea (hidraulica)
    printf("Esta es la cadena recogida: \n%s\n", linea);
    getchar();
    i=-1;
    do{ //Bucle para cambiar las comas de los numeros por puntos
        i++;
        if(linea[i]=='"')
        {
            do{
                i++;
                if (linea[i] == ',')
                {
                    linea[i] = '.';
                }
            }while(linea[i] != '"');
        }

    }while(linea[i] != '\n');
    printf("Esta es la cadena cambiada: \n%s\n", linea);

    for(i=0, z=0; linea[i] != '\n'; i++)
    {
        if (linea[i]== '"')
        {
            j=0;
            i++;
            do{
                cadnum[j] = linea[i];
                i++;
                j++;
            }while(linea[i] != '"');
            j++;
            cadnum[j] = '\0';
            printf("%s    ", cadnum);
            x[z].hidraulica = atof(cadnum);
            printf("\n");
            printf("El num %d es: %.3f  ", z+1, x[z].hidraulica);
            z++;
        }
    }


    fclose(fichero);
}

