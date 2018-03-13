/*
Jonathan Land

Output Format

For each pair of  and  values (i.e., for each query), print a single integer denoting the element located at index of the array referenced by . There should be a total of  lines of output.

Sample Input

2 2
3 1 5 4
5 1 2 8 9 3
0 1
1 3
Sample Output

5
9
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
	void foo();
	foo();
}

using namespace std;

void foo()
{
	int N;
	int Q;
	
	scanf("%d%d", &N, &Q);
	
	vector<vector<int> >v(N);
	
	for(int i=0; i<N; i++)
	{
		int M;
		scanf("%d",&M);
		v[i].resize(M);
		
		for(int j=0; j<M ; j++)
		{
			scanf("%d", &v[i][j]);
		}
	}
	
	for(int i=0 ; i<Q; i++)
	{
		int a;
		int b; 
		scanf("%d%d", &a, &b);
		printf("%d\n",v[a][b]);
	}
}