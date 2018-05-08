#include<iostream>
using namespace std;

int main(void)
{
	cout << "How many miles have you driven? ";
	double miles;
	cin >> miles;
	cout << "How many gallons have you used? ";
	double gallons;
	cin >> gallons;
	cout << "Your car has gotten " << miles/gallons << " miles per gallon" << endl;
}