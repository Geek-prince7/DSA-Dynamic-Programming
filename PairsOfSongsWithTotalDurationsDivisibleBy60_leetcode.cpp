#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
int numPairsDivisibleBy60(vector<int>& time) {
    unordered_map<int,int> mymap;
    int n=time.size();
    int count=0;
    for(int i=0;i<n;i++)
    {
        time[i]=time[i]%60;
        if(mymap.count(time[i]))
        {
            count+=mymap[time[i]];
        }
        ++mymap[60-time[i]];
    }
    return count;

}
int main()
{
    vector<int> time;
    while(1)
    {
        int n;
        cin>>n;
        if(n==-222)
        {
            break;
        }
        time.push_back(n);
    }
    cout<<numPairsDivisibleBy60(time);


}
