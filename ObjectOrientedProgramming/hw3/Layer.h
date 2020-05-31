#include <iostream>
using namespace std;

class Layer
{
public:
	Neuron* neurons;
	Layer(){}
	Layer(int, int, int, float*); // add and print new layer (all values come to the function and transactions are done inside)
	~Layer();
};

Layer::Layer(int numLayer, int numNeuron, int numFunction, float* values)
{
	if (numFunction == 0) // for activation type number
	{
		neurons = new SigmoidNeuron[numNeuron];
		for (int i = 0; i < numNeuron; i++)
		{
			SigmoidNeuron newS(numLayer, values[i]);
			neurons[i] = newS;
		}

	}
	else if (numFunction == 1)// for activation type number
	{
		neurons = new  LReluNeuron[numNeuron];
		for (int i = 0; i < numNeuron; i++)
		{
			LReluNeuron newS(numLayer, values[i]);
			neurons[i] = newS;
		}
	}
	else// for activation type number
	{
		neurons = new  ReluNeuron[numNeuron];
		for (int i = 0; i < numNeuron; i++)
		{
			ReluNeuron newS(numLayer, values[i]);
			neurons[i] = newS;
		}
	}
	cout << "Layer " << numLayer << ":" << endl; // print values of layer
	for (int i = 0; i < numNeuron; i++)
		cout << neurons[i].getActivate_value() << endl;
}

Layer::~Layer() // destruction neuron array
{
	delete[]neurons;
}