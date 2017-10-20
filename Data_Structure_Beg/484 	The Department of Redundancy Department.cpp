#include <bits/stdc++.h>
using namespace std;
queue <int> q[1005];
map <int, int> mp;
queue<int> qq;
vector <int> v;
int arr[100000007];
int main()
{
    int n;
    map <int , int> mp;
    map <int, int> :: iterator it;

    while(cin >> n)
    {
        
        if(mp.count(n) == 0)
        {
            mp[n] = 1;
            v.push_back(n);

        }
        else
            mp[n] = mp[n] + 1;
    }
    for(int i = 0; i < v.size(); i++)
    {
        cout<<v[i] << " " << mp[v[i]] << endl;
    }
    v.clear();
    mp.clear();


}
