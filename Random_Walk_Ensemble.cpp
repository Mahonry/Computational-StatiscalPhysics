//Vamos a modificar el caminantes aleatorios para hacer 1000 realizaciones y guardar el dato al tiempo t = 100

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
		out = -1;
	}
	
	return out;
}

int main(){
	ofstream Results ("DataRW_Ensamble.dat");
	srand(time(NULL)); //En la semilla, ponemos el tiempo para generar numeros aleatorios.
	int pos = 0;
	for(int j=0; j<1000000; j++){
		pos = 0;
		for(int i=0; i<10000; i++){	
			pos += Coin(0.5);
		}
	Results<<pos<<endl;
	}
	cout<<"Done"<<endl;
	Results.close();
	return 0;
}

