#include <bits/stdc++.h>
using namespace std;
queue <int> q[1005];
map <int, int> mp;
queue<int> qq;
int main()
{
    int tes,o=1;

    while(cin >> tes)
    {
       if(tes==0)
        break;

        for(int i = 1; i <= tes; i++)
        {
            int n;

            cin >> n;

            for(int j = 0; j < n; j++)
            {
                int x;
                cin >> x;
               //q[i].push(x);
                mp[x] = i;
            }
        }
        /*
       for(int i = 0; i < tes; i++)
       {
           printf("%d ", i);

           while(q[i].size() > 0)
           {
               cout<<q[i].front() << " ";
               q[i].pop();
           }
           cout<< endl;
       }
       */
       cout << "Scenario #" << o++ << '\n';
       string s;
       int n;
       queue <int> qq;
       while(1)
       {
          cin >> s;

          if(s == "STOP")
          {
              break;
          }

          if(s == "ENQUEUE")
          {
              cin >> n;
              int u = mp[n];
              if(q[u].empty())
              {
                  qq.push(u);
              }

              q[u].push(n);

          }
          if(s == "DEQUEUE")
          {
             int x = qq.front();
             if(q[x].size() == 0)
             {
                 qq.pop();
             }
              x = qq.front();
              if(qq.size() > 0)
              {
                  cout<<q[x].front()<< endl;
                  q[x].pop();
              }

          }
       }
       while(qq.size() > 0)
        qq.pop();
       for(int p = 0; p <= tes; p++)
       {
           while(q[p].size() > 0)
           {
               q[p].pop();
           }
       }
       mp.clear();
       cout<< endl;
    }


}
