#ifndef INICIO_H_INCLUDED
#define INICIO_H_INCLUDED

#include "balanceArboles.h"
#include "ProyectoFinal.h"

enum Colors { // Listado de colores (La letra "L" al inicio, indica que es un color m?s claro).
     BLACK = 0,
     BLUE = 1,
     GREEN = 2,
     CYAN = 3,
     RED = 4,
     MAGENTA = 5,
     BROWN = 6,
     LGREY = 7,
     DGREY = 8,
     LBLUE = 9,
     LGREEN = 10,
     LCYAN = 11,
     LRED = 12,
     LMAGENTA = 13,
     YELLOW = 14,
     WHITE = 15
};

void imagen1(int i, int x);
void Color(int Background, int Text);
void imagen2(int i, int x);
void inicio();
int inicioSesion();
void menuAdmin(nodoBiblioteca* arbol, nodoListaGeneros* listaGeneros, char archiUser[]);
void menuUser(nodoBiblioteca* arbol, nodoListaGeneros* listaGeneros, int id, char archiUser[], Fila* filaJuegos);

#endif // INICIO_H_INCLUDED
