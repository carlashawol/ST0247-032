#include <stdio.h>
#include<iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;

int main(){
	char *num, resp='s';
	int  cantidad, **w;
	cout<<"               IMPLEMENTACION DE GRAFO CON MATRIZ DE ADYACENCIA."<<endl;
	cout<<"Cantidad de nodos del grafo:"<<endl;
	cin>>cantidad;
    w=(int **)calloc(cantidad, sizeof(int*)); num=(char *)calloc(cantidad, sizeof(char));
	if(num != NULL)
	{
		cout<<"Introduzca todos los nodos en mayuscula: "<<endl;
		cin>>num;

		if(strlen(num) > cantidad){

			cout<<"Cantidad de nodos fuera de limite"<<endl;
		}

		else{
			for (int i=0; i<cantidad; i++){

				for (int a=0; a<cantidad; a++){

					printf("\nHay camino de %num a %c s/num: ", num[i], num[a]);

					fflush(stdin);

					scanf("%num", &resp);

					printf("%num", resp);

					if (resp == 's' || resp == 'S'){

						w[i][a] = 1;

						printf("%d", w[i][a]);

					}

					else{

						w[i][a] = 0;

						printf("%d", w[i][a]);
					}
				}
				cout<<resp<<endl;
			}
			for (int i=0; i<cantidad; i++){

				for (int a=0; a<cantidad; a++){

					printf("%d", w[i][a]);

				}
				cout<<resp<<endl;
			}
		}
	}
	else{
		cout<<"No hay espacio en memoria"<<endl;
	}
	free(num); free(w);
	getch();
	system("pause");
	return 0;
}
