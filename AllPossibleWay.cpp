#include <iostream>
#include<cmath>
using namespace std;
//#include "solution.h"
int getAllWays(int a, int b,int cno,int csum) {
	// Write your code here

    int ways=0;
    int p;
    for(int i=1;pow(i,b)<a;i++)
    {
        p=pow(cno,b);
        cno=i;
        ways+=getAllWays(a,b,cno+1,csum+p);

    }
    if(csum+p==a)
    {
        ways++;
    }
    return ways;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b,1,0);
}
