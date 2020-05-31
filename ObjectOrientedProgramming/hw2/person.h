/*
		Ayberk Bozkuş
		150160067
*/


#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	string name;
	string surname;
	Person();
	~Person();
};

Person::Person() // empty constructor
{
}

Person::~Person(){} // empty destructor






class Owner: public Person // subclass of Person
{
protected:
	double ownership; // rate owners
public:
	void set_ownership(double);
	double get_ownership();
	Owner(const string, const string);
	Owner(); // empty constructor
	~Owner(); // empty destructor
};

Owner::Owner()
{

}

Owner::~Owner(){}

Owner::Owner(const string name1, const string surname1)
{
	this->name = name1;
	this->surname = surname1;
}

void Owner::set_ownership(double numOwners)
{
	ownership = 100.0 / numOwners; // rate per owner
}

double Owner::get_ownership()
{
	return ownership; // take ownership
}






class Courier : public Person
{
public:
	Courier* next;
	int num_of_courier;
	string vehicle_type;
	Courier();
	~Courier();
	Courier(const string, const string, const string);
	bool operator == (Courier);
};

Courier::Courier(){}

Courier::~Courier(){}

Courier::Courier(const string name1, const string surname1, const string vehicle1)
{
	if (!(vehicle1 == "bicycle" || vehicle1 == "motorcycle" || vehicle1 == "car"))
	{
		cout << "Invalid vehicle type!" << endl;
		return;
	}
	this->name = name1;
	this->surname = surname1;
	this->vehicle_type = vehicle1;
}

bool Courier::operator == (Courier Courier1)
{
	if (Courier1.name != name || Courier1.surname != surname || Courier1.vehicle_type != vehicle_type)
		return false;
	else
		return true;
}
