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
		out = 0;
	}
	else{
		out = 1;
	}
	
	return out;
}

int Transition(int state, double p, double q){
	
	if (state == 0){
		state = Coin(1-p);
	}
	else{
		state = Coin(q);	
	}
	return state;
}

int FPT(int initial, int target, double p, double q){
	int state = initial;
	int time = 0;

	if (state == target){
		state = Transition(state,p,q);
		time += 1;
		
		while(state != target){
			state = Transition(state,p,q);
			time += 1;
		}
	}
	
	else{
		while(state != target){
			state = Transition(state,p,q);
			time += 1;
		}
			
				
	}
	
	return time;	

}


int main(){
	//En la semilla, ponemos el tiempo para generar numeros aleatorios.
	srand(time(NULL)); 
	
	
	double p = 0.01;
	string namef;
	
	while(p<=0.8){
		namef = "Pass T/FPT_p" + to_string(p).substr(0,4) + ".dat";
		ofstream FPT_data (namef);	
		
		for(int i = 0; i<10000; i++){
			FPT_data<<FPT(0,1,p,0.1)<<endl;
		}
		
		FPT_data.close();
		p += 0.01;
	}


	return 0;
}

