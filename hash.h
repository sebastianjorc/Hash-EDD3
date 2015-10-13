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

# ifndef nodo_h
# include "nodo.h"
# define nodo_h
# endif

# ifndef dato_h
# include "dato.h"
# define dato_h
# endif

typedef struct _hash{
	int alfa;
	Nodo *nodo;
}Hash;

void imprimir_tabla_hash(int m, Hash tablaHash[m]);
void inicializar_tabla_hash(Nodo *nodo, int m, Hash tablaHash[m]);

void imprimir_tabla_hash(int m, Hash tablaHash[m]){
	Nodo *aux;
	for (int i=0; i<m; i++){
		printf("Hash: %i\n",i);
		aux=tablaHash[i].nodo;
		while (aux!=NULL){
			imprimir_nodo(aux);
			aux=aux->sgte;
		}getchar();
	}
}

void inicializar_tabla_hash(Nodo *nodo, int m, Hash tablaHash[m]){
	int i=0; Nodo* aux,*aux2;
	establecer_alfa(nodo,m);
    	clock_t start = clock();
	for (int j=0; j<m; j++){
		tablaHash[j].nodo=NULL;
	}
	while (nodo->sgte!=NULL){
		i=nodo->alfa; 
		aux2=nodo->sgte;
		if (tablaHash[i].nodo==NULL){
			tablaHash[i].nodo=nodo; 
		}
		else{
			aux=tablaHash[i].nodo;
			while (aux->sgte!=NULL && aux->sgte->alfa==i){
				aux=aux->sgte;				
			}
			aux->sgte=nodo;
			nodo->sgte=NULL;
		}
		nodo=aux2;
	}
   	printf("Tiempo transcurrido en agregar nodos a tabla hash: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);getchar();
}

void buscar_nodo(int clave, Nodo *nodo, int m, Hash hash[m]){
    	clock_t start = clock();
	if (hash==NULL){
		while (clave!=(nodo->datos->pk)){
			nodo=nodo->sgte;
		}
	}
	else{
		Nodo *unNodo=hash[(clave%m)].nodo;
		while ((clave)!=(unNodo->datos->pk)){
			unNodo=unNodo->sgte;
		}
	}
   	printf("Tiempo transcurrido en buscar nodo es: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);getchar();
}
void insertar_nodo(int clave, Nodo *nodo, int m, Hash hash[m]){
    	clock_t start = clock();

	Nodo *aux=(Nodo*)malloc(sizeof(Nodo)); 
	aux->sgte=NULL; 

	aux->datos=inicializar_datos(clave);
	aux->alfa=(clave%m);

	if (hash==NULL){
		while (nodo->sgte!=NULL){
			nodo=nodo->sgte;
		}
		nodo->sgte=aux;
	}
	else{
		Nodo *unNodo=hash[(clave%m)].nodo;
		while ((clave)!=(unNodo->datos->pk)){
			unNodo=unNodo->sgte;
		}
		unNodo->sgte=aux;
	}
   	printf("Tiempo transcurrido ingresar nodo es: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);getchar();
}
