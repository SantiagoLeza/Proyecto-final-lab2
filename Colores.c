#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void Color(int Background, int Text){ // Función para cambiar el color del fondo y/o pantalla

     HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.

     int New_Color= Text + (Background * 16);

     SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.

}
