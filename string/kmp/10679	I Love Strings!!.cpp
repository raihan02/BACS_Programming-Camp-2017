#include <bits/stdc++.h>
using namespace std;
int prefix[1000006];
void setup (string s)
{
    prefix[0] = -1;
    int i = 0, j = -1;
    while(i < s.length())
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
bool kmp (string s1, string s2)
{
    int n, m;
    n  = s1.size();
    m = s2.size();
   int i = 0, j =0 ;

    setup(s2);
    while(i < n)
    {
        while(j >= 0 && s1[i] != s2[j])
        {
            j = prefix[j];
        }
        i++;
        j++;
        if(j == m)
            return true;
    }
    return false;
}
int main()
{
    int tes;
    scanf("%d", &tes);
    while(tes--)
    {
        string s1;

        cin >> s1;

        int q;
        cin >> q;

        while(q--)
        {
            string s2;

            cin >> s2;

            if(kmp(s1, s2) == true)
                cout<<"y"<< endl;
            else
                cout<< "n" << endl;
        }
    }
}
