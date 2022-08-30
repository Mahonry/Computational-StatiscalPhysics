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
	ofstream Results ("DataRW.dat");

	srand(time(NULL)); //En la semilla, ponemos el tiempo para generar numeros aleatorios.

	cout<<"____________"<<endl;
	int pos = 0;

	for(int i=0; i<100000000; i++){	
		pos += Coin(0.5);
		Results<<pos<<endl;
	}

	cout<<"____________"<<endl;
	
	Results.close();

	return 0;
}

