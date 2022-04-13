#ifndef PROYECTOFINAL_H_INCLUDED
#define PROYECTOFINAL_H_INCLUDED

#define nombreArchiJuegos "juegos.dat"
#define nombreApp "estim"
#define nombreArchiUsuarios "Usuarios.dat"

#define Accion "Accion"
#define Simulacion "Simulacion"
#define Deportes "Deportes"
#define Supervivencia "Supervivencia"
#define Estrategia "Estrategia"
#define Otro "Otro"

#define ContraseniaAdmin "Admin123"
#define CodigoSeguridad "Estim123"


////////////////////////////////////////////////

typedef struct
{
    int idJuego;
    char nombre[30];
    char genero[20];
    char subgeneros[20];
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
    char NumCelular[10];
    int Monedero;
    int ListaDeseados[100];
    int validosDeseados;
    int carrito[100];
    int validosCarrito;
    int Adquiridos[100];
    int validosAdquiridos;
    int EstadoUsuario;
    int Admin;   /// Si es 0 es porque no es un usuario admin, devuelve 1 si lo es.

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

///////////////////////////////////////

typedef struct
{
    int IdJuego;
    struct nodoDoble* siguiente;
    struct nodoDoble* anterior;

}nodoDoble;

typedef struct
{
    nodoDoble* inicio;
    nodoDoble* fin;
}Fila;

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
stCliente RegistrarCliente (int* id);
void MostrarXIdJuego (nodoJuego* lista, nodoBiblioteca* arbol);
registroJuego BuscarEnArbol (int idaBucar, nodoBiblioteca* arbol);
void MostrarClientesArchi (char archivo[]);
int comprobarMail (char archivo[], char NuevoMail[]);
int comprobarNumero (char archivo[], char NuevoNumero[]);
int comprobarContrasenia (char NuevaContra[]);
int ValidarInicio (char archivo [], char mail[], char contrasenia[], int* id);
int iniciarSesion(char archivo[], int* id);
int Registrase (char archivo[]);
stCliente ModificarNombre (char archivo[], int idCliente);
stCliente AgregarSaldo (char archivo[], int idCliente);
stCliente ModificarMail (char archivo[], int idCliente);
stCliente ModificarContra (char archivo[], int idCliente);
stCliente ModificarNumero (char archivo[], int idCliente);
stCliente DardeBaja (char archivo[], int idCliente);
stCliente DardeAlta (char archivo[], int idCliente);
void ModificarCamposUsuario (char archivo[], int id);
stCliente BuscarUsuario (char archivo[], int idCliente);
stCliente AgregarListaDeseados (char archivo[], int idCliente, int idJuego, nodoBiblioteca* arbol);
stCliente AgregarCarrito (char archivo[], int idCliente, int idJuego, nodoBiblioteca* arbol);
int existeJuego(nodoBiblioteca* arbol, int id);
int buscarEnArreglo(int arreglo[], int validos, int buscado);
void borrarArreglo(int arreglo[], int* validos, int aBorrar);
void mostrarArregloJuegosAdmin(int arreglo[], int val, nodoBiblioteca* arbol);
void mostrarArregloJuegosUser(int arreglo[], int val, nodoBiblioteca* arbol);
void ActualizarUsuario ( char archivo[], stCliente cliente);
void MostrarUsuario (stCliente dato);
void MostrarCarritoUsuario (registroJuego dato);
void mostrarArregloCarrito(int arreglo[], int val, nodoBiblioteca* arbol);
Fila inicFila();
nodoDoble* crearNodoDoble (int id);
nodoDoble* buscarUltimo (nodoDoble* lista);
nodoDoble* agregarAlFInal (nodoDoble* lista, nodoDoble* nuevo);
void agregaAfila (Fila* filita, int id);
void pasarJuegosFila(Fila* fila, nodoBiblioteca* arbol);
int extraerFila(Fila* fila);
int verPimero (nodoDoble* lista);
void mostrarNodoDoble (nodoDoble* lista);
stCliente Comprar (char archivo[], int idCliente, int idJuego, nodoBiblioteca* arbol, char archivoJuego[]);
void CambiarEstadoJuego (char archivo[], int idJuego);


////////////////////////////////////////////////

#endif // PROYECTOFINAL_H_INCLUDED
