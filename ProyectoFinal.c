#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "ProyectoFinal.h"
#include "balanceArboles.h"

/////////////////////////////////////////////////////////////////

void cargarJuegosAlArchivo(char archivo[])
{
    int retorno = 0;

    int id = cantClientesArchi(archivo)+1;

    FILE *archi = fopen(archivo, "a");

    if(archi)
    {
        registroJuego dato;

        do
        {
            dato = crearRegistro(&id);
            fwrite(&dato, sizeof(registroJuego), 1, archi);

            retorno = MessageBox(NULL, "Desea cargar otro?", "Aviso", MB_OKCANCEL);
        }
        while(retorno != IDCANCEL);

        fclose(archi);
    }
}

registroJuego crearRegistro(int *id)
{
    registroJuego dato;

    dato.idJuego = *id;
    *id = *id + 1;

    printf("\n Ingrese el nombre del juego: ");
    fflush(stdin);
    gets(dato.nombre);

    int i;

    int check;

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
                strcpy(dato.subgeneros, Accion); //utilizo macros para poder utilizar los string exactamente igual mas adelnate
                break;

            case 2:
                strcpy(dato.subgeneros, Simulacion);
                break;

            case 3:
                strcpy(dato.subgeneros, Deportes);
                break;

            case 4:
                strcpy(dato.subgeneros, Supervivencia);
                break;

            case 5:
                strcpy(dato.subgeneros, Estrategia);
                break;

            case 6:
                strcpy(dato.subgeneros, Otro);
                break;


            default:
                MessageBox(NULL, "Opcion no valida, intente nuevamente", "ERROR", MB_OK | MB_ICONERROR);
                check = 0;
                break;
        }

    }
    while(check == 0);


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

    FILE *archi3 = fopen(archivo, "rb");
    if(archi3)
    {
        fseek(archi3, 0, SEEK_END);

        i = ftell(archi3) / sizeof(registroJuego);

        fclose(archi3);
    }
    else
    {
        MessageBox(NULL, "Error de archivos.", "ERROR", MB_OK | MB_ICONERROR);
    }

    return i;
}



///////////////////////////////////////////////////////////

                        ///Funcion mostrar

///////////////////////////////////////////////////////////

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

    printf("\n Subgenero: %s", dato.subgeneros);

    printf(" \n Precio: %i", dato.precio);

    printf(" \n Valoracion: %i", dato.valoracion);

    printf(" \n Cantidad de ventas: %i", dato.cantVentas);

    printf(" \n Estado: [%i]", dato.estado);

}

void MostrarJuegoUsuario (registroJuego dato)
{
    int i=0;

    if(dato.estado == 1)
    {
        printf("\n\n--------------------------------- ");

        printf(" \n |Nombre: %s", dato.nombre);

        printf(" \n |Genero principal: %s", dato.genero);

        printf("\n |Subgenero: %s", dato.subgeneros);

        printf(" \n |Precio: %i", dato.precio);

        printf(" \n |Valoracion: %i", dato.valoracion);

        printf("\n--------------------------------- \n");
    }

}

void MostrarCarritoUsuario (registroJuego dato)
{
    int i=0;

    if(dato.estado == 1)
    {
        printf("\n\n--------------------------------- ");

        printf(" \n |Numero: %d", dato.idJuego);

        printf(" \n |Nombre: %s", dato.nombre);

        printf(" \n |Genero principal: %s", dato.genero);

        printf("\n |Subgenero: %s", dato.subgeneros);

        printf(" \n |Precio: %i", dato.precio);

        printf(" \n |Valoracion: %i", dato.valoracion);

        printf("\n--------------------------------- \n");
    }

}

///////////////////////////////////////////////////////////

                        ///Funciones Nodo Juegos

///////////////////////////////////////////////////////////

nodoLista* inicNodo()
{
    return NULL;
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

///////////////////////////////////////////////////////////

                        ///Funciones cliente

///////////////////////////////////////////////////////////


stCliente RegistrarCliente (int* id)
{
    stCliente aux;
    int flag= 0;
    char contra1[10];
    char contra2[10];
    char codSeguridad[10];
    int comp=0;
    int password=0;
    int num=0;

    aux.IDCliente = *id;
    *id= *id+1;

    printf("\n Ingrese nombre y apellido: ");
    fflush(stdin);
    gets(aux.NombreyApellido);


    do{
        printf("\n Ingrese su mail: ");
        fflush(stdin);
        gets(aux.Mail);
        comp= comprobarMail(nombreArchiUsuarios, aux.Mail);     /// Comprueba que el email no este resgistrafo: 1= esta registrado 0= email sin registrar
        if (comp==1)
        {
            printf("\n El mail que desea ingresar ya esta registrado.");
        }
    }while ( comp == 1 );


///////////////////////////////////////////////////////////////////////////////////////////////////
    while (flag==0)
    {

            do{                                                     /////////////////////
            printf("\n Ingrese su contraenia (no mas de 10 digitos): ");
            fflush(stdin);
            gets(contra1);
            password= comprobarContrasenia(contra1);
            if (password == -1)
            {
                printf("\n Ingrese el codigo de seguridad: ");
                fflush(stdin);
                gets(codSeguridad);

                if (strcmp(codSeguridad, CodigoSeguridad) == 0)
                {
                    password=2;
                    flag=1;
                    printf("\n El codigo es correcto.");
                }
                else
                {
                    printf("\nEl codigo es incorrecto, debera ingresar los datos nuevamente.");
                    password=0;
                }

            }

            } while (password==0);

        if ( password != 2){

    if (strlen(contra1) > 10)   /// strlen cuenta la cantidad de caracteres.

        {
            printf("\n Error (exceso de caracteres).");
        }

    else if (strlen(contra1) == 0)

        {
            printf("\n No se registro ningun caracter.");
        }
    else

        {
            printf("\n Ingrese nuevamente su contraenia: ");
            fflush(stdin);
            gets(contra2);

            while (strcmp(contra1, contra2) != 0)
            {
                printf("\n No coincide. ");
                printf("\n Ingrese nuevamente su contraenia: ");    ///Comprueba si contra1 es = contra2
                fflush(stdin);
                gets(contra2);

            }

            flag=1;

        }
    }
    }

    strcpy(aux.Contra, contra1);  /// copia la contra ingresada a la estructura.

    /////////////////////////////////////////////////////////////////////////////

    do{
    printf("\n Ingrese su numero de celular: ");
    fflush(stdin);
    gets(aux.NumCelular);
    num= comprobarNumero(nombreArchiUsuarios, aux.NumCelular);
    if ( num == 1 )
    {
        printf("\n El numero ingresado esta registrado en la base de datos.");      ///Comprueba el num de telefono
    }
    else if (strlen(aux.NumCelular) > 10)
    {
        printf("\n El numero de celular ingresado es incorrecto. ");
    }
    }while ( (num == 1) || (strlen(aux.NumCelular) > 10) );
    /////////////////////////////////////////////////////////////////////////////


    aux.Monedero=0;
    aux.validosAdquiridos = 0;
    aux.validosCarrito = 0;
    aux.validosDeseados = 0;

    aux.EstadoUsuario= 1;

    if ( password == 1 )
    {
        aux.Admin= 0;
    }
    else if ( password== 2 )
    {
        aux.Admin= 1;
    }



    return aux;
}

void MostrarUsuario (stCliente dato)
{
    printf("\n-------------------------");

    printf(" \n |ID: %i", dato.IDCliente);
    printf(" \n |Nombre: %s", dato.NombreyApellido);
    printf(" \n |Mail: %s", dato.Mail);
    printf(" \n |Contrasenia: %s", dato.Contra);
    printf(" \n |Celular: %s", dato.NumCelular);
    printf(" \n |Monedero: %i", dato.Monedero);

    if ( dato.EstadoUsuario ==1 )
    {
        printf(" \n |Estado: [activo]\n");
    }
    else if ( dato.EstadoUsuario == 2 )
    {
        printf(" \n |Estado: [Admin]\n");
    }
    else
    {
        printf(" \n |Estado: [inactivo]\n");
    }

    printf("--------------------------\n");
}

void MostrarXIdJuego (nodoJuego* lista, nodoBiblioteca* arbol)
{
    nodoJuego* seguidora= lista;

    while ( seguidora != NULL )
    {
        MostrarJuegoUsuario(BuscarEnArbol(seguidora->IdJuego, arbol));
        seguidora= seguidora->siguiente;
    }
}

registroJuego BuscarEnArbol (int idaBucar, nodoBiblioteca* arbol)   /// retorna un struct con todos los datos del juego que coincidan con el id
{                                                                   /// pasado x parametro (que sale de la lista del usuario)
    registroJuego aRetornar;

    if ( arbol != NULL )
    {

        if ( arbol->dato.idJuego == idaBucar )
        {
            arbol->dato= aRetornar;
        }
        else if ( arbol->dato.idJuego < idaBucar )
        {
            aRetornar= BuscarEnArbol(idaBucar, arbol->der);
        }
        else if ( arbol->dato.idJuego > idaBucar )
        {
            aRetornar= BuscarEnArbol(idaBucar, arbol->izq);
        }

    }

    return aRetornar;
}


int cantClientesArchi(char archivo[])
{
    int i = 0;

    FILE *archi2 = fopen(archivo, "rb");
    if(archi2)
    {
        fseek(archi2, 0, SEEK_END);

        i = ftell(archi2) / sizeof(stCliente);

        fclose(archi2);
    }
    else
    {
        MessageBox(NULL, "Error de archivos.", "ERROR", MB_OK | MB_ICONERROR);
    }

    return i;
}

void cargarClientesAlArchivo(char archivo[])
{
    int retorno = 0;

    FILE *archi = fopen(archivo, "ab");

    int id= cantClientesArchi(nombreArchiUsuarios);

    if(archi)
    {
        stCliente dato;

        do
        {
            printf("\n---------------------");
            dato = RegistrarCliente(&id);
            fwrite(&dato, sizeof(stCliente), 1, archi);

            retorno = MessageBox(NULL, "Desea cargar otro?", "Aviso", MB_OKCANCEL);
        }
        while(retorno != IDCANCEL);

        fclose(archi);
    }
    else
    {
        printf("\n Error.");
    }


}

void MostrarClientesArchi (char archivo[])
{
    FILE *archi= fopen(archivo, "rb");
    stCliente aux;

    if (archi)
    {
        while (fread(&aux, sizeof(stCliente), 1, archi) > 0)
        {
            MostrarUsuario(aux);
        }

        fclose(archi);
    }
    else
    {
        printf("\n Error");
    }
}

int comprobarMail (char archivo[], char NuevoMail[])
{
    FILE *archi= fopen(archivo, "rb");
    stCliente aux;
    int flag=0;

    if (archi)
    {
        while ( (flag==0) && ((fread(&aux, sizeof(stCliente), 1, archi))>0))
        {
            if ( strcmp(aux.Mail, NuevoMail) == 0 )
            {
                flag=1;
            }
        }

        fclose(archi);
    }
    else
    {
        printf("\n Error");
    }

    return flag;
}

int comprobarContrasenia (char NuevaContra[])
{
    int flag=1;

    if ( strcmp( NuevaContra, ContraseniaAdmin )==0 )
    {
        flag= -1;
    }


    return flag;
}

int comprobarNumero (char archivo[], char NuevoNumero[])
{
    FILE *archi= fopen(archivo, "rb");
    stCliente aux;
    int flag=0;

    if (archi)
    {
        while ( (flag==0) && ((fread(&aux, sizeof(stCliente), 1, archi))>0))
        {
            if ( strcmp(aux.NumCelular, NuevoNumero) == 0 )
            {
                flag=1;
            }
        }

        fclose(archi);
    }
    else
    {
        printf("\n Error");
    }

    return flag;
}

int ValidarInicio (char archivo [], char mail[], char contrasenia[], int* id)
{
    int flag=0;
    int rta=0;
    stCliente usuario;

    FILE* archi= fopen(archivo, "rb");

    if (archi)
    {
         while ( (flag==0) && ((fread(&usuario, sizeof(stCliente), 1, archi))>0))
        {
            if ( strcmp(usuario.Mail, mail) == 0 )
            {
                if ( strcmp(usuario.Contra, contrasenia) == 0)
                {
                   rta=1;
                   *id= usuario.IDCliente;
                }
                else
                {
                    rta=2; /// no encontro la contrasenia
                }

                flag= 1;
            }
        }

        if (usuario.EstadoUsuario==0)
        {
            printf("\n Su usuario esta dadod de baja.");
            DardeAlta(archivo, *id);

        }

        fclose(archi);
    }
    else
    {
        printf("\n Error");
    }

    return rta; /// 1=  si encontro la contrasenia (usuario normal) 2= no encontro la contrasenia

}


int iniciarSesion(char archivo[], int* id)
{
    int flag=0;
    int ctrl;
    int check=0;
    char continuar= 's';
    int intentos=2;


    char mail[50];
    char contra[50];

    puts("\n------------------------------------------------------");

    do {
    printf("\nIngrese el mail de su cuenta: ");
    fflush(stdin);
    gets(mail);
    check= comprobarMail(archivo, mail);
    if (check==0)
    {
        printf("\n El mail no se encuentra en la base de datos.");
        printf("\n\n Si desea intentarlo nuevamente ingrese [S], de lo contrario [N]: ");
        fflush(stdin);
        scanf("%c", &continuar);
    }
    }while (check==0 && continuar=='s');

    if ( continuar == 's' )
    {
        do {
        printf("\n Ingrese la contrasenia: ");
        fflush(stdin);
        gets(contra);

        ctrl = ValidarInicio(archivo, mail, contra, id);

        if (ctrl == 1)
        {
            flag=1;
            printf("\n Inicio de sesion exitoso");
        }
        else if (ctrl == 2 )
        {
            flag=2;
            printf("La contrasenia incorrecta, vuelva a intentarlo. (Le queda un intento)\n");
            intentos= intentos-1;

        }
        }while (ctrl == 2 && intentos>0);

    }

    return flag;
}


int Registrase (char archivo[])
{

    int id= cantClientesArchi(nombreArchiUsuarios);

    FILE *archi = fopen(archivo, "a+b");

    if(archi)
    {
        stCliente dato;

        system("start https://docs.google.com/document/d/1oyUKWbZQljrkTZItuK2YUaYBZ48Bq0WXezFx8j27Vfw/edit?usp=sharing");

        if(MessageBox(NULL, "Acepte los terminos y condiciones", "Aviso", MB_OKCANCEL) != IDCANCEL)
        {
            printf("\n---------------------");
            dato = RegistrarCliente(&id);
            fwrite(&dato, sizeof(stCliente), 1, archi);
        }



        fclose(archi);
    }
    else
    {
        printf("\n Error.");
    }

    return id;
}



///\////////////////////////////////////////////////////////


            /// Funciones de modificacion cliente ///


///\///////////////////////////////////////////////////////

stCliente AgregarSaldo (char archivo[], int idCliente)
{
    int monto=0;
    stCliente usuario;
    int flag=0;

    FILE* archi= fopen(archivo, "r+b");

    if (archi)
    {

        while ((flag==0) && (fread(&usuario, sizeof(stCliente),1,archi) > 0))
        {
            if (idCliente == usuario.IDCliente)
            {
                flag=1;
            }
        }

        if ( flag ==1 )
        {
            printf("\n Ingrese el monto que desea ingresar a su monedero: ");
            scanf("%i", &monto);
            usuario.Monedero+= monto;

        }

        fclose(archi);
    }
    else
    {
        printf("\n Hubo un error.");
    }

    return usuario;
}

stCliente ModificarNombre (char archivo[], int idCliente)
{
    char NuevoNombre [30];
    stCliente usuario;
    int flag=0;

    FILE* archi= fopen(archivo, "r+b");

    if (archi)
    {

        while ((flag==0) && (fread(&usuario, sizeof(stCliente),1,archi) > 0))
        {
            if (idCliente == usuario.IDCliente)
            {
                flag=1;
            }
        }

        if ( flag ==1 )
        {
            printf("\n Ingrese su nuevo nombre y apellido:  ");
            fflush(stdin);
            gets(NuevoNombre);

            strcpy(usuario.NombreyApellido, NuevoNombre);


        }

        fclose(archi);
    }
    else
    {
        printf("\n Hubo un error.");
    }

    return usuario;
}


stCliente ModificarMail (char archivo[], int idCliente)
{
    char NuevoMail [30];
    stCliente usuario;
    int flag=0;
    int comprobacion=0;

    FILE* archi= fopen(archivo, "r+b");

    if (archi)
    {

        while ((flag==0) && (fread(&usuario, sizeof(stCliente),1,archi) > 0))
        {
            if (idCliente == usuario.IDCliente)
            {
                flag=1;
            }
        }

        if ( flag ==1 )
        {
            do{
            printf("\n Ingrese su nuevo mail:  ");
            fflush(stdin);
            gets(NuevoMail);
            comprobacion= comprobarMail(archivo, NuevoMail);
            if (comprobacion==1)
            {
                printf(" El mail que desea ingresar ya esta ocupado.\n");
            }
            }while (comprobacion == 1 );

            strcpy(usuario.Mail, NuevoMail);


        }
        fclose(archi);
    }
    else
    {
        printf("\n Hubo un error.");
    }

    return usuario;
}

stCliente ModificarContra (char archivo[], int idCliente)
{
    char NuevaContra [30];
    char NuevaContra2  [30];
    stCliente usuario;
    int flag=0;
    int comprobacion=0;

    FILE* archi= fopen(archivo, "r+b");

    if (archi)
    {

        while ((flag==0) && (fread(&usuario, sizeof(stCliente),1,archi) > 0))
        {
            if (idCliente == usuario.IDCliente)
            {
                flag=1;
            }
        }

        if ( flag ==1 )
        {
            do{
            printf("\n Ingrese su nueva contraenia (no mas de 10 digitos): ");
            fflush(stdin);
            gets(NuevaContra);
            if (strlen(NuevaContra) > 10)   /// strlen cuenta la cantidad de caracteres.
            {
                printf("\n Error (exceso de caracteres).");
                comprobacion=1;
            }
            else if (strlen(NuevaContra) == 0)
            {
                printf("\n No se registro ningun caracter.");
                comprobacion=1;
            }
            else
            {
                comprobacion=0;
            }
            } while (comprobacion==1);

                printf("\n Ingrese nuevamente su contraenia: ");
                fflush(stdin);
                gets(NuevaContra2);

            while (strcmp(NuevaContra, NuevaContra2) != 0)
            {
                printf("\n No coincide. ");
                printf("\n Ingrese nuevamente su contraenia: ");    ///Comprueba si contra1 es = contra2
                fflush(stdin);
                gets(NuevaContra2);
            }

            strcpy(usuario.Contra, NuevaContra);

            }

            fclose(archi);
        }


    else
    {
        printf("\n Hubo un error.");
    }

    return usuario;
}


stCliente ModificarNumero (char archivo[], int idCliente)
{
    char NuevoNumero [30];
    stCliente usuario;
    int flag=0;
    int comprobacion=0;

    FILE* archi= fopen(archivo, "r+b");

    if (archi)
    {

        while ((flag==0) && (fread(&usuario, sizeof(stCliente),1,archi) > 0))
        {
            if (idCliente == usuario.IDCliente)
            {
                flag=1;
            }
        }

        if ( flag ==1 )
        {
            do{
            printf("\n Ingrese su nuevo numero:  ");
            fflush(stdin);
            gets(NuevoNumero);
            comprobacion= comprobarNumero(archivo, NuevoNumero);
            if (comprobacion==1)
            {
                printf(" El numero que desea ingresar ya esta ocupado.\n");
            }
            }while (comprobacion == 1 );

            strcpy(usuario.NumCelular, NuevoNumero);

        }
        fclose(archi);
    }
    else
    {
        printf("\n Hubo un error.");
    }

    return usuario;
}


stCliente DardeBaja (char archivo[], int idCliente)
{

    stCliente usuario;
    int flag=0;
    char estad;


    FILE* archi= fopen(archivo, "r+b");

    if (archi)
    {

        while ((flag==0) && (fread(&usuario, sizeof(stCliente),1,archi) > 0))
        {
            if (idCliente == usuario.IDCliente)
            {
                flag=1;
            }
        }

        if ( flag ==1 )
        {
            printf("\n Desea darse de baja? s/N ");
            fflush(stdin);
            scanf("%c", &estad);
            if ( estad == 's' )
            {
                usuario.EstadoUsuario= 0;

                printf("\n Usuario dado de baja con exito.");

            }
            else
            {
                printf("\n Usuario no ha sido dado de baja.");
            }
        }

        fclose(archi);
    }
    else
    {
        printf("\n Hubo un error.");
    }

    return usuario;
}

stCliente DardeAlta (char archivo[], int idCliente)
{

    stCliente usuario;
    int flag=0;
    char estad;


    FILE* archi= fopen(archivo, "r+b");

    if (archi)
    {

        while (flag==0 && fread(&usuario, sizeof(stCliente),1,archi) > 0)
        {
            if (idCliente == usuario.IDCliente)
            {
                flag=1;
            }
        }

        if ( flag == 1 )
        {
            printf("\n Desea activar la cuenta nuevamente? s/N: ");
            fflush(stdin);
            scanf("%c", &estad);

            if ( estad == 's' )
            {
                usuario.EstadoUsuario= 1;

                printf("\n La cuenta se ha activado con exito.");
            }
            else
            {
                printf("\n La cuenta no ha sido activada.");
            }

            fseek(archi, sizeof(stCliente)*-1, SEEK_CUR);
            fwrite(&usuario, sizeof(stCliente), 1, archi);
        }
        else
        {
            printf("Usuario no encontrado\n");
            system("pause");
        }

        fclose(archi);
    }
    else
    {
        printf("\n Hubo un error.");
    }

    return usuario;
}

void ModificarCamposUsuario (char archivo[], int id)
{

    stCliente usuario;
    int flag=0;
    int campo;


    FILE* archi= fopen(archivo, "r+b");

    if (archi)
    {

        while ((flag==0) && (fread(&usuario, sizeof(stCliente),1,archi) > 0))
        {
            if (id == usuario.IDCliente)
            {
                flag=1;
            }
        }

        if (flag==1){

            printf("\n Ingrese el campo que desee modificar: \n");
            printf("\n 1-Nombre y apellido\n 2-Mail\n 3-Contrasenia\n 4-Numero\n 5-Dar de baja\n 6-Agregar saldo ");
            scanf("%i", &campo);

            switch (campo)
            {

            case 1:
               usuario= ModificarNombre(archivo, id);
                break;

            case 2:
               usuario= ModificarMail(archivo, id);
                break;

            case 3:
               usuario= ModificarContra(archivo, id);
                break;

            case 4:
               usuario= ModificarNumero(archivo, id);
               break;

            case 5:
               usuario= DardeBaja(archivo, id);
               break;

            case 6:
                usuario= AgregarSaldo(archivo, id);
                break;

            }

            fseek(archi, sizeof(stCliente)*-1, SEEK_CUR);
            fwrite(&usuario, sizeof(stCliente), 1, archi);
        }

        fclose(archi);

    }
    else
    {
        printf("\n Error.");
    }
}

stCliente BuscarUsuario (char archivo[], int idCliente)
{
    stCliente usuario;
    int flag=0;

    FILE* archi= fopen(archivo, "r+b");

    if (archi)
    {

        while ((flag==0) && (fread(&usuario, sizeof(stCliente),1,archi) > 0))
        {
            if (idCliente == usuario.IDCliente)
            {
                flag=1;
            }
        }

        if ( flag== 0)
        {
            usuario.IDCliente= -1;
        }

        fclose(archi);

    }
    else
    {
        printf("\n Error.");
    }

    return usuario;

}


///////////////////////////////////////////////////////////

                        ///Funciones arbol

///////////////////////////////////////////////////////////




nodoBiblioteca* inicArbol ()
{
    return NULL;
}


nodoBiblioteca* CrearNodoArbol (registroJuego datito)
{
    nodoBiblioteca* aux= (nodoBiblioteca*) malloc(sizeof(nodoBiblioteca));

    aux->dato= datito;
    aux->der= NULL;
    aux->izq= NULL;

    return aux;
}

int existeJuego(nodoBiblioteca* arbol, int id)
{
    int flag = 0;

    if(arbol)
    {
        if(arbol->dato.idJuego == id && arbol->dato.estado == 1)
        {
            flag = 1;
        }
        else
        {
            if(id < arbol->dato.idJuego)
            {
                flag = existeJuego(arbol->izq, id);
            }
            else
            {
                flag = existeJuego(arbol->der, id);
            }
        }
    }

    return flag;
}

///////////////////////////////////////////////////////////

                        ///Funciones arreglo

///////////////////////////////////////////////////////////


void mostrarArregloJuegosUser(int arreglo[], int val, nodoBiblioteca* arbol)
{
    int i;
    for(i=0;i<val;i++)
    {
        MostrarJuegoUsuario(buscarPorId(arbol, arreglo[i]));
    }
}

void mostrarArregloCarrito(int arreglo[], int val, nodoBiblioteca* arbol)
{
    int i;
    for(i=0;i<val;i++)
    {
        MostrarCarritoUsuario(buscarPorId(arbol, arreglo[i]));
    }
}

void mostrarArregloJuegosAdmin(int arreglo[], int val, nodoBiblioteca* arbol)
{
    int i;
    for(i=0;i<val;i++)
    {
        MostrarJuegoAdmin(buscarPorId(arbol, arreglo[i]));
    }
}



int buscarEnArreglo(int arreglo[], int validos, int buscado)
{
    int i=0;
    int flag = 0;

    while(flag == 0 && i<validos)
    {
        if(arreglo[i] == buscado)
        {
            flag = 1;
        }
        i++;
    }

    return flag;
}

void borrarArreglo(int arreglo[], int* validos, int aBorrar)
{
    if(buscarEnArreglo(arreglo, *validos, aBorrar) == 1)
    {
        int i=0;
        int flag = 0;

        while(flag == 0 && i<*validos)
        {
            if(arreglo[i] == aBorrar)
            {
                flag = 1;
            }
            else
            {
                i++;
            }

        }

        for(i=i;i<*validos;i++)
        {
            arreglo[i] = arreglo[i+1];
        }

        *validos-=1;
    }
}

stCliente AgregarListaDeseados (char archivo[], int idCliente, int idJuego, nodoBiblioteca* arbol)
{
    stCliente usuario;
    int flag=0;
    registroJuego juego;
    int comprobar=0;

    FILE* archi= fopen(archivo, "r+b");

    if (archi)
    {

            while ((flag==0) && (fread(&usuario, sizeof(stCliente),1,archi) > 0))
            {
                if (idCliente == usuario.IDCliente)
                {
                    flag=1;
                }
            }

            if ( flag == 1)
            {
                comprobar= existeJuego(arbol, idJuego);

                if ( comprobar == 1 )
                {
                    juego= buscarPorId(arbol, idJuego);
                    usuario.ListaDeseados[usuario.validosDeseados]= juego.idJuego;
                    usuario.validosDeseados+= 1;

                    ActualizarUsuario(archivo, usuario);
                }
                else
                {
                    printf("\n El id ingresado no existe.");
                }

            }

            fclose(archi);

    }
    else
    {
        printf("\n Error.");
    }


    return usuario;
}

stCliente AgregarCarrito (char archivo[], int idCliente, int idJuego, nodoBiblioteca* arbol)
{
    stCliente usuario;
    int flag=0;
    registroJuego juego;
    int comprobar= 0;

    FILE* archi= fopen(archivo, "r+b");

    if (archi)
    {

            while ((flag==0) && (fread(&usuario, sizeof(stCliente),1,archi) > 0))
            {
                if (idCliente == usuario.IDCliente)
                {
                    flag=1;
                }
            }

            if ( flag == 1)
            {
                comprobar= existeJuego(arbol, idJuego);

                if ( comprobar == 1 )
                {
                    juego= buscarPorId(arbol, idJuego);

                    usuario.carrito[usuario.validosCarrito]= juego.idJuego;
                    usuario.validosCarrito+= 1;

                    ActualizarUsuario(archivo, usuario);

                }
                else
                {
                    printf("\n El id ingresado no existe.");
                }
            }


            fclose(archi);

    }
    else
    {
        printf("\n Error.");
    }


    return usuario;
}

stCliente Comprar (char archivo[], int idCliente, int idJuego, nodoBiblioteca* arbol, char archivoJuego[])
{
    stCliente usuario;
    int flag=0;
    registroJuego juego;
    int comprobar= 0;

    FILE* archi= fopen(archivo, "r+b");

    if (archi)
    {

            while ((flag==0) && (fread(&usuario, sizeof(stCliente),1,archi) > 0))
            {
                if (idCliente == usuario.IDCliente)
                {
                    flag=1;
                }
            }

            if ( flag == 1)
            {
                    comprobar= existeJuego(arbol, idJuego);

                if ( comprobar == 1 )
                {

                    juego= buscarPorId(arbol, idJuego);

                    if (usuario.Monedero < juego.precio)
                    {
                        printf("\n No puedes adquirir este juego, saldo insuficiente.");
                    }
                    else
                    {
                        borrarArreglo(usuario.ListaDeseados, &usuario.validosDeseados, idJuego);
                        borrarArreglo(usuario.carrito, &usuario.validosCarrito, idJuego);

                        usuario.Monedero -= juego.precio;

                        usuario.Adquiridos[usuario.validosAdquiridos]= juego.idJuego;
                        usuario.validosAdquiridos+= 1;

                        sumarVenta(archivoJuego, juego.idJuego);

                        ActualizarUsuario(archivo, usuario);
                    }
                }
                else
                {
                    printf("\n El id ingresado no existe.");
                }
            }


            fclose(archi);
    }
    else
    {
        printf("\n Error.");
    }


    return usuario;
}

void ActualizarUsuario ( char archivo[], stCliente cliente)
{
    stCliente usuario;
    int flag=0;

    FILE* archi= fopen(archivo, "r+b");

    if (archi)
    {

        while ((flag==0) && (fread(&usuario, sizeof(stCliente),1,archi) > 0))
        {
            if (cliente.IDCliente == usuario.IDCliente)
            {
                flag=1;
            }
        }

        if ( flag== 1)
        {
            usuario= cliente;

            fseek(archi, sizeof(stCliente)*-1, SEEK_CUR);
            fwrite(&usuario, sizeof(stCliente), 1, archi);
        }

        fclose(archi);

    }
    else
    {
        printf("\n Error.");
    }
}

nodoDoble* crearNodoDoble (int id)
{
    nodoDoble* aux= (nodoDoble*) malloc(sizeof(nodoDoble));

    aux->IdJuego= id;
    aux->anterior= NULL;
    aux->siguiente= NULL;

    return aux;
}

Fila inicFila()
{
    Fila fila;

    fila.inicio = inicStruct();
    fila.fin = inicStruct();

    return fila;
}

nodoDoble* buscarUltimo (nodoDoble* lista)
{
    nodoDoble* segui= lista;

    while (segui->siguiente!=NULL)
    {
        segui= segui->siguiente;
    }

    return segui;
}

nodoDoble* agregarAlFInal (nodoDoble* lista, nodoDoble* nuevo)
{
    if (lista==NULL)
    {
        lista= nuevo;
    }
    else
    {
       nodoDoble* ultimo= buscarUltimo(lista);
       ultimo->siguiente= nuevo;
       nuevo->anterior= ultimo;
    }

    return lista;
}

void agregaAfila (Fila* filita, int id)
{
    nodoDoble* nuevo= crearNodoDoble(id);


    if (filita->inicio == NULL)
    {
        filita->inicio= filita->fin;
    }

    filita->fin= nuevo;
    filita->inicio= agregarAlFInal(filita->inicio, nuevo);

}

void pasarJuegosFila(Fila* fila, nodoBiblioteca* arbol)
{
    int i;
    int num;

    for (i=0;i<10;i++)
    {
        do
        {
            num = rand()%cantJuegosArchi(nombreArchiJuegos);
        }
        while(existeJuego(arbol, num) == 0);
        agregaAfila(fila, num);
    }
}

nodoDoble* BorrarPrimero ( nodoDoble* lista )
{
    nodoDoble* aBorrar= lista;

    if (lista!=NULL)
    {
        lista= lista->siguiente;
        if (lista!=NULL)
        {
            lista->anterior= NULL;
        }
        free(aBorrar);

    }

    return lista;
}

int extraerFila (Fila* fila)
{
    int id;

    if (fila->inicio != NULL)
    {
        id= verPimero(fila->inicio);

        fila->inicio= BorrarPrimero(fila->inicio);

        if (fila->inicio == NULL)
        {
            fila->fin= NULL;
        }

    }

    return id;
}

int verPimero (nodoDoble* lista)
{
    int rta= 0;

    if (lista!=NULL)
    {
        rta= lista->IdJuego;
    }

    return rta;
}

void mostrarNodoDoble (nodoDoble* lista)
{
    nodoDoble* seguidora= lista;

    while (seguidora!=NULL)
    {
        printf("\n num= %i", seguidora->IdJuego);
        seguidora= seguidora->siguiente;
    }
}

void CambiarEstadoJuego (char archivo[], int idJuego)
{

    registroJuego juego;
    int flag=0;
    char estad;


    FILE* archi= fopen(archivo, "r+b");

    if (archi)
    {

        while (flag==0 && fread(&juego, sizeof(registroJuego),1,archi) > 0)
        {
            if (idJuego == juego.idJuego)
            {
                flag=1;
            }
        }

        if ( flag == 1 )
        {

            if ( juego.estado == 0 )
            {
                juego.estado= 1;

                printf("\n El juego se ha activado con exito.");
            }
            else
            {
                juego.estado= 0;

                printf("\n El juego se ha dado de baja  con exito.");
            }

            fseek(archi, sizeof(registroJuego)*-1, SEEK_CUR);
            fwrite(&juego, sizeof(registroJuego), 1, archi);
        }
        else
        {
            printf("Juego no encontrado\n");
        }

        fclose(archi);
    }
    else
    {
        printf("\n Hubo un error.");
    }
}
