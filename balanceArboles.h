#ifndef BALANCEARBOLES_H_INCLUDED
#define BALANCEARBOLES_H_INCLUDED

#include "ProyectoFinal.h"

////////////////////////////////////////////////////////////////////////////

typedef struct
{
    char genero[20];
    nodoJuego* listaJuegos;
    struct nodoListaGeneros* siguiente;

}nodoListaGeneros;

////////////////////////////////////////////////////////////////////////////

nodoBiblioteca* enlistarNodo(nodoBiblioteca* arbol, nodoBiblioteca* nuevo);
void mostrarArbolPreOrden(nodoBiblioteca* arbol);
void mostrarArbolInOrden(nodoBiblioteca* arbol);
int cantNodos(nodoBiblioteca* arbol);
nodoBiblioteca* desplazarDerecha(nodoBiblioteca* arbol);
nodoBiblioteca* desplazarIzquierda(nodoBiblioteca* arbol);
nodoBiblioteca* masDerecha(nodoBiblioteca* arbol);
nodoBiblioteca* masIzquierda(nodoBiblioteca* arbol);
nodoBiblioteca* borrarNodo(nodoBiblioteca* arbol, int aBorrar);
nodoBiblioteca* balancearArbol(nodoBiblioteca* arbol);
nodoBiblioteca* pasarArchivoArbol(char archivo[], nodoBiblioteca* arbol);
void mostrarArchivoJuegos(char archivo[]);
void sumarVenta(char Archivo[], int idJuego);
registroJuego buscarPorId(nodoBiblioteca* arbol, int id);
registroJuego buscarPorNombre(nodoBiblioteca* arbol, char nombre[]);
int buscarGenero(nodoListaGeneros* lista, char genero[]);
nodoListaGeneros* enlistarGeneros(nodoListaGeneros* lista, nodoListaGeneros* nuevo);
nodoListaGeneros* crearNodoGenero(char genero[]);
nodoListaGeneros* pasarArchiLista(nodoBiblioteca* arbol, nodoListaGeneros* lista);
void* inicStruct();
nodoJuego* enlistarJuego(nodoJuego* lista, int id);
void mostrarListaGeneros(nodoListaGeneros* listaGeneros, nodoBiblioteca* arbol);
void mostrarListaGenero(nodoListaGeneros* listaGeneros, nodoBiblioteca* arbol, char genero[]);

////////////////////////////////////////////////////////////////////////////

#endif // BALANCEARBOLES_H_INCLUDED
