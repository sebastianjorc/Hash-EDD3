# ifndef stdio_h
# include <stdio.h>
# define stdio_h
# endif

# ifndef stdlib_h
# include <stdlib.h>
# define stdlib_h
# endif

#ifndef TIME_H
#include <time.h>
#define TIME_H
#endif

# ifndef dato_h
# include "dato.h"
# define dato_h
# endif

typedef struct _nodo{
	int alfa;
	Datos* datos;
	struct _nodo* sgte;
}Nodo;

Nodo *inicializar_nodo(int i);
int nodo_es_vacio(Nodo *nodo);
void imprimir_nodo(Nodo *nodo);
Nodo* cargar_archivo(int *i, Nodo *nodo);
void establecer_alfa(Nodo *nodo, int m);

Nodo *inicializar_nodo(int i){
	Nodo *nodo=(Nodo*)malloc(sizeof(Nodo));
	nodo->sgte=NULL;
	return nodo;
}

int nodo_es_vacio(Nodo *nodo){
	if (nodo==NULL)	return 1;
	return 0;
}

void imprimir_nodo(Nodo *nodo){
	imprimir_datos(nodo->datos);
}

Nodo* cargar_archivo(int *i, Nodo *nodo){
	nodo=NULL; nodo=(Nodo*)malloc(sizeof(Nodo));
	Datos *dato=cargar_datos(nodo->datos,i);
    	clock_t start = clock();
	while (dato->sgte!=NULL){
		
		Nodo *nuevo=(Nodo*)malloc(sizeof(Nodo));
		nuevo->datos=dato;
		dato=dato->sgte;
		if (nodo->datos==NULL){
			nodo=nuevo;
		}
		else{	
			Nodo *aux=nodo;
			while (aux->sgte!=NULL){
				aux=aux->sgte;
			}
			aux->sgte=nuevo;
		}
	}
   	printf("Tiempo transcurrido en cargar datos desde archivos y transformarlos en nodos: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);getchar();
	return nodo;
}

void establecer_alfa(Nodo *nodo, int m){
	Nodo *aux=nodo;
	while (aux!=NULL){
		aux->alfa=buscar_alfa(aux->datos,m);
		aux=aux->sgte;
	}
}
