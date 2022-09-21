//Vamos a modificar el metodo para modelar tiempo medio de primer paso de la probabilidad de T 0->0
#include<cstdlib>
#include<fstream> //Libreria para grabar cosas en archivos
#include<iostream>

// En la terminal podemos correr ls *.dat > names.txt para hace una lista de archivos 

using namespace std;

int Coin(double p){
	double val = 1.0*rand()/RAND_MAX;
	int out;	
	
	if (val<=p){
		out = 1;
	}
	else{
		out = -1;
	}
	
	return out;
}

int Transitions(int node, int Nv){
	int change = Coin(0.5);
	
	if (change == 1){
		node = (node + 1)%Nv;
	}
	else{
		node = ((node - 1)%Nv + Nv)%Nv; //Ayuda a que el resultado no sea negativo	
	}
	return node;
}





int main(){
	//Definimos construtor para guardar los resultados
	string namef;

	//En la semilla, ponemos el tiempo para generar numeros aleatorios.
	srand(time(NULL)); 
	
	//Tamaño de la red
	int Nv = 50; 

	//Definimos tiempo inicial
	int t = 0;

	//Definimos nodo inicial
	int actual_node = 0;

	//Definimos Target;
	int target;
	
	

	for (int i = 1; i <50; i++){
		namef = "Data/Anillo/FPT_anillo_node" + to_string(i) + ".dat";
		ofstream FPT_data (namef);
		FPT_data<<"TIME"<<endl;
		target = i;
		for (int j = 0; j < 1000000; j++){

			while(actual_node != target){
				actual_node = Transitions(actual_node,Nv);
				t += 1;
			}
			FPT_data<<t<<endl;
			t = 0;
			actual_node = 0;
		}

	
	}


	return 0;
}

