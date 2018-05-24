/*
Jonathan Land

Input will contain two integers, separated by a newline.
Input/ouput will be automatically handled. 

Sample Input

4
5
Sample Output

9
1
*/

#include <stdio.h>
#include <stdlib.h>

void update(int *a,int *b) 
{    
	//two vars that perform on operations on pointer args
    int sum = *a + *b; 
    int difference = abs(*a - *b);
    
    //can't use return statements here, so we have
    //set the vars equal to the pointer args to be referenced in main
    *a = sum;
    *b = difference; 
}

int main() 
{
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
