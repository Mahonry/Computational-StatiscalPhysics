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
		out = 0;
	}
	
	return out;
}

int main(){

	//Definimos la posicion inicial
	int pos = 0;

	//Definimos el tiempo
	int t = 0;
	
	//Definimos la probabilidad inicia
	double p = 0.01;

	//Definimos la probabilidad q
	double q = 0.3;
	



	srand(time(NULL)); //En la semilla, ponemos el tiempo para generar numeros aleatorios.

	//Maneras de guardar el archivo
	//string namefile;
	//namefile = "FPT_p_" + to_string(p) + ".dat";
	ofstream Results ("T00.dat");
	

	for(int j; j <= 50; j += 1)
	{
		int flag = 0;
		for(int i = 0; i<=10000; i++){
			pos += Coin(p);
			
			if(pos == 1){
				t += 1;
				pos = 0;
				while(pos == 0){
					pos += Coin(q);
					t += 1;
				}
			
			}
			else{
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

