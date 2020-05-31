#include <iostream>

class Network
{
public:
	Layer* layers;
	Network(int numLayer,int*numNeuorns,int*numFunctions,float* valueinputs)
	{
		float keepZ, * keepInputs; // to calculate new Z values
		layers = new Layer[numLayer];
		for (int i = 0; i < numLayer; i++)
		{
			if (i == 0)
			{
				Layer addLayer(i, numNeuorns[i], numFunctions[i], valueinputs); // add to first layer
				layers[i] = addLayer;
				keepZ = createMatrixop(valueinputs, numNeuorns[i + 1], numNeuorns[i]);
			}
			else
			{
				keepInputs = new float[numNeuorns[i]];
				for (int n = 0; n < numNeuorns[i]; n++)
				{
					keepInputs[n] = keepZ;
				}
				Layer addLayer(i, numNeuorns[i], numFunctions[i], keepInputs); // add new layer
				layers[i] = addLayer;
				for (int a = 0; a < numNeuorns[i]; a++)
				{
					keepInputs[a] = addLayer.neurons->getActivate_value();
				}
				if(i+1<numLayer)
					keepZ = createMatrixop(keepInputs, numNeuorns[i + 1], numNeuorns[i]);
			}
		}
		
	}
	Network(){}
	~Network();
	float createMatrixop(float* values, int row, int col) // calculate new Z values
	{
		float z = 0;
		float** w, ** b;
		w = new float* [row];
		b = new float* [row];
		for (int i = 0; i < row; i++)
		{
			w[i] = new float[col];
			b[i] = new float[1];
			for (int j = 0; j < col; j++)
			{
				w[i][j] = 0.1;
				if (j == 0)
				{
					b[i][j] = 0.1;
				}
			}
		}
		for (int k = 0; k < row; k++)
		{
			for (int l = 0; l < col; l++)
			{
				z = z + w[k][l] * values[l];
			}
			return z + b[k][0];
		}
		return 0;
	}

	void deleteLayer() // to prevent memory leakage
	{
		delete[] this->layers;
	}
};

Network::~Network()
{
	//Since layers arrayi mainde was first created, it needs to be deleted in cpp

	//delete[] layers;
}