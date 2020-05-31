#include <iostream>
#include <math.h>

using namespace std;

class Neuron // abstract base class
{
protected:
	float Activate_value,Zpoint; // neuron activate value and z0 point
public:
	virtual void activate(float z) = 0;
    Neuron(){}
    float getActivate_value() { return Activate_value; }
    float getZpoint() { return Zpoint; }
    ~Neuron(){}
};

class SigmoidNeuron :public Neuron
 {
 public:
     void activate(float z0)
     {
         Activate_value = z0;
     }
     SigmoidNeuron(int num,float Z)
     {
         if (num == 0) // contorl first layer 
         {
             Zpoint = Z;
             activate(Zpoint);
         }
         else
         {
             Zpoint = Z;
             activate(1 / (1 + exp(-Zpoint)));
         }
     }
     SigmoidNeuron(){}
 };

class LReluNeuron :public Neuron
{
public:
    void activate(float z0)
    {
        Activate_value = z0;
    }
    LReluNeuron(int num, float Z) 
    {
        if (num == 0)// contorl first layer 
        {
            Zpoint = Z;
            activate(Zpoint);
        }
        else
        {
            Zpoint = Z;
            if (Zpoint * 0.1 < Z)
                activate(Z);
            else
                activate(Z * 0.1);
        }
    }
    LReluNeuron(){}
};

class ReluNeuron :public Neuron
{
public:
    void activate(float z0)
    {
        Activate_value = z0;
    }
    ReluNeuron(int num,float Z) 
    {
        if (num == 0)// contorl first layer 
        {
            Zpoint = Z;
            activate(Zpoint);
        }
        else
        {
            Zpoint = Z;
            if (Zpoint < 0)
                activate(0);
            else
                activate(Zpoint);
        }
    }
    ReluNeuron(){}
};

 