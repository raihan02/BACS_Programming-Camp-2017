#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
deque <ll> d;
int arr[100000007];
int main()
{
    ll p, c;
    int o = 1;

    while(cin >> p >> c)
    {
        if(!p && !c)
            break;

        for(int i = 1; i <= p && i <= 1000; i++)
            d.push_back(i);
        char ch;

        cout<<"Case "<<o++<<":"<< endl;
        while(c--)
        {
            cin >> ch;

            if(ch == 'N')
            {
                int a = d.front();
                d.pop_front();
                d.push_back(a);

                cout<<a<< endl;
            }
            else if(ch == 'E')
            {
                ll x;
                cin >> x;
                deque<ll> :: iterator it;
                for(it = d.begin(); it != d.end(); it++)
                {
                    if(*it ==x){
                        d.erase(it);
                        break;
                    }
                }
                d.push_front(x);
            }
        }
        d.clear();
    }


}
