#include<iostream>
#include<stdlib.h>
using namespace std;
struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
	
};
//Prototipos de las funciones
Nodo *crearNodo(int);// la funcion crear tiene un apuntador
void insertarNodo(Nodo *&, int);
void menu();
void mostrarArbol(Nodo *, int);
bool busqueda(Nodo *, int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
void borrar(Nodo *);
Nodo *arbol=NULL;//OBLIGATORIO.

int main(){
	menu();
	
	
	
	return 0;
}
// Funcion de menu

void menu(){
	int dato, opcion, contador=0;
	
	do{
		
		cout<<"\nMENU. "<<endl;
		cout<<"1. INSERTAR UN NUEVO NODO."<<endl;
		cout<<"2. MOSTRAR ARBOL."<<endl;
		cout<<"3. BUSCAR EN EL ARBOL."<<endl;
		cout<<"4. Recorrer el arbol en PreOrden."<<endl;
		cout<<"5. Recorrer el arbol en InOrden."<<endl;
		cout<<"6. Recorrer el arbol en postOrden."<<endl;
		cout<<"7. Salir."<<endl;
		cout<<"Opcion: ";
		cin>>opcion;
	     switch(opcion){
	     	
	     	case 1: cout<<"Digite el numero que desee insertar en el arbol: ";
	     	        cin>>dato;
	     	        insertarNodo(arbol, dato);
	     	        cout<<"\n";
	     	        system("pause");
	     	        break;
	     	case 2:
	     		    cout<<"IMPRIMIENDO EL ARBOL."<<endl;
	     		    mostrarArbol(arbol, contador);
	     		    cout<<"\n";
	     		    system("pause");
	     		    break;
	     	case 3:
	     		   cout<<"Ingrese el elemento que desea buscar en el arbol: ";
	     		   cin>>dato;
	     		   if((busqueda(arbol, dato))==true){
	     		   	    cout<<"ELEMENTO FUE ENCONTRADO."<<endl;
					}else{
						cout<<"Elemento no fue encontrado:c"<<endl;
					}
	     		    system("pause");
	     		    break;
	     	case 4: cout<<"Recorriendo el arbol en PreOrden."<<endl;
	     	        preOrden(arbol);
	     	        cout<<"\n";
	     		    system("pause");
	     	        break;
	     	case 5: cout<<"Mostrando el arbol en InOrden."<<endl;
	     	        inOrden(arbol);
	     	        cout<<"\n";
	     		    system("pause");
	     	        break;
	     	case 6: cout<<"Mostrando el arbol en postOrden."<<endl;
	     	        postOrden(arbol);
	     	        cout<<"\n";
	     		    system("pause");
	     	        break;
		 }
		 system("cls");
	}while(opcion != 7);
	
	
}


//funcion para crear un nuevo nodo.
Nodo *crearNodo(int n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	
	return nuevo_nodo;
	
}
//funcion para insertar un nuevo nodo.
void insertarNodo(Nodo *&arbol , int n){
	//tenemos que tener en cuenta dos cosas: que el arbol este vacio y qu el arbol ya tenga un nodo.
	if(arbol==NULL){
		Nodo *nuevo_nodo= crearNodo(n);
		arbol= nuevo_nodo;
	}else{
		int ValorRaiz =arbol->dato;//obtenemos el valor de la raiz
		if(n<ValorRaiz){//insertamos el nodo a la izquierda ya que el elemento es menor
		   insertarNodo(arbol->izq, n);
		}else{//insertamos el nodo a la derecha ya que el elemento es mayor
			insertarNodo(arbol->der, n);
		}
	}
	
}
// Funcion para mostrar el arbol
void mostrarArbol(Nodo *arbol, int cont){
	if( arbol== NULL){
		return;
	}else{
		mostrarArbol(arbol->der, cont+1);//primero mostramos el arbol por la der
		for(int i=0; i<cont; i++){
			cout<<"  ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq, cont+1);
	}
}
//funcion buscar en el arbol un nodo

bool busqueda(Nodo *arbol, int n){
	if(arbol==NULL){
		return false;
	}else if(arbol->dato==n){
		return true;
	}else if(n<arbol->dato){
		return busqueda(arbol->izq, n);
	}else{
		return busqueda(arbol->der, n);
	}
	
}

void preOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}else{
		cout<<arbol->dato<<"-";
		preOrden(arbol->izq);
		preOrden(arbol->der);	
	}
}
void inOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	
	}else{
		inOrden(arbol->izq);
		cout<<arbol->dato<<"-";
		inOrden(arbol->der);
	}
}

void postOrden( Nodo *arbol){
	if(arbol==NULL){
		return;
	}else{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout<<arbol->dato<<"-";
	}
}
void borrar(Nodo *arbol){
	arbol->izq=arbol->der;
}
	
