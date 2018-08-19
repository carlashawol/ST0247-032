#include <iostream>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0
using namespace std;
int comprobar (int fila, int reinas[], int n) 
{
  int i;

  for (i=0; i<fila; i++)
      if (  ( reinas[i]==reinas[fila] )                      
         || ( abs(fila-i) == abs(reinas[fila]-reinas[i]) ) ) 
         return FALSE;
 
  return TRUE;
}

void mostrarTablero (int reinas[], int n)
{
  int i,j;

  for (i=0; i<n; i++) {

      for (j=0; j<n; j++) {

          if (reinas[i]==j)
             cout<<"#"<<endl;
          else
             cout<<"-"<<endl;
      }

      cout<<i<<endl;
      cout<<reinas[i]<<endl;
  }

  cout<<endl;
}

void colocarReina (int fila, int reinas[], int n)
{
  int ok = FALSE;

  if (fila<n) {


     for (reinas[fila]=0; reinas[fila]<n; reinas[fila]++) {

         if (comprobar(fila,reinas,n)) {


            colocarReina (fila+1, reinas, n);
         }
     } 
  
  } else {


     mostrarTablero(reinas,n);
  }

  return 0;
}


void mostrarAyuda (char *programa)
{
  cout<<"Uso del programa:\n";
  cout<<programa;
  cout<<"donde <n> es el número de reinas que deseamos colocar (un mínimo de 4).\n";
}


void main (int argc, char *argv[])
{
  int *reinas; 
  int nreinas;  
  int i;        

  nreinas = -1;

  if (argc==2) 
     nreinas = atoi(argv[1]);


  if (nreinas>0) {


      reinas = (int*) malloc ( nreinas*sizeof(int) );


      for (i=0; i<nreinas; i++)
          reinas[i] = -1;

      colocarReina(0,reinas,nreinas);


      free (reinas);
  
  } else {

      mostrarAyuda(argv[0]);

  }
}

// Tomado de: http://elvex.ugr.es/decsai/c/problemas/reinas/reinas2.c
