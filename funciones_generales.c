#include <stdio.h>
#include <stdlib.h>

void ejecutarEnConsola(const char *lineaDeComando)
{
    printf("\n");
    system(lineaDeComando);
}

char pedirConfirmacion(const char *texto)
{
    char retorno;

    printf("\n%s (S/N): ", texto);
    fflush(stdin);
    scanf("%c", &retorno);

    do
    {
        switch(retorno)
        {
            case 'S':
            case 's':
                retorno = 'S';
                break;
            case 'N':
            case 'n':
                retorno = 'N';
                break;
            default:
                printf("\nPor favor ingrese 'S' o 'N': ");
                fflush(stdin);
                scanf("%c", &retorno);
                break;
        }
    }
    while(retorno != 'S' && retorno != 'N');

    return retorno;
}
