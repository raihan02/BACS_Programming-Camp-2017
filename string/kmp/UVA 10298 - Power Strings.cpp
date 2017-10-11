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
int main()
{
   string s;

   while(cin >> s)
   {
       if(s == ".")break;
       setup(s);
       int x = prefix[s.size()];
        int ans = s.size() - x;

        cout<< s.size()/ans;
       cout<< endl;
   }
}
