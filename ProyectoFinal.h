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
    char subgeneros[2][10];
    int precio;
    int valoracion;
    int cantVentas;
    int estado;

}registroJuego;

///////////////////////////////////////

        ///cliente



typedef struct
{
    int IdJuego;
    struct nodoJuego* siguiente;
}nodoJuego;

typedef struct
{
    int IDCliente;
    char NombreyApellido [30];
    char Mail [30];
    char Contra [10];
    int NumCelular;
    int Monedero;
    nodoJuego* ListaDeseados;
    int EstadoUsuario;

}stCliente;


///////////////////////////////////////


typedef struct
{
    registroJuego dato;
    struct nodoLista *sig;

}nodoLista;

typedef struct
{
    registroJuego dato;
<<<<<<< HEAD
    struct nodoBiblioteca *der;
    struct nodoBiblioteca *izq;

}nodoBiblioteca;
=======
    struct arbolNodo *der;
    struct arbolNodo *izq;

}arbolNodo;
>>>>>>> 00fcf1b0e661c5e0666e09a7a580a9333de74d75

////////////////////////////////////////////////

void cargarJuegosAlArchivo(char archivo[]);
registroJuego crearRegistro();
int cantJuegosArchi(char archivo[]);
nodoLista* crearNodo (registroJuego dato);
<<<<<<< HEAD
nodoLista* inicNodo();
=======
>>>>>>> 00fcf1b0e661c5e0666e09a7a580a9333de74d75
void MostrarJuegoAdmin (registroJuego dato);
void MostrarJuegoUsuario (registroJuego dato);
void MostrarNodoAdmin (nodoLista* lista);
void MostrarNodoUsuario (nodoLista* lista);
<<<<<<< HEAD
nodoBiblioteca* inicArbol ();
nodoBiblioteca* CrearNodoArbol (registroJuego datito);
void cargarClientesAlArchivo(char archivo[]);
int cantClientesArchi(char archivo[]);
stCliente RegistrarCliente ();
=======
>>>>>>> 00fcf1b0e661c5e0666e09a7a580a9333de74d75

////////////////////////////////////////////////

#endif // PROYECTOFINAL_H_INCLUDED
