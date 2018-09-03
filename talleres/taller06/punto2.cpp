#include <iostream>
#include <iomanip>
#include <list>

struct label {
   int nro;	
   int prev;
   int peso;	
   int marca;
};
typedef struct label label_t;
 
using namespace std;
 
void dijkstra( int, int **, int, int );
 
int main () {
 
   int numNodos = 8;

   int i, j, **A;
 
   if ( ( A = new int*[numNodos] ) == NULL ) return 1;
   for ( i = 0; i < numNodos; i++ )
      if ( ( A[i] = new int[numNodos] ) == NULL ) return 1;
 
   for ( i = 0; i < 8; i++ )
      for ( j = 0; j < 8; j++ )
         A[i][j] = 0;
 
   A[0][1] = 16;
   A[0][2] = 10;
   A[0][3] = 5;
 
   A[1][0] = 16;
   A[1][2] = 2;
   A[1][5] = 4;
   A[1][6] = 6;
 
   A[2][0] = 10;
   A[2][1] = 2;
   A[2][3] = 4;
   A[2][4] = 10;
   A[2][5] = 12;
 
   A[3][0] = 5;
   A[3][2] = 4;
   A[3][4] = 15;
 
   A[4][2] = 10;
   A[4][3] = 15;
   A[4][5] = 3;
   A[4][7] = 5;
 
   A[5][1] = 4;
   A[5][2] = 12;
   A[5][4] = 3;
   A[5][6] = 8;
   A[5][7] = 16;
 
   A[6][1] = 6;
   A[6][5] = 8;
   A[6][7] = 7;
 
   A[7][4] = 5;
   A[7][5] = 16;
   A[7][6] = 7;

   cout << "Matriz de adyacencia:" << endl << endl;
   for ( i = 0; i < 8; i++ ) {
      for ( j = 0; j < 8; j++ )
         cout << setw(2) << A[i][j] << "  ";
      cout << endl;
   }
   cout << endl;

   dijkstra( numNodos, A, 0, 7 );

   delete [] A;
   for ( i = 0; i < numNodos; i++ )
      delete A[i];
 
   return 0;
}
 

void dijkstra( int N, int **A, int a, int b ) {
 
   label_t *Labels;
   int i, i0, j, peso;
   int *ruta;	
 
   if ( ( Labels = new label_t[N] ) == NULL ) return;
 
   if ( a < 0 || a > N - 1 ) return;

   if ( b < 0 || b > N - 1 ) return;
 
   for ( i = 0; i < N; i++ ) {
      Labels[i].nro = i;
      if ( i != a ) {
         Labels[i].prev = -1;
         Labels[i].peso = -1;
         Labels[i].marca = 0;
      }
      else {
         Labels[i].prev = -1;
         Labels[i].peso = 0;		
         Labels[i].marca = 0;
      }
   }

   while ( 1 ) {
     
      peso = -1;
      i0 = -1;
      for ( i = 0; i < N; i++ ) {
         if ( Labels[i].marca == 0 && Labels[i].peso >= 0 )
            if ( peso == -1 ) {
               peso = Labels[i].peso;
               i0 = i;
            }
            else if ( Labels[i].peso <= peso ) {
               peso = Labels[i].peso;
               i0 = i;
            }
      }
      if ( i0 == -1 ) {	/* termina si no encuentra */
         cout << "Ya no quedan nodos por analizar." << endl;
         break;
      }
 
      cout << "*** Analizando nodo " << i0 << " ***" << endl;
 

      for ( i = 0; i < N; i++ ) {
         if ( A[i0][i] > 0 ) {
           
            if ( Labels[i].peso == -1 || Labels[i0].peso + A[i0][i] < Labels[i].peso ) {
               if ( Labels[i0].peso + A[i0][i] < Labels[i].peso )
                  cout << "   [ mejorando coste de nodo " << i << " ]" << endl;
               Labels[i].peso = Labels[i0].peso + A[i0][i];
               Labels[i].prev = i0;
               cout << "   coste de nodo " << i << " desde nodo " << i0 << ": " << Labels[i].peso << endl;
            }
         }
      }
      Labels[i0].marca = 1;
      cout << "   [ nodo " << i0 << " marcado ]" << endl;
 
      for ( i = 0; i < N; i++ ) {
         cout << i << ": [";
         if ( Labels[i].peso == -1 ) cout << "Inf";
         else cout << Labels[i].peso;
         cout << ", " << Labels[i].prev ;
         if ( Labels[i].marca == 1 ) cout <<  ", x]" << endl;
         else cout << "]" << endl;
      }
      cout << endl;
 
      cout << "presione ENTER para continuar ...";
      cin.get();
   }
 
   int longitud = 2;
   i = b;
   while ( ( i = Labels[i].prev ) != a ) longitud++;	
   if ( ( ruta = new int[longitud] ) == NULL ) return;
 
   ruta[longitud - 1] = b;		
   i = b;
   j = 0;
   for ( j = 1; j < longitud; j++ ) {
      i = Labels[i].prev;
      ruta[longitud - j - 1] = i;
   }
 
   cout << "================================================================" << endl;
   cout << endl << "Ruta mas economica entre nodo " << a << " y nodo " << b << ":" << endl << endl;
   for ( i = 0; i < longitud; i++ ) {
      cout << ruta[i];
      if ( i < longitud - 1 ) cout << " - ";
   }
   cout << endl << endl << "Costo total: " << Labels[b].peso << endl << endl;
 
   delete ruta;
   delete [] Labels;
}
//tomado de:https://foro.elhacker.net/programacion_cc/algoritmo_de_dijkstra_paso_a_paso-t427371.0.html
