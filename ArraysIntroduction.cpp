#include <cmath>
#include <iostream>

/*

Jonathan Land

Output Format

Print the  integers of the array in the reverse order in a single line separated by a space.

Sample Input

4
1 4 3 2
Sample Output

2 3 4 1
*/

using namespace std;

int main() 
{
    int SIZE = 0;
    cin >> SIZE; 
    int arr[SIZE];
        
    for (int i = 0; i < SIZE; i++)
    {
        cin >> arr[i];
    }
        
    for (int i = SIZE - 1; i > 0; i--) 
    {
        cout << arr[i];
        cout << " ";
    }

    cout << arr[0];

    return 0;
}