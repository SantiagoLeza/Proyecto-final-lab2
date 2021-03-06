#include "balanceArboles.h"
#include <stdio.h>
#include <stdlib.h>
#include "ProyectoFinal.h"
#include <windows.h>

nodoBiblioteca* enlistarNodo(nodoBiblioteca* arbol, nodoBiblioteca* nuevo)
{
    if(!arbol)
    {
        arbol = nuevo;
    }
    else
    {
        if(nuevo->dato.idJuego < arbol->dato.idJuego)
        {
            arbol->izq = enlistarNodo(arbol->izq, nuevo);

        }
        else
        {
            arbol->der = enlistarNodo(arbol->der, nuevo);
        }
    }

    return arbol;
}

void mostrarArbolPreOrden(nodoBiblioteca* arbol)
{
    if(arbol)
    {
        MostrarJuegoUsuario(arbol->dato);
        mostrarArbolPreOrden(arbol->izq);
        mostrarArbolPreOrden(arbol->der);
    }
}

void mostrarArbolInOrden(nodoBiblioteca* arbol)
{
    if(arbol)
    {
        mostrarArbolPreOrden(arbol->izq);
        MostrarJuegoUsuario(arbol->dato);
        mostrarArbolPreOrden(arbol->der);
    }
}

int cantNodos(nodoBiblioteca* arbol)
{
    int i=0;

    if(arbol != NULL)
    {
        i = 1;
        i+=cantNodos(arbol->izq);
        i+=cantNodos(arbol->der);
    }

    return i;
}

nodoBiblioteca* balancearArbol(nodoBiblioteca* arbol)
{
    if(arbol)
    {
        if(arbol->izq != NULL)
        {
            while((cantNodos(arbol->izq) - cantNodos(arbol->der)) >= 2)
            {
                arbol = desplazarDerecha(arbol);
            }

            arbol->izq = balancearArbol(arbol->izq);
        }
        if(arbol->der != NULL)
        {
            while((cantNodos(arbol->izq) - cantNodos(arbol->der)) <= -2)
            {
                arbol = desplazarIzquierda(arbol);
            }

            arbol->der = balancearArbol(arbol->der);
        }
    }

    return arbol;
}

nodoBiblioteca* borrarNodo(nodoBiblioteca* arbol, int aBorrar)
{
    if(arbol)
    {
        if(arbol->dato.idJuego == aBorrar)
        {
            if(arbol->izq != NULL)
            {
                nodoBiblioteca* masDer = masDerecha(arbol->izq);
                arbol->dato = masDer->dato;
                arbol->izq = borrarNodo(arbol->izq, masDer->dato.idJuego);
            }
            else if(arbol->der != NULL)
            {
                nodoBiblioteca* masIzq = masIzquierda(arbol->der);
                arbol->dato = masIzq->dato;
                arbol->der = borrarNodo(arbol->der, masIzq->dato.idJuego);
            }
            else
            {
                free(arbol);
                arbol = NULL;
            }
        }
        else if(arbol->dato.idJuego > aBorrar)
        {
            arbol->izq = borrarNodo(arbol->izq, aBorrar);
        }
        else if(arbol->dato.idJuego < aBorrar)
        {
            arbol->der = borrarNodo(arbol->der, aBorrar);
        }
    }

    return arbol;
}

nodoBiblioteca* masIzquierda(nodoBiblioteca* arbol)
{
    nodoBiblioteca* retorno = arbol;

    if(arbol)
    {
        while(retorno->izq != NULL)
        {
            retorno = retorno->izq;
        }
    }
    else
    {
        retorno = NULL;
    }
    return retorno;
}

nodoBiblioteca* masDerecha(nodoBiblioteca* arbol)
{
    nodoBiblioteca* retorno = arbol;

    if(arbol)
    {
        while(retorno->der != NULL)
        {
            retorno = retorno->der;
        }
    }
    else
    {
        retorno = NULL;
    }
    return retorno;
}

nodoBiblioteca* desplazarDerecha(nodoBiblioteca* arbol)
{
    registroJuego aux = arbol->dato;
    registroJuego aux2 = masDerecha(arbol->izq)->dato;

    arbol = borrarNodo(arbol, masDerecha(arbol->izq)->dato.idJuego);
    arbol->dato = aux2;

    arbol = enlistarNodo(arbol, CrearNodoArbol(aux));

    return arbol;
}

nodoBiblioteca* desplazarIzquierda(nodoBiblioteca* arbol)
{
    registroJuego aux = arbol->dato;
    registroJuego aux2 = masIzquierda(arbol->der)->dato;

    arbol = borrarNodo(arbol, masIzquierda(arbol->der)->dato.idJuego);
    arbol->dato = aux2;

    arbol = enlistarNodo(arbol, CrearNodoArbol(aux));

    return arbol;
}

//////////////////////////////////////////////////////////////////////////////////////

nodoBiblioteca* pasarArchivoArbol(char archivo[], nodoBiblioteca* arbol)
{
    FILE *archi = fopen(archivo, "rb");
    registroJuego aux;
    nodoBiblioteca* nuevo;

    if(archi)
    {
        while(fread(&aux, sizeof(registroJuego), 1, archi) > 0)
        {
            nuevo = CrearNodoArbol(aux);
            arbol = enlistarNodo(arbol, nuevo);
        }

        fclose(archi);
    }
    else
    {
        MessageBox(NULL, "Error de archivos.", "ERROR", MB_OK | MB_ICONERROR);
    }

    return arbol;
}

void mostrarArchivoJuegos(char archivo[])
{
    FILE *archi = fopen(archivo, "rb");
    registroJuego aux;

    if(archi)
    {
        while(fread(&aux, sizeof(registroJuego), 1, archi) > 0)
        {
            MostrarJuegoAdmin(aux);
        }

        fclose(archi);
    }
}

void sumarVenta(char Archivo[], int idJuego)
{
    FILE *archi = fopen(Archivo, "r+b");
    registroJuego aux;
    int flag = 0;

    if(archi)
    {
        while(flag == 0 && fread(&aux, sizeof(registroJuego), 1, archi) > 0)
        {
            if(aux.idJuego == idJuego)
            {
                flag = 1;
                aux.cantVentas += 1;
                fseek(archi, sizeof(registroJuego)*-1, SEEK_CUR);
                fwrite(&aux, sizeof(registroJuego), 1, archi);
            }
        }

        fclose(archi);
    }
}

registroJuego buscarPorId(nodoBiblioteca* arbol, int id)
{
    registroJuego aux;

    if(arbol)
    {
        if(arbol->dato.idJuego == id)
        {
            aux = arbol->dato;
        }
        else if(id < arbol->dato.idJuego)
        {
            aux = buscarPorId(arbol->izq, id);
        }
        else
        {
            aux = buscarPorId(arbol->der, id);
        }
    }

    return aux;
}

registroJuego buscarPorNombre(nodoBiblioteca* arbol, char nombre[])
{
    registroJuego retorno;
    retorno.idJuego = -1;

    if(arbol)
    {
        if(strcmpi(arbol->dato.nombre, nombre) == 0 || strstr(arbol->dato.nombre, nombre))
        {
            retorno = arbol->dato;
        }
        else
        {
            retorno = buscarPorNombre(arbol->izq, nombre);
            if(retorno.idJuego == -1)
            {
                retorno = buscarPorNombre(arbol->der, nombre);
            }
        }
    }
    return retorno;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

nodoListaGeneros* enlistarGeneros(nodoListaGeneros* lista, nodoListaGeneros* nuevo)
{
    if(!lista)
    {
        lista = nuevo;
    }
    else
    {
        nuevo->siguiente = lista;
        lista = nuevo;
    }

    return lista;
}

nodoListaGeneros* crearNodoGenero(char genero[])
{
    nodoListaGeneros* nuevo = (nodoListaGeneros*) malloc(sizeof(nodoListaGeneros));

    strcpy(nuevo->genero, genero);
    nuevo->listaJuegos = inicStruct();
    nuevo->siguiente = NULL;

    return nuevo;
}

int buscarGenero(nodoListaGeneros* lista, char genero[])
{
    nodoListaGeneros* seg = lista;
    int flag = 0;

    while(flag == 0 && seg != NULL)
    {
        if(strcmpi(seg->genero, genero) == 0)
        {
            flag = 1;
        }

        seg = seg->siguiente;
    }

    return flag;
}

void* inicStruct()
{
    return NULL;
}

nodoJuego* enlistarJuego(nodoJuego* lista, int id)
{
    nodoJuego* nuevo = (nodoJuego*) malloc(sizeof(nodoJuego));

    nuevo->IdJuego = id;
    nuevo->siguiente = NULL;

    if(!lista)
    {
        lista = nuevo;
    }
    else
    {
        nuevo->siguiente = lista;
        lista = nuevo;
    }

    return lista;
}

nodoListaGeneros* pasarArchiLista(nodoBiblioteca* arbol, nodoListaGeneros* lista)
{
    FILE* archi = fopen(nombreArchiJuegos, "rb");
    registroJuego aux;
    nodoListaGeneros* seg;

    if(archi)
    {
        while(fread(&aux, sizeof(registroJuego), 1, archi) > 0)
        {
            if(buscarGenero(lista, aux.genero) == 0)
            {
                lista = enlistarGeneros(lista, crearNodoGenero(aux.genero));
            }

            seg = lista;

            while(strcmp(seg->genero, aux.genero) != 0)
            {
                seg = seg->siguiente;
            }

            if(seg!=NULL)
            {
                seg->listaJuegos = enlistarJuego(seg->listaJuegos, aux.idJuego);
            }
            else
            {
                printf("Error\n");
            }

        }

        fclose(archi);
    }

    return lista;
}

void mostrarListaGeneros(nodoListaGeneros* listaGeneros, nodoBiblioteca* arbol)
{
    nodoJuego* seg2;
    nodoListaGeneros* seg = listaGeneros;

    while(seg != NULL)
    {
        printf("\n%s:\n", seg->genero);

        seg2 = seg->listaJuegos;

        while(seg2 != NULL)
        {
            MostrarJuegoUsuario(buscarPorId(arbol, seg2->IdJuego));
            seg2 = seg2->siguiente;
        }

        seg = seg->siguiente;
    }
}

void mostrarListaGenero(nodoListaGeneros* listaGeneros, nodoBiblioteca* arbol, char genero[])
{
    nodoListaGeneros* seg = listaGeneros;
    nodoJuego* seg2;

    int flag = 0;

    while(flag == 0 && seg != NULL)
    {
        if(strcmpi(seg->genero, genero) == 0)
        {
            flag = 1;
            seg2 = seg->listaJuegos;
        }
        else
        {
            seg = seg->siguiente;
        }

    }

    if(flag == 1)
    {
        while(seg2 != NULL)
        {
            MostrarJuegoUsuario(buscarPorId(arbol, seg2->IdJuego));
            seg2 = seg2->siguiente;
        }
    }
}
