/*
Jonathan Land

Write a function int max_of_four(int a, int b, int c, int d)
 which reads four arguments and returns the greatest of them.

Sample Input

3
4
6
5
Sample Output

6

*/

#include <iostream>
#include <cstdio>
using namespace std;

int max_of_four(int a, int b, int c, int d)
{
    int maxNum = 0;
    
    if (a > b && a > c && a > d)
    {
       maxNum = a;
    }
    
    if (b > a && b > c && b > d)
    {
       maxNum = b;
    }
    
    if (c > a && c > b && c > d)
    {
        maxNum = c;
    }
    
    if (d > a && d > b && d > c)
    {
       maxNum = d;
    }
    
    return maxNum; 
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}