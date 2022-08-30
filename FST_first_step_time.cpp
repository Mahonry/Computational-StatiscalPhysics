//Vamos a modificar el metodo para modelar tiempo medio de primer paso de la probabilidad de T 0->1
#include<cstdlib>
#include<fstream> //Libreria para grabar cosas en archivos
#include<iostream>

using namespace std;

int Coin(double p){
	double val = 1.0*rand()/RAND_MAX;
	int out;	
	
	if (val<=p){
		out = 1;
	}
	else{
		out = 0;
	}
	
	return out;
}

int main(){
	ofstream Results ("T 0-> 1.dat");
	srand(time(NULL)); //En la semilla, ponemos el tiempo para generar numeros aleatorios.
	
	//Definimos la posicion inicial
	int pos = 0;

	//Definimos el tiempo
	int t = 0;
	
	//Definimos la probabilidad inicia
	double p = 0.01;
	for(int j; j <= 50; j += 1)
	{
		for(int i = 0; i<=10000; i++){
			while(pos == 0){
				pos += Coin(p);
				t += 1;
				}
		
		Results<<p<<" "<<t<<endl;
		t = 0;
		pos = 0;
		}
	p += 0.01;
	}
	cout<<"Done"<<endl;
	Results.close();
	return 0;
}

