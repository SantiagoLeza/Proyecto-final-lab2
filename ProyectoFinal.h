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
    struct nodoBiblioteca *der;
    struct nodoBiblioteca *izq;

}nodoBiblioteca;

////////////////////////////////////////////////

void cargarJuegosAlArchivo(char archivo[]);
registroJuego crearRegistro();
int cantJuegosArchi(char archivo[]);
nodoLista* crearNodo (registroJuego dato);
nodoLista* inicNodo();
void MostrarJuegoAdmin (registroJuego dato);
void MostrarJuegoUsuario (registroJuego dato);
void MostrarNodoAdmin (nodoLista* lista);
void MostrarNodoUsuario (nodoLista* lista);
nodoBiblioteca* inicArbol ();
nodoBiblioteca* CrearNodoArbol (registroJuego datito);
void cargarClientesAlArchivo(char archivo[]);
int cantClientesArchi(char archivo[]);
stCliente RegistrarCliente ();

////////////////////////////////////////////////

#endif // PROYECTOFINAL_H_INCLUDED
