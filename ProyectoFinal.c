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

    printf("\n Ingrese el nombre del juego: ");
    fflush(stdin);
    gets(dato.nombre);

    int i;

    int check;

    int col=0;

    printf("\n Ingrese el numero correspondiente al genero principal.\n");
    printf("  1.Accion     2.Simulacion\n");
    printf("  3.Deportes   4.Supervivencia\n");
    printf("  5.Estrategia 6.Otro \n");

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
    while(check == 0 );

    printf("\n Ingrese el numero correspondiente a los subgeneros.\n");
    printf("  1.Accion     2.Simulacion\n");
    printf("  3.Deportes   4.Supervivencia\n");
    printf("  5.Estrategia 6.Otro \n");


    do
    {
        check = 1;
        scanf("%d", &i);
        switch(i)
        {
            case 1:
                strcpy(dato.subgeneros[col], Accion); //utilizao macros para poder utilizar los string exactamente igual mas adelnate
                col++;
                break;

            case 2:
                strcpy(dato.subgeneros[col], Simulacion);
                col++;
                break;

            case 3:
                strcpy(dato.subgeneros[col], Deportes);
                col++;
                break;

            case 4:
                strcpy(dato.subgeneros[col], Supervivencia);
                col++;
                break;

            case 5:
                strcpy(dato.subgeneros[col], Estrategia);
                col++;
                break;

            case 6:
                strcpy(dato.subgeneros[col], Otro);
                col++;
                break;


            default:
                MessageBox(NULL, "Opcion no valida, intente nuevamente", "ERROR", MB_OK | MB_ICONERROR);
                check = 0;
                break;
        }

    }
    while(check == 0 || col < 2);


    printf("\n Ingrese el valor del juego: ");
    scanf("%d", &dato.precio);

    printf("\n Ingrese la valoracion del 1 al 5: ");
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
            MessageBox(NULL, "\n Opcion no valida, intente nuevamente", "ERROR", MB_OK | MB_ICONERROR);
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

nodoLista* crearNodo (registroJuego dato)
{
    nodoLista* aux= (nodoLista*)malloc(sizeof(nodoLista));

    aux->dato= dato;
    aux->sig= NULL;

    return aux;
}

void MostrarJuegoAdmin (registroJuego dato)
{
    int i=0;

    printf("\n--------------------------------- \n");

    printf(" \n ID: %i", dato.idJuego);

    printf(" \n Nombre: %s", dato.nombre);

    printf(" \n Genero principal: %s", dato.genero);

    ////////////////////////////////////////////////////

    printf("\n Subgeneros: ");

    for (i=0; i<2; i++)
    {
        printf("[%s] ", dato.subgeneros[i]);

    }
    ////////////////////////////////////////////////////


    printf(" \n Precio: %i", dato.precio);

    printf(" \n Valoracion: %i", dato.valoracion);

    printf(" \n Cantidad de ventas: %i", dato.cantVentas);

    printf(" \n Estado: [%i]", dato.estado);

}

void MostrarJuegoUsuario (registroJuego dato)
{
    int i=0;

    printf("\n\n--------------------------------- ");

    printf(" \n |Nombre: %s", dato.nombre);

    printf(" \n |Genero principal: %s", dato.genero);

    ////////////////////////////////////////////////////

    printf("\n |Subgeneros: ");

    for (i=0; i<2; i++)
    {
        printf("[%s] ", dato.subgeneros[i]);

    }
    /////////////////////////////////////////////////////

    printf(" \n |Precio: %i", dato.precio);

    printf(" \n |Valoracion: %i", dato.valoracion);

    printf("\n--------------------------------- \n");

}

void MostrarNodoAdmin (nodoLista* lista)
{
    if ( lista != NULL )
    {
        nodoLista* seguidora= lista;

        while ( seguidora !=NULL )
        {
            MostrarJuegoAdmin(seguidora->dato);
            seguidora= seguidora->sig;
        }
    }
}

void MostrarNodoUsuario (nodoLista* lista)
{
    if ( lista != NULL )
    {
        nodoLista* seguidora= lista;

        while ( seguidora !=NULL )
        {
            MostrarJuegoUsuario(seguidora->dato);
            seguidora= seguidora->sig;
        }
    }
}
















