

#include<iostream>
#include<string>
using namespace std; 

int main(void)
{
	cout << "What is your first name? ";
	string first_name;
	getline(cin, first_name);

	cout << "What is your last name? ";
	string last_name;
	getline(cin, last_name);

	cout << "What letter grade do you deserve? ";
	char grade;
	cin >> grade;

	cout << "What is your age? ";
	int age;
	
	cin >> age;
	
	cout << "Name: " << last_name << ", " << first_name << endl
	     << "Grade: " << char (grade + 1) << endl
	     << "Age: " << age << endl;
	return 0;
}
