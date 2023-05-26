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
void tabla(); //Función para poner lo datos de una fecha o tipo de dato en formato tabla (estructurado por filas)
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
        //datoconcreto();
        break;
    case 2:
        tabla(E);
        break;
    case 3:
        //estadistica();
        break;
    case 4:
        crearfichero(E);
        break;
    case 5:
        //ordenarvalores();
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
     sscanf(separar,"%s",E[i].tipo_energia); //Recoge el título
     //printf("%s\n",E[i].tipo_energia);
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

    for (i=0; i<24; i++) //Configuramos manualmente la de fuel+gas para que no de error
    {
        E[5].x[i] = 0;
    }
    E[5].x[6] = -0.000001;
}

void crearfichero(energia E[])
{
    FILE *fichero, *ficheronuevo;
    char nombre[50];
    int tipo_energia, mes;
    float total = 0.0;

    printf("Introduzca el nombre del nuevo fichero: ");
    scanf("%s", nombre);

    fichero = fopen(".\\generacion_por_tecnologias_21_22_puntos.csv", "r");
    if (fichero == NULL) {
        printf("Error al abrir el fichero.\n");
        return;
    }

    ficheronuevo = fopen(nombre, "w");
    if (ficheronuevo == NULL) {
        printf("Error al abrir el nuevo fichero.\n");
        fclose(fichero);
        return;
    }

    printf("Selecciona el tipo de energia que quiere guardar:\n");
    printf("1. Hidraulica \n");
    printf("2. Turbinacion bombeo\n");
    printf("3. Nuclear\n");
    printf("4. Carbon\n");
    printf("5. Fuel + Gas\n");
    printf("6. Motores diesel\n");
    printf("7. Turbina de gas\n");
    printf("8. Turbina de vapo\n");
    printf("9. Ciclo combinado\n");
    printf("10. Hidroeolica\n");
    printf("11. Eolica\n");
    printf("12. Solar fotovoltaica\n");
    printf("13. Solar termica\n");
    printf("14. Otran renovables\n");
    printf("15. Cogeneracion\n");
    printf("16. Residuos no renovables\n");
    printf("17. Residuos renovables\n");

    scanf("%d", &tipo_energia);


    fprintf(ficheronuevo, "Datos mensuales de generación de energía en GWh entre 01/2021 y 12/2022:\n");
    for (mes = 0; mes < 24; mes++) {

        fscanf(fichero, "%f", &E[tipo_energia].x[mes]);
        total += E[tipo_energia ].x[mes];
        fprintf(ficheronuevo, "Mes %d: %.4f\n", mes + 1, E[tipo_energia ].x[mes]);
    }

    fprintf(ficheronuevo, "Total: %.4f\n", total);

    fclose(fichero);
    fclose(ficheronuevo);
    printf("Los datos se han copiado correctamente al nuevo fichero.\n");
}

void tabla(energia E[])
{
    int x, tipodato, fecha, i, j, z;
    do{
        printf("Seleccione que desea ver:\n1- Todos los datos de una fecha\n2- Todas las fechas de un dato\n");
        fflush(stdin);
        scanf("%d", &x);
    }while (x!=1 && x!=2);
    if(x==1)
    {
        printf("Seleccione una fecha:\n");
        for (i=0, z=1, j=0; i<24; i++, j++)
        {
            printf("%d- %d/202%d\n", i+1, j+1, z);
            if(j==11)
            {
                z++;
                j= -1;
            }
        }
        do
        {
            fflush(stdin);
            scanf("%d", &fecha);
        }while(fecha > 24 || fecha < 0);
        printf("Los datos de la fecha %d/%d son:\n", E[0].fecha[fecha-1].meses, E[0].fecha[fecha-1].ano);
        for (i=1; i<19; i++)
        {
            printf("%s:\t %f\n", E[i].tipo_energia, E[i].x[fecha-1]);
            printf("---------------------------------------\n");
        }
    }
    else if (x==2)
    {
        printf("Seleccione un tipo de dato:\n");
        for (i=0, j=1; i<18; i++, j++)
        {
            printf("%d- %s\n", i+1, E[j].tipo_energia);
        }
        do
        {
            fflush(stdin);
            scanf("%d", &tipodato);
        }while(tipodato > 18 || tipodato < 0);
        printf("Los datos por fecha de %s son:\n\n", E[tipodato].tipo_energia);
        for(i=0; i<24; i++)
        {
            if(i<9)
            {
                printf("0");
            }
            if(11 < i && i <21)
            {
                printf("0");
            }
            printf("%d/%d:\t %f\n", E[0].fecha[i].meses, E[0].fecha[i].ano, E[tipodato].x[i]);
            printf("---------------------------------------\n");
        }
    }
}

void estadistica(energia E[]) {
    int inicio, fin;
    printf("Ingrese el índice inicial del intervalo: ");
    scanf("%d", &inicio);
    printf("Ingrese el índice final del intervalo: ");
    scanf("%d", &fin);

    // Validar los índices ingresados por el usuario
    if (inicio < 0 || inicio >= N || fin < 0 || fin >= N || inicio > fin) {
        printf("Intervalo de datos inválido.\n");
        return;
    }

    int i, j;
    float sum = 0.0, sum_cuadrados = 0.0;
    int num_elementos = (fin - inicio) + 1;

    // Calcular la suma de los elementos del intervalo
    for (i = inicio; i <= fin; i++) {
        for (j = 0; j < 24; j++) {
        	//printf("%d \n" , E[i].x[0]);
            sum += E[i].x[j];
            sum_cuadrados += pow(E[i].x[j], 2);
        }
    }


    // Calcular la media
    float media = sum / (num_elementos * 24);

    // Calcular la varianza
    float varianza = (sum_cuadrados / (num_elementos * 24)) - pow(media, 2);

    // Calcular la desviación estándar
    float desviacion = sqrt(varianza);

    printf("Estadísticas para el intervalo [%d, %d]:\n", inicio, fin);
   	bool salir = false;
    while (!salir) {
        int opcion;
        printf("\n¿Qué estadística deseas calcular?\n");
        printf("1. Media\n");
        printf("2. Varianza\n");
        printf("3. Desviación estándar\n");
        printf("4. Calcular estadísticas para otro intervalo\n");
        printf("5. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Media: %.2f\n", media);
                break;
            case 2: {
                // Calcular la varianza
                float varianza = (sum_cuadrados / (num_elementos * 24)) - pow(media, 2);
                printf("Varianza: %.2f\n", varianza);
                break;
            }
            case 3: {
                // Calcular la desviación estándar
                float varianza = (sum_cuadrados / (num_elementos * 24)) - pow(media, 2);
                float desviacion = sqrt(varianza);
                printf("Desviación estándar: %.2f\n", desviacion);
                break;
            }
            case 4:
                estadistica(E); // Llamar a la función estadistica nuevamente
                break;
            case 5:
                salir = true; // Salir del ciclo y terminar la función
                break;
            default:
                printf("Opción inválida. Por favor, selecciona una opción válida.\n");
                break;
        }
    }
}

