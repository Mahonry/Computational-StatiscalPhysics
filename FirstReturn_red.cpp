#include<cstdlib>
#include<fstream> 
#include<iostream>
#include<vector>
#include <ctime>
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


	ifstream file("./Data/Random Walk Network 1/Lines.dat");

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


	for(int i = 0; i< Nv; i++)
	{
		string name = "./Data/FRT/T_" + to_string(i) + ".dat";
		ofstream FRT_data (name);
		FRT_data<<"Nodo"<<" "<<"t"<<endl;
		int pos_init = i;
		int target = i;
		cout<<i<<endl;
		
		for(int r = 0; r<100000; r++)
		{
			int t = 0;
			if(pos_init == target)
			{
				pos_init = Neighbors[pos_init][RandomInteger(Degrees[pos_init])];
				t += 1;
				while(pos_init != target)
				{
					pos_init = Neighbors[pos_init][RandomInteger(Degrees[pos_init])];	
					t+=1;			
				}
			}
			else
			{
				while(pos_init != target)
				{
					pos_init = Neighbors[pos_init][RandomInteger(Degrees[pos_init])];
					t+=1;
				}		
			}
			FRT_data<<i<<" "<<t<<endl;;
	
		}
		FRT_data.close();
	}


	return 0;
}

