#include <iostream>
#include <stdlib.h> // Libreria para rand() y srand()
#include <time.h>   // Libreria para clock() y time()
#include <iomanip> // Libreria para mostrar el resultado del tiempo en segundos y no en notacion cientifica
using namespace std;

//Declaracion de funciones

void pedirTamano(int &tamano, int* &arr);
void llenarArreglo(int arr[], int tamano);
void imprimirArreglo(int arr[], int tamano);
void ordenarSeleccion(int arr[], int tamano);

int main() {
    srand(time(NULL)); // Inicializar la semilla aleatoria
    int* arreglo = NULL; // Puntero para crear el arreglo dinámico
    int tamano = 0;
    int opcion = 0;
    
    do { // Ciclo do-while para el programa
    cout<<"\n===================================================\n";
    cout<<"              MENU PRINCIPAL - SELECCION             \n";
    cout<<"\n===================================================\n";
        cout<<"1: Leer tamaño del arreglo\n";
        cout<<"2: Llenar el arreglo con números al azar\n";
        cout<<"3: Imprimir arreglo\n";
        cout<<"4: Ordenar el arreglo\n";
        cout<<"5: Salir del programa\n";
        cout<<"Seleccione la opcion: \n";
        cin>>opcion;
        
        //Switch para seleccionar
        
        switch(opcion){
            case 1:
                pedirTamano(tamano, arreglo);
                break;
            case 2:
                if(tamano<=0 || arreglo==NULL){
                    cout<<"Primero ingrese un numero valido (opcion 1)\n";
                } else{
                    llenarArreglo(arreglo, tamano);
                }
                break;
            case 3:
                if(tamano<=0 || arreglo==NULL){
                    cout<<"El arreglo no ha sido creado\n";
                } else{
                    imprimirArreglo(arreglo, tamano);
                }
                break;
            case 4:
                if(tamano<=0 || arreglo==NULL){
                    cout<<"El arreglo no ha sido creado\n";
                } else{
                    ordenarSeleccion(arreglo, tamano);
                }
                break;
            case 5:
                cout<<"Saliendo del programa...\n";
                break;
            default:
                cout<<"Numero invalido. Ingrese un numero de nuevo \n";
            }
        } while(opcion!=5);
        
        if (arreglo != NULL) {
            delete[] arreglo;
        }
        return 0;
}

    //IMPLEMENTACION DE LAS FUNCIONES

//Pedir tamaño y reservar memoria dinamica

void pedirTamano(int &tamano, int* &arr){
    do{
        cout<<"Ingrese el tamaño del arreglo: \n";
        cin>>tamano;
        if(tamano<=0){
            cout<<"El tamaño debe ser mayor de 0 \n";
        }
    } while (tamano<=0);
    
    if(arr!=NULL){
        delete[] arr;  //Borrar arreglo si ya existia uno
    }
    
    arr=new int[tamano];
    cout<<"El tamaño establecido a: "<<tamano<<" elementos\n";
}

//Llenar el arreglo con numeros al azar

void llenarArreglo(int arr[], int tamano) {
    int minRango, maxRango;
    cout<<"Ingrese el rango minimo: \n";
    cin>>minRango;
    cout<<"Ingrese el rango maximo: \n";
    cin>>maxRango;
    if(minRango>=maxRango){
        cout<<"Numero excedido \n";
        return;
    } 
    int rango=(maxRango-minRango+1);
    for (int i=0;i<tamano;i++){
        arr[i]=minRango+(rand()%rango);
    } cout<<"Arreglo llenado exitosamente con numeros \n";
}

//Imprimir el Arreglo

void imprimirArreglo(int arr[], int tamano){
    cout<<"\n--- Contenido del arreglo ---\n";
    if(tamano>100){
        cout<<"Mostrando solo los primeros 50 y 50 ultimos elementos por espacio \n";
        for(int i=0;i<50;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n...[...]... \n";
        for(int i=tamano -50; i<tamano;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    } else{
        for (int i=0;i<tamano;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
}

//Ordenar seleccion 

void ordenarSeleccion(int arr[], int tamano){
    long pasadas=0;
    long comparaciones=0;
    long intercambios=0;
    
    //Medicion de tiempo con clock
    clock_t inicio=clock();
    
    //Algoritmo de ordenamiento por seleccion
    
    for (int i=0;i<tamano-1;i++){
        pasadas++;
        int min_idx=i;
        
        for (int j=i+1;j<tamano;j++){
        comparaciones++;
        if(arr[j]<arr[min_idx]){
            min_idx=j;
            }
        }   
    if(min_idx!=i){
        int aux=arr[i];
        arr[i]=arr[min_idx];
        arr[min_idx]=aux;
        intercambios++;
    }
    }
    clock_t fin=clock();
    double tiempoSegundos=(double)(fin-inicio)/ CLOCKS_PER_SEC;
    cout<<fixed<<setprecision(6); //Esta linea permite mostrar el resultado del tiempo en segundos
    
    //Reporte de estadisticas
    cout<<"\n===================================================\n";
    cout<<"             ESTADISTICAS DE RENDIMIENTO             \n";
    cout<<"\n===================================================\n";
    cout<<"Algoritmo:                                  Seleccion\n";
    cout<<"Elementos:     "<<tamano<<"\n";
    cout<<"Pasadas:       "<<pasadas<<"\n";
    cout<<"Comparaciones: "<<comparaciones<<"\n";
    cout<<"intercambios:  "<<intercambios<<"\n";
    cout<<"Tiempo:        "<<tiempoSegundos<<"s\n";
    cout<<"\n===================================================\n";

}