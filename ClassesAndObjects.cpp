/*
Program that takes user input to include grades, then compared to the first set of scores, 
prints out how many students scored higher

*/
#include <cstdio>
#include <iostream>

using namespace std;

class Student 
{
    private:
    	//array to hold max amt of grades included
        int grades[5];
    public:
    	//input method to include grades 
        void input() 
        {
            cin >> grades[0] >> grades[1] >> grades[2] >> grades[3] >> grades[4];
        }
	
		//method to calculate sum
        int calculateTotalScore() 
        {
            int sum = 0;
            for (int i = 0; i < 5; i++) 
            {
                sum += grades[i];
            }
            return sum;
        }
};

int main() 
{
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++)
    {
        s[i].input();
    }

    // calculate score
    int student_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++)
    {
        int total = s[i].calculateTotalScore();
        if(total > student_score)
        {
            count++;
        }
    }

    // print result
    cout << count;
    return 0;
}