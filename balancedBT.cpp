#include <iostream>
#include<cmath>
using namespace std;

//#include "solution.h"

long mod=pow(10,9)+7;
int balancedBTs(int n) {
    // Write your code here
    if(n==0 ||n==1)
    {
        return 1;
    }
    int ans1=balancedBTs(n-1);
    int ans2=balancedBTs(n-2);
    int out1=int(((long)(ans1)*ans1)%mod);
    int out2=int(((long)(ans1)*ans2*2)%mod);
    return (out1+out2)%mod;


}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}
