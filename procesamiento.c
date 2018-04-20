#include <stdio.h>
#include "funciones_generales.h"
#include "estructuras.h"
#include "arrays.h"

void mostrarPersona(const ePersona *persona)
{
    printf("\n%-20s | edad: %d | dni: %d", persona->nombre, persona->edad, persona->dni);

}

void procesarImprimirLista(const ePersona *personas)
{
    int i = 0;

    ejecutarEnConsola(LIMPIAR_PANTALLA);
    while(personas[i].estado == 'A' && i < CANT_MAX_PERSONAS)
    {
        mostrarPersona(&(personas[i]));
        i++;
    }
    if(i == 0)
    {
        printf("\nNada para mostrar! \n\nLa lista esta vacia o todos los registros se dieron de baja.");
    }
    ejecutarEnConsola(HACER_PAUSA);
}

int pedirInt(const char *mensajeIngreso)
{
    int retorno;

    printf("%s", mensajeIngreso);
    fflush(stdin);
    scanf("%d", &retorno);


    return retorno;
}

int pedirDni()
{
    int dni;

    dni = pedirInt("\nIngrese el DNI de la persona que desea dar de baja: ");

    while(dni <= DNI_MIN || dni > DNI_MAX)
    {
        dni = pedirInt("\nEl DNI ingresado no es valido. Por favor reingrese dicho numero: ");
    }

    return dni;
}

void procesarBaja(ePersona *personas)
{
    int dni;
    int i;
    char confimacion;

    ejecutarEnConsola(LIMPIAR_PANTALLA);
    printf("\nDANDO DE BAJA UNA PERSONA");

    dni = pedirDni();
    printf("\ndni : %d", dni);
    i = buscarEnPersonasDni(&dni, personas);
    if(i == -1)
    {
        printf("\nEl dni ingresado no existe en la lista de personas");
    }
    else
    {
        mostrarPersona(personas+i);

        if((personas+i)->estado != 'A')
        {
            printf("La persona ya se encontraba dada de baja");
        }
        else
        {
            confimacion = pedirConfirmacion("Esta seguro que desea dar de baja a la persona?");
            if(confimacion == 'S')
            {
                (personas+i)->estado = 'B';
            }
            else
            {
                printf("\nSe cancelo la gestion\n");
            }
        }
    }
    ejecutarEnConsola(HACER_PAUSA);
}

