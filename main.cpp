#include<iostream>
#include<vector>


using namespace std;


class Vehicle
{
public:
	virtual void display() = 0;
	virtual ~Vehicle() {};
};


class Truck : public Vehicle
{
private:
	int length, weight;

public:
	Truck(int length, int weight) : length(length), weight(weight) {};
	void display();
};

void Truck::display()
{
	cout << "This is Truck" << endl;
}


class Car : public Vehicle
{
private:
	int length, weight;

public:
	Car(int length, int weight) : length(length), weight(weight) {};
	void display();
};

void Car::display()
{
	cout << "This is Car" << endl;
}


int main()
{

	Vehicle *V1 = new Truck(100, 200);
	Vehicle *V2 = new Car(10, 5);

	V1->display();
	V2->display();

	vector<Vehicle*> vec{ V1, V2 };

	
	for (auto i : vec)
		i->display();


	int repeat = 10;
		
	do
	{
		V1->display();
	} while (--repeat);
	
	repeat = 10;

	while (repeat--)
	{
		V2->display();
	}



	int tab[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int *tabl = new int[5];

		
	int *ptr = tab;
	cout << *ptr << endl;
	cout << *(ptr + 3) << endl;
	
	ptr += 4;
	cout << *(ptr - 2) << endl;


	double d = 5.6547;
	int i = static_cast<int>(d);
	cout << i << endl;

		

	for (auto j : vec)
		delete j;	

	delete tabl;


	getchar();
	return 0;
}
