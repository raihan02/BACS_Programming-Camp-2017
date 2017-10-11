#include <bits/stdc++.h>
using namespace std;
int prefix[1000006];

void setup (string s)
{
    int  i = 0, j = -1;
    prefix[0] =-1;

    while(i < s.size())
    {
        while(j >= 0 && s[i] != s[j])
        {
            j = prefix[j];
        }
        i++;
        j++;
        prefix[i] = j;
    }
}
int main()
{
    int tes;
    cin >> tes;

    while(tes--)
    {
        string s;

        cin >> s;
        setup(s);


        int ans;
        int x =s.size()-  prefix[s.size()];
        if(s.size() % x == 0)
            ans = x;
        else
            ans = s.size();

        cout<< ans << endl;

        if(tes)
            cout<< endl;
    }
}
