#include <iostream>
#include <cstdio>
/*
    Jonathan Land

 
 Input Format

You will be given two positive integers,  and  (), separated by a newline.

Output Format

For each integer  in the interval  :

If , then print the English representation of it in lowercase. That is "one" for , "two" for , and so on.
Else if  and it is an even number, then print "even".
Else if  and it is an odd number, then print "odd".
Note: 

Sample Input

8
11
Sample Output

eight
nine
even
odd
*/

using namespace std;

int main() 
{
    //declare two ivars
    int a;
    int b;
    
    //take user input
    cin >> a >> b;

    //loop through the inputs
    for (int i = a; i <= b; i++) 
    {
        //if 1 is less than the user input and also less than or equal to 9, then
        //fall into the loop and complete the ifs
        if (1 <= i && i <= 9) 
        {
            if (i == 1) 
            {
                cout << "one";
            }
            else if (i == 2) 
            {
                cout << "two";
            }
            else if (i == 3) 
            {
                cout << "three";
            }
            else if (i == 4) 
            {
                cout << "four";
            }
            else if (i == 5) 
            {
                cout << "five";
            }
            else if (i == 6) 
            {
                cout << "six";
            }
            else if (i == 7) 
            {
                cout << "seven";
            }
            else if (i == 8) 
            {
                cout << "eight";
            }
            else if (i == 9) 
            {
                cout << "nine";
            }
        }
        //checking for greater than 9, and if so fall into 
        // loop and check if even or odd and print
        else if (i > 9) 
        {
            if (i % 2 == 0) 
            {
                cout << "even";
            }
            else 
            {
                cout << "odd";
            }
        }

        cout << "\n";
    }

    return 0;
}