#include <bits/stdc++.h>
using namespace std;
vector <int> vc, vt;
int dp[10][180][2];
long long get (long long n, vector <int> &d)
{
    while(n >0)
    {
        d.push_back(n % 10);
        n = n / 10;
    }
}
long long dpp (int id , int sum , int t , vector <int> &d)
{
    if(id == -1)
        return sum;

    if(dp[id][sum][t] != -1 && t != 1)
        return dp[id][sum][t];

    int k, newd;

    if(t == 1)
        k = d[id];
    else
        k = 9;
    long long res = 0;
    for(int i = 0; i <= k; i++)
    {
        if(d[id] == i)
            newd = t;
        else
            newd = 0;

        res += dpp (id-1, sum + i, newd, d);
    }
    if(!t)
        dp[id][sum][t] = res;

    return res;
}

long long fun (int a, int b)
{
    vector <int> v1, v2;
    v1.clear();
    v2.clear();

    memset(dp, -1, sizeof dp);
    get(a - 1 , v1);
    long long ans1 = dpp (v1.size() - 1, 0, 1, v1);

    get(b, v2);

    long long ans2 = dpp (v2.size() - 1, 0, 1, v2);

    return ans2 - ans1;



}
int main()
{
    long long a, b;

    cin  >> a >> b;
   long long ans =  fun(a, b);
    cout<< ans << endl;
}
