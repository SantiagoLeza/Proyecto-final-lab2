#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "inicio.h"
#include "gotoxy.h"
#include "ProyectoFinal.h"
#include "balanceArboles.h"

void Color(int Background, int Text){ // Funci�n para cambiar el color del fondo y/o pantalla

     HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.

     int New_Color= Text + (Background * 16);

     SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.

}

void cuadro(int x1, int x2, int y1, int y2)
{
    HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = {0, 0, 100, 25};
    SetConsoleWindowInfo(hndl, 1, &windowSize);

    int i;

    for (i=x1;i<x2;i++){
		gotoxy(i,y1); printf("\304"); //linea horizontal superior
		gotoxy(i,y2); printf("\304"); //linea horizontal inferior
    }

    for (i=y1;i<y2;i++){
		gotoxy(x1,i); printf("\263"); //linea vertical izquierda
		gotoxy(x2,i); printf("\263"); //linea vertical derecha
	}

    gotoxy(x1,y1); printf("\332");
    gotoxy(x1,y2); printf("\300");
    gotoxy(x2,y1); printf("\277");
    gotoxy(x2,y2); printf("\331");

}

void imagen1(int i, int x)
{
     gotoxy(i, x);
     Color(BLACK, LGREEN);
     puts("                                           ,(((((((((((((,                                          ");
     puts("                                     #(((((((((((((((((((((((((#                                    ");
     puts("                                 (((((((((((((((((((((((((((((((((((                                ");
     puts("                              #(((((((((((((((((((((((((((((((((((((((#                             ");
     puts("                            ((((((((((((((((((((((((((((((((((((((((((((/                           ");
     puts("                          (((((((((((((((((((((((((((((((((    /((((((((((#                         ");
     puts("                         ((((((((((((((((((((((((((((((   ./////   *((((((((                        ");
     puts("                       ,(((((((((((((((((((((((((((((*  ///    .//   ((((((((,                      ");
     puts("                       ((((((((((((((((((((((((((((((  ///       //   ((((((((                      ");
     puts("                      ((((((((((((((((((((((((((((/     //*     ///  ((((((((((                     ");
     puts("                      (((((((((((((((((((((((((          .///////   (((((((((((                     ");
     puts("                         (//////////////////                      //(//////////,                    ");
     puts("                               (/////                       //////////*////////.                    ");
     puts("                                        (////(            /////////////////////                     ");
     puts("                                              *(#        /*////////////////////                     ");
     puts("                       **                       ((     ***********************                      ");
     puts("                        *******                 #(    ***********************                       ");
     puts("                         *******    (          #(    ***********************                        ");
     puts("                           ,,,,,,     /(((#((((     ,,,,,,,,,,,,,,,,,,,,,,                          ");
     puts("                             ,,,,,,,              ,,,,,,,,,,,,,,,,,,,,,,                            ");
     puts("                               .,,,,,,,,,    ,,,,,,,,,,,,,,,,,,,,,,,,.                              ");
     puts("                                   .,...........................,.                                  ");
     puts("                                        .....................                                       ");
     Color(BLACK, WHITE);
}

void imagen2(int i, int x)
{

    printf("\n\n\n\n");
    Color(BLACK, LGREEN);
    puts("                     :::::::::: :::::::: ::::::::::: :::::::::::   :::   ::: ");
    puts("                    :+:       :+:    :+:    :+:         :+:      :+:+: :+:+: ");
    puts("                   +:+       +:+           +:+         +:+     +:+ +:+:+ +:+ ");
    puts("                  +#++:++#  +#++:++#++    +#+         +#+     +#+  +:+  +#+  ");
    puts("                 +#+              +#+    +#+         +#+     +#+       +#+   ");
    puts("                #+#       #+#    #+#    #+#         #+#     #+#       #+#    ");
    puts("               ########## ########     ###     ########### ###       ###     ");
    Color(BLACK, WHITE);

    gotoxy(42, 15);
    printf("Loading...");

    gotoxy(35, 16);
    cuadro(30, 60, 16, 18);

    int z;
    int w = 250;

    for (z=31; z<60; z++)
    {
        gotoxy(z, 17);
        printf("%c", 219);
        Sleep(w);
        if(w>25)
        {
            w = w - 25;
        }

    }

    gotoxy(44, 20);
    Color(BLACK, LGREEN);
    puts("DONE");
    Color(BLACK, WHITE);

}

void inicio()
{
    imagen1(3, 1);
    cuadro(2, 98, 0, 25);
    Sleep(1000);

    system("cls");
    imagen2(3, 1);
    cuadro(2, 98, 0, 25);

    gotoxy(27, 22);
    system("pause");
}

int inicioSesion()
{
    int retorno;
    int ctrl = 0;

    printf("\n\n\n\n");
    Color(BLACK, LGREEN);
    puts("                     :::::::::: :::::::: ::::::::::: :::::::::::   :::   ::: ");
    puts("                    :+:       :+:    :+:    :+:         :+:      :+:+: :+:+: ");
    puts("                   +:+       +:+           +:+         +:+     +:+ +:+:+ +:+ ");
    puts("                  +#++:++#  +#++:++#++    +#+         +#+     +#+  +:+  +#+  ");
    puts("                 +#+              +#+    +#+         +#+     +#+       +#+   ");
    puts("                #+#       #+#    #+#    #+#         #+#     #+#       #+#    ");
    puts("               ########## ########     ###     ########### ###       ###     ");
    Color(BLACK, WHITE);

    cuadro(2, 98, 0, 25);
    cuadro(23, 75, 14, 16);

    gotoxy(27, 15); printf("1. Iniciar Sesion.");

    gotoxy(55, 15); printf("2. Registrarse.");

    do
    {
        gotoxy(40, 18); printf("Que desea hacer?: ");
        scanf("%d", &retorno);
        if(retorno == 1 || retorno == 2)
        {
            ctrl = 1;
        }
        else
        {
            gotoxy(58, 18); printf(" ");
            MessageBox(NULL, "Ingrese una opcion valida", "Error", MB_OK);
        }
    }
    while(ctrl == 0);

    return retorno;
}

void menuAdmin(nodoBiblioteca* arbol, nodoListaGeneros* listaGeneros, char archiUser[])
{
menuAdmin:
    system("cls");
    int opcion = 0;
    int genero = 0;

    stCliente user;
    int id;

    printf("\n\n\n\n");
    Color(BLACK, LGREEN);
    puts("                     :::::::::: :::::::: ::::::::::: :::::::::::   :::   ::: ");
    puts("                    :+:       :+:    :+:    :+:         :+:      :+:+: :+:+: ");
    puts("                   +:+       +:+           +:+         +:+     +:+ +:+:+ +:+ ");
    puts("                  +#++:++#  +#++:++#++    +#+         +#+     +#+  +:+  +#+  ");
    puts("                 +#+              +#+    +#+         +#+     +#+       +#+   ");
    puts("                #+#       #+#    #+#    #+#         #+#     #+#       #+#    ");
    puts("               ########## ########     ###     ########### ###       ###     ");
    Color(BLACK, WHITE);

    printf("\n\n\n");
    printf("                       1. Mostrar juegos               2. Buscar por genero   \n\n");
    printf("                       3. Ver usuario por id           4. Ver Lista de usuarios \n\n");
    printf("                       5. Modificar un usuario         6. Agregar un juego  \n\n");
    printf("                       7. Dar alta/baja juego        \n\n");
    printf("\n                             Que desea hacer?                  8. Salir");

    cuadro(1, 100, 1, 25);

    gotoxy(46,23);
    scanf("%d", &opcion);

    switch(opcion)
    {
        case 1:
            system("cls");
            mostrarArchivoJuegos(nombreArchiJuegos);
            system("pause");
            break;

        case 2:
            gotoxy(20, 11);
            printf("\n\n\n");
            printf("                       1. Accion                  2. Simulacion                \n\n");
            printf("                       3. Deportes                4. Supervivencia             \n\n");
            printf("                       5. Estrategia              6. Otro                             \n\n");
            printf("\n\n\n                             Que desea hacer?");

            cuadro(1, 100, 1, 25);

            gotoxy(10, 20); printf("                                                    ");
            gotoxy(50 ,23); printf("                                        ");

            gotoxy(46,23); printf(" ");

            gotoxy(46,23);
            scanf("%d", &genero);

            system("cls");

            switch(genero)
            {
                case 1:
                    mostrarListaGenero(listaGeneros, arbol, Accion);
                    break;

                case 2:
                    mostrarListaGenero(listaGeneros, arbol, Simulacion);
                    break;

                case 3:
                    mostrarListaGenero(listaGeneros, arbol, Deportes);
                    break;

                case 4:
                    mostrarListaGenero(listaGeneros, arbol, Supervivencia);
                    break;

                case 5:
                    mostrarListaGenero(listaGeneros, arbol, Estrategia);
                    break;

                case 6:
                    mostrarListaGenero(listaGeneros, arbol, Otro);
                    break;
            }
            system("pause");
            break;

        case 3:
            system("cls");
            Color(BLACK, RED);
            printf("Ingrese el numero del id a buscar: ");
            scanf("%d", &id);
            user = BuscarUsuario(archiUser, id);
            MostrarUsuario(user);
            Color(BLACK, WHITE);
            system("pause");
            break;

        case 4:
            system("cls");
            MostrarClientesArchi(archiUser);
            system("pause");
            break;

        case 5:
            system("cls");
            printf("Ingrese el numero del id a modificar: ");
            scanf("%d", &id);
            ModificarCamposUsuario(archiUser, id);
            break;

        case 6:
            system("cls");
            cargarJuegosAlArchivo(nombreArchiJuegos);
            system("pause");
            break;

        case 7:
            system("cls");
            printf("Ingrese el id del juego a dar de baja/alta");
            scanf("%d", &id);
            CambiarEstadoJuego(nombreArchiJuegos, id);

            system("pause");
            break;

        case 8:
            return;
    }
    goto menuAdmin;

}

void menuUser(nodoBiblioteca* arbol, nodoListaGeneros* listaGeneros, int id, char archiUser[], Fila* filaJuegos)
{
menuUser:
    system("cls");
    int opcion = 0;
    int genero = 0;
    char ctrl;
    int i;
    int IdAgregar;
    char juegoABuscar[30];
    stCliente user = BuscarUsuario(archiUser, id);

    if(user.EstadoUsuario == 0)
    {
        return;
    }

    printf("\n\n\n\n");
    Color(BLACK, LGREEN);
    puts("                     :::::::::: :::::::: ::::::::::: :::::::::::   :::   ::: ");
    puts("                    :+:       :+:    :+:    :+:         :+:      :+:+: :+:+: ");
    puts("                   +:+       +:+           +:+         +:+     +:+ +:+:+ +:+ ");
    puts("                  +#++:++#  +#++:++#++    +#+         +#+     +#+  +:+  +#+  ");
    puts("                 +#+              +#+    +#+         +#+     +#+       +#+   ");
    puts("                #+#       #+#    #+#    #+#         #+#     #+#       #+#    ");
    puts("               ########## ########     ###     ########### ###       ###     ");
    Color(BLACK, WHITE);

    printf("\n\n\n");
    printf("                       1. Mostrar tienda      2. Buscar por genero   \n\n");
    printf("                       3. Agregar por Id      4. Agregar por nombre   \n\n");
    printf("                       5. Ver mis juegos      6. Ver Lista de deseos \n\n");
    printf("                       7. Ver carrito         8. Opciones de cuenta  \n\n");
    printf("                       9. Ver lista de descubrimientos  \n");
    printf("\n                             Que desea hacer?                  10. Salir");

    cuadro(1, 100, 1, 25);

    gotoxy(46,24);
    scanf("%d", &opcion);



    switch(opcion)
    {
        case 1:
            system("cls");
            mostrarArbolInOrden(arbol);
            system("pause");
            break;

        case 2:
            gotoxy(20, 11);
            printf("\n\n\n");
            printf("                       1. Accion             2. Simulacion           \n\n");
            printf("                       3. Deportes           4. Supervivencia        \n\n");
            printf("                       5. Estrategia         6. Otro                 \n\n");
            printf("\n\n\n                             Que desea hacer?");

            cuadro(1, 100, 1, 25);

            gotoxy(46,23); printf(" ");

            gotoxy(2, 20); printf("                                                                                   ");
            gotoxy(55, 23); printf("                            ");

            gotoxy(46,23);
            scanf("%d", &genero);

            system("cls");

            switch(genero)
            {
                case 1:
                    mostrarListaGenero(listaGeneros, arbol, Accion);
                    break;

                case 2:
                    mostrarListaGenero(listaGeneros, arbol, Simulacion);
                    break;

                case 3:
                    mostrarListaGenero(listaGeneros, arbol, Deportes);
                    break;

                case 4:
                    mostrarListaGenero(listaGeneros, arbol, Supervivencia);
                    break;

                case 5:
                    mostrarListaGenero(listaGeneros, arbol, Estrategia);
                    break;

                case 6:
                    mostrarListaGenero(listaGeneros, arbol, Otro);
                    break;
            }
            system("pause");
            break;

        case 3:
            system("cls");
            mostrarArchivoJuegos(nombreArchiJuegos);
            printf("\n\nDonde desea agregar el juego?\n 1.Lista de deseos  2.Carrito\n");

            scanf("%d", &i);

            printf("Que id de juego desea agregar? ");
            scanf("%d", &IdAgregar);

            if(existeJuego(arbol, IdAgregar) == 1)
            {
                if(i == 1)
                {
                    user = AgregarListaDeseados(archiUser, id, IdAgregar, arbol);
                }
                else if(i==2)
                {
                    user = AgregarCarrito(archiUser, id, IdAgregar, arbol);
                }
            }
            else
            {
                printf("Id no valido\n");
            }


            system("pause");
            break;

        case 4:

            system("cls");
            printf("Ingrese el nombre a buscar: ");
            fflush(stdin);
            gets(juegoABuscar);
            IdAgregar = buscarPorNombre(arbol, juegoABuscar).idJuego;

            system("cls");
            printf("Donde desea agregar el juego?\n 1.Lista de deseos  2.Carrito\n");

            scanf("%d", &i);

            if(existeJuego(arbol, IdAgregar) == 1)
            {
                if(i == 1)
                {
                    user = AgregarListaDeseados(archiUser, id, IdAgregar, arbol);
                }
                else if(i==2)
                {
                    user = AgregarCarrito(archiUser, id, IdAgregar, arbol);
                }
            }
            else
            {
                printf("Id no valido\n");
            }

            system("pause");
            break;

        case 5:
            system("cls");
            mostrarArregloJuegosUser(user.Adquiridos, user.validosAdquiridos, arbol);
            system("pause");
            break;

        case 6:
            system("cls");
            mostrarArregloJuegosUser(user.ListaDeseados, user.validosDeseados, arbol);
            system("pause");
            break;

        case 7:
            system("cls");
            mostrarArregloCarrito(user.carrito, user.validosCarrito, arbol);
            if(user.validosCarrito == 0)
            {
                printf("el carrito esta vacio\n\n");
                system("pause");
                break;
            }
            printf("Desea comprar algun juego del carrito? s/N");
            fflush(stdin);
            scanf("%c", &ctrl);
            if(ctrl == 's')
            {
                int idComprar;
                printf("Ingrese el numero del juego que desea comprar: ");
                scanf("%d", &idComprar);

                user = Comprar(archiUser, id, idComprar, arbol, nombreArchiJuegos);
            }

            system("pause");
            break;

        case 8:
            system("cls");
            MostrarUsuario(user);
            printf("\n\nDesea modificar algun dato? s/N: ");
            fflush(stdin);
            scanf("%c", &ctrl);
            if(ctrl == 's')
            {
                ModificarCamposUsuario(archiUser, id);
                system("cls");
                user = BuscarUsuario(archiUser, id);
                MostrarUsuario(user);
            }
            system("pause");
            break;

        case 9:
            while(filaJuegos->inicio != NULL)
            {
                MostrarJuegoUsuario(buscarPorId(arbol, extraerFila(filaJuegos)));
                system("pause");
            }
            pasarJuegosFila(filaJuegos, arbol);
            break;

        case 10:
            return;

    }
    goto menuUser;
}
