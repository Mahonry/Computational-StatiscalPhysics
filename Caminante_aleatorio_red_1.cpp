#include<cstdlib>
#include<fstream> 
#include<iostream>
#include<vector>
using namespace std;

//Objetivo leer la red

string str;
int a, b;
const int Nv = 100;
int matA [Nv][Nv]; //Matriz de Adjacencia 

int RandomInteger(int val)
{
	return rand()%(val);
}

int main()
{
	srand(time(NULL)); 


	ifstream file("Lines.dat");

	vector<int> Degrees(Nv);  
	vector<vector<int>> Neighbors(Nv);	
	vector<int> Frequ_visited(Nv);

	while(getline(file,str))	
	{
		a = stoi(str.substr(0,str.find("  ")));
		b = stoi(str.substr(str.find("  ")+2));		
		Neighbors[a].push_back(b);
		Neighbors[b].push_back(a);
	}
	
	for(int i= 0; i<Nv;i++)
	{
		Degrees[i] = Neighbors[i].size();
		Frequ_visited[i] = 0;

		
	}

	ofstream RWpos ("Visited.dat");
	int pos_init = 0;
	RWpos<<"Visited"<<endl;
	

	for(int t = 0; t<1000000000; t++)
	{
		pos_init = Neighbors[pos_init][RandomInteger(Degrees[pos_init])];
		Frequ_visited[pos_init] += 1;
	}

	for(int i = 0; i<Nv; i++)
	{
		RWpos<<Frequ_visited[i]<<endl;
	}
	
	RWpos.close();

	return 0;
}

