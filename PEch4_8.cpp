

#include<iostream>
struct pizza 
{
	char name[20];
	float diameter;
	float weight;
};

int main(void)
{
	using namespace std; 
	//pizza pie;
	pizza * pie = new pizza;
	
	cout << "What is the diameter of the pizza? ";
	cin >> pie->diameter;
	cin.get();

	cout << "What is the name of the pizza company? ";
	cin.getline(pie->name, 20);
	
	cout << "What is the weight of the pizza? ";
	cin >> pie->weight;
	
	cout << "The name of the pizza company is " << pie->name << endl
	     << "The diameter is " << pie->diameter << endl
	     << "The weight is " << pie->weight << endl;

	delete pie;	
	
	return 0;
}
