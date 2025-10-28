/*Implemente un programa en C++ que:

1.Lea el número de aeropuertos n

2.crear una matriz dinámica de distancias entre aeropuertos de tamaño n x n de tipo double

3.Llenar la matriz con valores aleatorios entre 100 y 1500 km

4.Muestre la matriz

5.Calcular el promedio de las distancias

6.Mostrar el aeropuerto con la menor distancia promedio hacia los demás

7.Implemente una función liberarMatriz

AUTOR: Aguedo Lucero Franz Paul
Codigo:20244728H



*/



#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

double **MatrizDistancias(int n){
    double **matriz = new double*[n];
    for(int i=0;i<n;i++){
        matriz[i] = new double[n];
    }

    for(int i =0;i < n;i++){
        for(int j =0 ;j<n;j++){
            matriz[i][j] = 100.0 + (1500.0 - 100.0) * ((double)rand() / RAND_MAX); //Me da los valores aleatorios de tipo double entre 1500 y 100 usando la formula de RAND
        }
    }

    return matriz;
}

void MostrarMatriz(double **matriz,int n){
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout <<endl;
    }
}

double CalculoProm(double **matriz,int n){
    
    double Prom =0;
    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            Prom += matriz[i][j];
        }
    }

    int o = n*n;
    return Prom/o;
}

double Encontrarmin(double **matriz,int n){
    double Valormin = matriz[0][0];
    double prom = CalculoProm(matriz,n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(fabs(Valormin - prom) > fabs(matriz[i][j]-prom)){//compara la diferencia entre el promedio para saber quien es el menor valor
                Valormin = matriz[i][j];
            }
        }
    }
    return Valormin;
}

//Adicianamos una funcia liberar matriz
void liberarMatriz(double **matriz,int n){
    for(int i =0;i<n;i++){
        delete[] matriz[i];
    }
    delete[] matriz;

}

int main() {
    srand(time(NULL));
    int n;

    cout << "Ingrese el numero de aeropuertos: ";
    cin >> n;
    double **ptr = MatrizDistancias(n);
    cout << "La matriz distancias generada: "<<endl;
    MostrarMatriz(ptr,n);
    cout <<"Promedio de las distancias: "<<CalculoProm(ptr,n)<<endl;
    cout<<"Distancia mas cerca al promedio es: "<<Encontrarmin(ptr,n);
    liberarMatriz(ptr,n);
    return 0;
}