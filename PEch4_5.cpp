#include<iostream>
using namespace std;

int main(void)
{
	//create a struct with vars
	struct CandyBar
	{
		char brand[20];
		float weight;
		int calories;
	};

	//now fill it with info
	snack = 
	{
		"Mocha",
		2.3,	
		350
	};


	//now print all this out
	cout << "Our snack brand is " << snack.brand << endl;
	cout << "The weight is " << snack.weight << endl;
	cout << "And it contains " << snack.calories << " calories" << endl;

	return 0;
}
