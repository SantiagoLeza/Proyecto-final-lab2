#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "ProyectoFinal.h"
#include "balanceArboles.h"
#include "inicio.h"
#include "time.h"

////////////////////////////////////////////////////////////////

int main()
{
    srand(time(NULL));

    nodoBiblioteca* arbol = inicArbol();
    arbol = pasarArchivoArbol(nombreArchiJuegos, arbol);
    arbol = balancearArbol(arbol);

    nodoListaGeneros* listaGeneros = inicStruct();
    listaGeneros = pasarArchiLista(arbol, listaGeneros);

    Fila filaJuegos = inicFila();

    pasarJuegosFila(&filaJuegos, arbol);

    int idUsuario;
    int modo = 0;

    inicio();

incio:
    system("cls");

    if(inicioSesion() == 1)
    {
        system("cls");
        modo = iniciarSesion(nombreArchiUsuarios, &idUsuario);
        if(modo == 0)
        {
            goto incio;
        }
    }
    else
    {
        system("cls");
        idUsuario = Registrase(nombreArchiUsuarios);
        modo = 1;
    }

    if(modo == 1)
    {
        stCliente user = BuscarUsuario(nombreArchiUsuarios, idUsuario);

        if(user.Admin == 1)
        {
            Color(BLACK, RED);
            menuAdmin(arbol, listaGeneros, nombreArchiUsuarios);
            Color(BLACK, WHITE);
        }
        else
        {
            menuUser(arbol, listaGeneros, idUsuario, nombreArchiUsuarios, &filaJuegos);
        }

    }

    system("pause");
    return 0;
}

////////////////////////////////////////////////////////////////
