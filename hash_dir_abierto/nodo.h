# ifndef stdio_h
# include <stdio.h>
# define stdio_h
# endif

# ifndef stdlib_h
# include <stdlib.h>
# define stdlib_h
# endif

# ifndef dato_h
# include "dato.h"
# define dato_h
# endif

typedef struct _nodo{
	Datos* datos;
	struct _nodo* sgte;
}Nodo;


Nodo *inicializar_nodo(){
	Nodo *nodo=(Nodo*)malloc(sizeof(Nodo));
	nodo->datos=inicializar_datos();
	nodo->sgte=NULL;
	return nodo;
}

