#define LARGO_ITEM_MENU 50
#define NRO_MAX_OPCIONES_MENU 5
#define LARGO_NOMBRE_PERSONA 100

typedef struct
{
    int cantOpciones;
    int codigos[NRO_MAX_OPCIONES_MENU];
    char descripciones[NRO_MAX_OPCIONES_MENU][LARGO_ITEM_MENU];
} eMenu;

typedef struct
{
    char nombre[LARGO_NOMBRE_PERSONA];
    int edad;
    int dni;
    char estado;
} ePersona;
