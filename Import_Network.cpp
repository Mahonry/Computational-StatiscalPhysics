#include<cstdlib>
#include<fstream> 
#include<iostream>
using namespace std;

//Objetivo leer la red

string str;
int a, b;
int Nv = 100;
int matA[Nv][Nv]; //Matriz de Adjacencia 

int main()
{
	//Inicializamos la matriz en cero
	for (int i = 0; i<Nv;i++)
	{
		for(int j = 0; j<Nv; j++)
		{
			matA[i][j] = 0;		
		}	
	}

	ifstream file("Lines.dat");

	while(getline(file,str))	
	{
		a = stoi(str.substr(0,str.find("  ")));
		b = stoi(str.substr(str.find("  ")+2));		
		matA[a][b] = 1;
		matA[b][a] = 1;
	}
	

	///Enviamos al archivo
	ofstream Adjacency ("matA.dat");

	for (int i = 0; i<Nv; i++)
	{
		for(int j = 0; j<Nv; j++)
		{
			Adjacency<<matA[i][j]<<" ";		
		}	
		
		Adjacency<<endl;
	}

	Adjacency.close();

	return 0;
}

