#include<iostream>
using namespace std;
int main(){
	string h1,h2;
	int tamH1, tamH2;
	cout << "Digite la hilera 1: ";
        cin >> h1;
        cout << "Digite la hilera 2: ";
        cin >> h2;

        tamH1 = h1.length();
        tamH2 = h2.length();

        int matriz[tamH2][tamH1];
        for(int i = 0;i < tamH1; i++){
            matriz[0][i] = i;
        }
        for(int j = 0;j < tamH2; j++){
            matriz[j][0] = j;
        }

        for(int i = 1;i < tamH2; i++){
            for(int j = 1;j < tamH1; j++){
                if(h1.substr(j,1) == h2.substr(i,1)){
                    matriz[i][j] = 0;
                }
                else{
                    matriz[i][j] = 1;
                }
            }
        }
      
        int min=0;
        for(int i = 1;i < tamH2; i++){
            for(int j = 1;j < tamH1; j++){
                min = minimo(matriz[i-1][j] + 1, matriz[i][j-1] + 1);
                matriz[i][j] = minimo(matriz[i-1][j-1] + matriz[i][j], min);
            }
        }

        cout << endl;
        for(int i = 0;i < tamH2; i++){
            for(int j = 0;j < tamH1; j++){
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl << "Hilera 1: " << h1 << "\nHilera 2: " << h2 << endl;
        cout << "Distancia de Levenshtein: " << matriz[tamH2-1][tamH1-1] << endl; 
	
	
	
}
//tomado de:https://sites.google.com/site/algoritmossimilaridaddistancia/distancia-de-levenshtein 

