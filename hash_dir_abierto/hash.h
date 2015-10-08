# ifndef stdio_h
# include <stdio.h>
# define stdio_h
# endif

# ifndef stdlib_h
# include <stdlib.h>
# define stdlib_h
# endif

# ifndef nodo_h
# include "nodo.h"
# define nodo_h
# endif

# ifndef dato_h
# include "dato.h"
# define dato_h
# endif

# define tam 5

typedef int Alfa;

typedef struct _hash{ //nRanuras=5;
	Alfa alfa;
	Nodo *nodo;
}Hash;

void inicializar_tabla_hash(Hash tablaHash[tam]);
void imprimir_tabla_hash(Hash tablaHash[tam]);

void inicializar_tabla_hash(Hash tablaHash[tam]){
	for (int i=0; i<tam; i++){
		(tablaHash[i]).alfa=i;
		tablaHash[i].nodo=inicializar_nodo(i);
	}
}

void imprimir_tabla_hash(Hash tablaHash[tam]){
	for (int i=0; i<tam; i++){
			printf("\nAlfa = %i\n",(tablaHash[i].alfa));
			imprimir_nodo(tablaHash[i].nodo);
	}
}
