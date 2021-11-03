#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "ProyectoFinal.h"

/////////////////////////////////////////////////////////////////

void cargarJuegosAlArchivo(char archivo[])
{
    int retorno = 0;

    FILE *archi = fopen(archivo, "a");

    if(archi)
    {
        registroJuego dato;

        do
        {
            dato = crearRegistro();
            fwrite(&dato, sizeof(registroJuego), 1, archi);

            retorno = MessageBox(NULL, "Desea cargar otro?", "Aviso", MB_OKCANCEL);
        }
        while(retorno != IDCANCEL);

        fclose(archi);
    }
}

registroJuego crearRegistro()
{
    registroJuego dato;

    dato.idJuego = cantJuegosArchi(nombreArchiJuegos);

    printf("Ingrese el nombre del juego.\n");
    fflush(stdin);
    gets(dato.nombre);

    int i;
    printf("Ingrese el numero correspondiente al genero.\n");
    printf("1.Accion     2.Simulacion\n");
    printf("3.Deportes   4.Supervivencia\n");
    printf("5.Estrategia 6.Otro \n");

    int check;

    do
    {
        check = 1;
        scanf("%d", &i);
        switch(i)
        {
            case 1:
                strcpy(dato.genero, Accion); //utilizao macros para poder utilizar los string exactamente igual mas adelnate
                break;

            case 2:
                strcpy(dato.genero, Simulacion);
                break;

            case 3:
                strcpy(dato.genero, Deportes);
                break;

            case 4:
                strcpy(dato.genero, Supervivencia);
                break;

            case 5:
                strcpy(dato.genero, Estrategia);
                break;

            case 6:
                strcpy(dato.genero, Otro);
                break;

            default:
                MessageBox(NULL, "Opcion no valida, intente nuevamente", "ERROR", MB_OK | MB_ICONERROR);
                check = 0;
                break;
        }

    }
    while(check == 0);

    printf("Ingrese el valor del juego: \n");
    scanf("%d", &dato.precio);

    printf("Ingrese la valoracion del 1 al 5.\n");
    do
    {
        i=0;
        check = 0;

        scanf("%d", &i);

        if(i>=1 && i<=5)
        {
            dato.valoracion = i;
            check = 1;
        }
        else
        {
            MessageBox(NULL, "Opcion no valida, intente nuevamente", "ERROR", MB_OK | MB_ICONERROR);
        }
    }
    while(check == 0);

    dato.cantVentas = 0;

    dato.estado = 1;

    return dato;
}

int cantJuegosArchi(char archivo[])
{
    int i = 0;

    FILE *archi2 = fopen(archivo, "r");
    if(archi2)
    {
        fseek(archi2, sizeof(registroJuego), SEEK_END);
        int dim = ftell(archi2);

        i = dim / sizeof(registroJuego);

        fclose(archi2);
    }
    else
    {
        MessageBox(NULL, "Error de archivos.", "ERROR", MB_OK | MB_ICONERROR);
    }

    return i;
}

/////////////////////////////////////////////////////////////////
