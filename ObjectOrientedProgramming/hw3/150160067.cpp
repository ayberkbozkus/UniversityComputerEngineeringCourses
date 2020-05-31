/* 
		Ayberk Bozkuş 150160067
*/


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Neuron.h"
#include "Layer.h"
#include "Network.h"

using namespace std;

int main(int argc,char**argv)
{
	int numLayers,*numNeuron,*numFunction; // variables to get txt file
	float* input;
	string line[4]; // variables to get txt file
	stringstream line0, line1, line2, line3; // to hold each line
	ifstream file(argv[1]);
	if (file.is_open())
	{
		getline(file, line[0]);
		line0 << line[0];
		line0 >> numLayers;
		getline(file, line[1]);
		line1 << line[1];
		numNeuron = new int[numLayers]; // Freeing up the number of layers
		getline(file, line[2]);
		line2 << line[2];
		numFunction = new int[numLayers];
		getline(file, line[3]);
		line3 << line[3];
		input = new float[numLayers];
		for (int i = 0; i < numLayers; i++)
		{
			line1 >> numNeuron[i];
			line2 >> numFunction[i];
			try  // (throw catch) different value control from 0-2
			{
				if(numFunction[i]<0 || numFunction[i]>2)
				{
					throw numFunction[i];
				}	
			}
			catch(int numf)
			{
				cout<<"Unidentified activation function!"<<endl; // error message
				return 1;
			}
			line3 >> input[i];
		}
		int test=5;
		line3>>test;
		try
		{
			if(test!=5)
			{
				throw test;
			}
		}
		catch(int test1)
		{
			cout<<"Input shape does not match!"<<endl;
			return 1;
		}
		Network Start(numLayers, numNeuron, numFunction, input); // start to layer operations
	}
	return 0;
}