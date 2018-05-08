#include<iostream>
#include<string>
using namespace std; 

int main()
{
	cout << "Enter your first name: ";
	char first_name[20];
	cin.getline(first_name,20);
	first_name[19] = '\0';
	cout << "Enter your last name: ";
	char last_name[20];
	cin.getline(last_name,20);
	last_name[19] = '\0';
	char full_name[40];
	strcpy(full_name, strcat(strcat(last_name, ", "), first_name));
	cout << "Here's the information on a single string: " 
	     << full_name 
	     << endl;
	return 0;
}