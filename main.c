#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define nombreApp "estim"

int main()
{
    int retorno = MessageBox(NULL, "Acepte terminos y condiciones\nAl aceptar el contrato acepta que:\n-satan�s posea su alma para el resto de la eternidad.\n-se usen sus datos privados para venderlos por la deep web.\n-no se ha ba�ado en m�s de una semana", nombreApp, MB_OKCANCEL );

    while(retorno == IDCANCEL)
    {
        retorno = MessageBox(NULL, "Acepte terminos y condiciones para continuar\n", nombreApp, MB_OKCANCEL );
    }

    system("pause");
    return 0;
}

