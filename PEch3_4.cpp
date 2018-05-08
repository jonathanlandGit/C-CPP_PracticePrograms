#include <iostream>
using namespace std;

//program that asks user input for seconds and then
//prints the equivalent in days, seconds, hours, and minutes

int main(void)
{
	const int secondsPerMinute = 60;
	const int secondsPerHour = 60 * 60;
	const int secondsPerDay = 60 * 60 * 24;

	cout << "Please enter the number of seconds: ";
	long int total_seconds;
	cin >> total_seconds;
	
	int days, hours, minutes, seconds;
	days = total_seconds / secondsPerDay;
	hours = (total_seconds % secondsPerDay) / secondsPerHour;
	minutes = (total_seconds % secondsPerHour) / secondsPerMinute;
	seconds = (total_seconds % secondsPerMinute);

	cout << total_seconds << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds." << endl;
	return 0;
}