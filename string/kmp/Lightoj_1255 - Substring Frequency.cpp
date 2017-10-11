#include <bits/stdc++.h>
using namespace std;
int prefix[1000006];

void setup (string s)
{
    int i = 0, j = -1;
    prefix[0] =-1;

    while(i < s.size())
    {
        while(j >= 0 && s[i] != s[j])
        {
            j =  prefix[j];
        }
        j++;
        i++;
        prefix[i] =j;
    }
}

int kmp (string s1, string s2)
{


    setup(s2);
    int i = 0, j = 0;
    int cnt = 0;
    while(i < s1.size())
    {

        while(j >= 0 && s1[i] != s2[j])
        {
            j = prefix[j];
        }

        j++;
        i++;

        if(j == s2.size()){
          cnt++;
          //j = prefix[j];
        }
    }
    return cnt;
}
int main()
{
    int tes,o=0;
    cin >> tes;
    while(tes--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        int ans=  kmp(s1, s2);


        printf("Case %d: %d\n",++o, ans);
    }
}
