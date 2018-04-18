#include <stdio.h>
#include <stdlib.h>
#include "funciones_generales.h"
#include "estructuras.h"
#include "menus.h"

int main()
{
    char salirDelPrograma = 'N';
    int opcion;
    do
    {
        static eMenu menuPrincipal = {/*cant opciones en el menu*/5,
                                    /*codigo opciones disponibles*/{1,2,3,9},
                                    /*descripcion opciones*/{"1. Agregar una persona","2. Borrar una persona","3. Imprimir lista ordenada por nombre","4. Imprimir gr fico de edades","9. Salir"}};
        static eMenu menuAlta = {5,{1,2,3,8,9},{"1. Nombre","2. Edad","3. Dni","8. Confirmar datos","9. Cancelar carga"}};

        opcion = pedirOpcion(&menuAlta);
        ejecutarEnConsola(HACER_PAUSA);

        salirDelPrograma = pedirConfirmacion("Desea salir del programa");
    }
    while(salirDelPrograma == 'N');

    return 0;
}
