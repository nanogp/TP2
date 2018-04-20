#include <stdio.h>
#include <stdlib.h>
#include "funciones_generales.h"
#include "estructuras.h"
#include "menus.h"
#include "procesamiento.h"


int main()
{
    char salirDelPrograma = 'N';
    int opcion;
    const eMenu menuPrincipal = {/*cant opciones en el menu*/5,
                                /*codigo opciones disponibles*/{1,2,3,4,9},
                                /*descripcion opciones*/{"1. Agregar una persona","2. Borrar una persona","3. Imprimir lista ordenada por nombre","4. Imprimir gr fico de edades","9. Salir"}};
    const eMenu menuAlta = {5,{1,2,3,8,9},{"1. Nombre","2. Edad","3. Dni","8. Confirmar datos","9. Cancelar carga"}};
    ePersona personas[CANT_MAX_PERSONAS]={};

    ePersona p1 = {{"juan perez"}, 21, 12, 'A'};
    ePersona p2 = {{"perica sanchez"}, 18, 13, 'A'};
    ePersona p3 = {{"tuvieja entanga"}, 56, 14, 'A'};

    personas[0]=p1;
    personas[1]=p2;
    personas[2]=p3;


    do
    {
        opcion = pedirOpcion(&menuPrincipal);

        switch(opcion)
        {
            case 1:
                //procesarAlta(&menuAlta, &personas);
                break;
            case 2:
                procesarBaja(&personas);
                break;
            case 3:
                procesarImprimirLista(personas);
                break;
            case 4:
                //procesarGrafico(&personas);
                break;
            case 9:
                salirDelPrograma = pedirConfirmacion("Desea salir del programa?");
                break;
        }
    }
    while(salirDelPrograma == 'N');

    return 0;
}
