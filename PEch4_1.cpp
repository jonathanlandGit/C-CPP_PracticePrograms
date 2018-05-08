#include <iostream>
using namespace std; 

int main(void)
{
	cout << "What is your first name? ";
	char first_name[20];
	cin.getline(first_name, 20); 
	first_name[19] = '\0';
	
	cout << "What is your last name? ";
	char last_name[20];
	cin.getline(last_name, 20);
	last_name[19] = '\0';
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
