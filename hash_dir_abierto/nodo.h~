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

Nodo *inicializar_nodo(int i){
	Nodo *nodo=(Nodo*)malloc(sizeof(Nodo));
	nodo->datos=inicializar_datos(i);
	nodo->sgte=NULL;
//	printf("%i\t%c\n", (nodo->datos->rut), (nodo->datos->nombre));
	return nodo;
}

int nodo_es_vacio(Nodo *nodo){
	if (nodo==NULL)	return 1;
	return 0;
}

void imprimir_nodo(Nodo *nodo){
	if (nodo_es_vacio(nodo)==0){
		imprimir_datos(nodo->datos);
	}
}
