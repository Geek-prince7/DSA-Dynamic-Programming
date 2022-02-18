#include <iostream>
#include<climits>
using namespace std;


int longestIncreasingSubsequence(int* arr, int n)
{
    int *ans=new int[n];
    for(int i=0;i<n;i++)
    {
        ans[i]=0;
    }
    ans[0]=1;
    int max=ans[0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
            {
                if(ans[i]<ans[j])
                {
                    ans[i]=ans[j];
                }
            }
        }
        ans[i]++;
        cout<<"for "<<arr[i]<<" lis is : "<<ans[i]<<endl;
        if(ans[i]>max)
        {
            max=ans[i];
        }
    }
    return max;
}






int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}
