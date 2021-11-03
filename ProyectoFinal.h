#ifndef PROYECTOFINAL_H_INCLUDED
#define PROYECTOFINAL_H_INCLUDED

#define nombreArchiJuegos "juegos.dat"
#define nombreApp "estim"

#define Accion "Accion"
#define Simulacion "Simulacion"
#define Deportes "Deportes"
#define Supervivencia "Supervivencia"
#define Estrategia "Estrategia"
#define Otro "Otro"


////////////////////////////////////////////////

typedef struct
{
    int idJuego;
    char nombre[30];
    char genero[20];
    int precio;
    int valoracion;
    int cantVentas;
    int estado;

}registroJuego;

typedef struct
{
    registroJuego dato;
    struct nodoLista *sig;
}nodoLista;

////////////////////////////////////////////////

void cargarJuegosAlArchivo(char archivo[]);
registroJuego crearRegistro();
int cantJuegosArchi(char archivo[]);

////////////////////////////////////////////////

#endif // PROYECTOFINAL_H_INCLUDED
