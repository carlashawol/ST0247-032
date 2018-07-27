#include<iostream>
#include <conio.h>
#include<string.h>
#include<time.h>
#define maxPatron 50
#define maxTexto 500
using namespace std;
void FuerzaB(char [],char [], int, int); //funcion
int main(void)
{
char Text[maxTexto];
char Letras[maxPatron];
float Tiempo,inicio,fin;
int n,m;
cout<<"FUERZA BRUTA\n";

 
cout<<"Ingrese Texto:";
gets(Text);
n=strlen(Text);
do{ cout<<"\n\nIngrese patron:";
    cin>>Letras;
    m=strlen(Letras);
    if( m > n )
    cout<<"El texto debe ser mayor o igual que el Patron.\n";
    }while(m>n); 
 
inicio=clock();                  
FuerzaB(Text,Letras,n,m);   
fin=clock();                     
Tiempo=((fin-inicio)/CLOCKS_PER_SEC);
cout<<"\n\nTIME:"<<Tiempo<<endl;
 
getch();
return 0;
 
}
 
void FuerzaBruta(char text[],char letras[], int n, int m)
{ int a, contador=0;
  int i, j;
  char t[100];
  for(i=0; i<=n;i++)
    { for(j=i,a=0;j<m;j++,a++)
      t[a]=text[i+a];
      t[a]='\0';
      if(strcmp(letras,t)==0)
         {cout<<"\nPOSICION  : "<<i<<"\n";
         contador++;}
         m++;
      }
      cout<<"\n\nOCURRENCIAS :"<<contador<<endl;
 
 }
