

#include<iostream>
using namespace std;

struct CandyBar
{
	char brand[20];
	float weight;
	int calories;
};

int main(void)
{
	CandyBar snacks[3] = {{"Twix", 1.1, 200}, {"Snickers", 2.5, 300}, {"Three Musketeers", 2.1, 150}};
	
	cout << "For our first snack: " << endl;
	cout << "Our snack brand is " << snacks[0].brand << endl;
	cout << "The weight is " << snacks[0].weight << endl;
	cout << "And it contains " << snacks[0].calories << " calories" << endl << endl;

	cout << "For our second snack: " << endl;
	cout << "Our snack brand is " << snacks[1].brand << endl;
	cout << "The weight is " << snacks[1].weight << endl;
	cout << "And it contains " << snacks[1].calories << " calories" << endl << endl;

	cout << "For our third snack: " << endl;
	cout << "Our snack brand is " << snacks[2].brand << endl;
	cout << "The weight is " << snacks[2].weight << endl;
	cout << "And it contains " << snacks[2].calories << " calories" << endl;

	return 0;
}
