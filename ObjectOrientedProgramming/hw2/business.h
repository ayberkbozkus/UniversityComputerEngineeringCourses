/*
		Ayberk Bozkuş
		150160067
*/


#include <iostream>
#include <string>

using namespace std;

class Business : public Courier, public Owner // class business for all operations
{
public:
	string Bname;
	Owner* arr;
	Courier* head;
	string address;
	int number_of_owners;
	Business();  // constructor
	~Business(); // destructor
	Business(const string, const string, Owner*, const int); // starting the business
	void list_owners(); // list all of the owners
	void list_couriers(); // list all of the couriers
	void hire_courier(Courier); // add a new courier
	void fire_courier(Courier); // search courier for fir
	int calculate_shipment_capacity(); // calculate total capacity
	void operator()(); // print business name, adress and owners information
	Courier operator[](int); // choose a courier
};

Business::Business(){} // empty constructor

Business::~Business() // destructor for lists(*head and *arr)
{
	while (head)
	{
		Courier* temp = head;
		head = head->next;
		delete temp;
	}
	delete[]arr;
}

Business::Business(const string bus_name, const string bus_adress, Owner* own_array, const int num_Owner)
{
	this->Bname = bus_name;
	this->address = bus_adress;
	this->number_of_owners = num_Owner;
	this->arr = own_array;
	set_ownership(num_Owner); // using setter for protected attribute
}

void Business::list_owners()
{
	double keep = get_ownership();
	for (int i = 0; i < number_of_owners; i++)
	{
		cout << arr[i].name << " " << arr[i].surname << " " << keep << endl;
	}
}

void Business::list_couriers()
{
	Courier* temp = head;
	while (temp)
	{
		cout << temp->name << " " << temp->surname << " " << temp->vehicle_type << endl;
		temp = temp->next;
	}
}

void Business::hire_courier(Courier Courier1)
{
	bool flag = true; // control vehicle type
	if (Courier1.vehicle_type == "car" || Courier1.vehicle_type == "bicycle" || Courier1.vehicle_type == "motorcycle")
		flag = false;
	if (!flag)
	{
		Courier* temp = new Courier(); // space up for new courier
		temp->name = Courier1.name;
		temp->surname = Courier1.surname;
		temp->vehicle_type = Courier1.vehicle_type;
		if (head == NULL)
		{
			head = temp;
			head->next = NULL;
		}
		else
		{
			Courier* cur = head;
			while (cur)
			{
				if (cur->next)
					cur = cur->next;
				else
				{
					cur->next = temp;
					temp->next = NULL;
					cur = temp->next;
				}
			}
		}
	}
}

void Business::fire_courier(Courier Courier1)
{
	Courier* temp = head;
	Courier cur;
	bool loop = true;
	bool check; // for testing operator ==
	while(loop)
	{
		cur.name = temp->name;
		cur.surname = temp->surname;
		cur.vehicle_type = temp->vehicle_type;
		check = (cur == Courier1);
		if (check)
			break;
		temp = temp->next;
		if (!temp || check)
			loop = false;
	}
	if (check) // if the objects are equal
	{
		if (temp == head)
		{
			head = head->next;
			delete temp;
		}
		else
		{
			Courier* keep = head;
			while (keep->next != temp)
				keep = keep->next;
			keep->next = temp->next;
			delete temp;
		}
	}
	else
		cout << "The courier you tried to fire was not found!" << endl; // error message
}

int	Business::calculate_shipment_capacity()
{
	Courier *temp = head;
	int capacity = 0;
	while (temp)
	{
		if (temp->vehicle_type == "car")
			capacity += 200;
		else if (temp->vehicle_type == "bicycle")
			capacity += 10;
		else
			capacity += 35;
		temp = temp->next;
	}
	return capacity;
}

void Business::operator() ()
{
	cout << Bname << " " << address << endl;
	list_owners();
	list_couriers();
}

Courier Business::operator[](int index) // select a courier and return it
{
	Courier cur,*temp=head;
	int traverse=0;
	while (temp)
	{
		if (traverse == index)
		{
			cur.name = temp->name;
			cur.surname = temp->surname;
			cur.vehicle_type = temp->vehicle_type;
			return cur;
		}
		else
		{
			temp = temp->next;
			traverse++;
		}
	}
	cout << "No courier found for the given index!" << endl;
	return cur;
}
