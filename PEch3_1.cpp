#include <iostream>
using namespace std;

double inchesToFeet(double num);
void inchesToFeet2(int height_inches);

int main()
{
	double inchHeight;

	cout << "Please enter your height in inches: "; 
	cin >> inchHeight;
	double total = inchesToFeet(inchHeight);

	cout << total << endl; 

	cout << endl;

	cout<< "Or" << endl;

	inchesToFeet2(inchHeight);
}

double inchesToFeet(double num)
{
	const double convertFactor = 0.083333333333333;
	return num * convertFactor; 
}

void inchesToFeet2(int height_inches)
{
	const int inches_per_foot = 12;
	int feet = height_inches / inches_per_foot; 
	int inches = height_inches % inches_per_foot;

	cout << feet << " ft" << endl;
	cout << inches << " inches" << endl; 
}