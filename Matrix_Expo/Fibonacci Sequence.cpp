#include <bits/stdc++.h>
using namespace std;
int mat[2][2];
int mod;
void bigmod (int e)
{
    if (e <= 1) return;
    bigmod (e >> 1);
    int tt[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int sum = 0;
            for (int k = 0; k < 2; k++) sum += (mat[i][k] * mat[k][j]) %mod;
            tt[i][j] = sum %mod;
        }
    }

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            mat[i][j] = tt[i][j];


    if (e %2 == 1)
    {
        int temp[2][2];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) temp[i][j] = 0;
        temp[0][0] = 1;
        temp[0][1] = 1;
        temp[1][0] = 1;
        temp[1][1] = 0;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int sum = 0;
                for (int k = 0; k < 2; k++) sum += (tt[i][k] * temp[k][j]) %mod;
                mat[i][j] = sum %mod;
            }
        }
    }
}

int main()
{
    int tes , o = 0;
    scanf("%d", &tes);
    while(tes--)
    {
        o++;
        int a,b ,c, d;

        scanf("%d %d %d %d", &a, &b , &c, &d);
        if(c == 0){
            printf("Case %d: %d\n",o, a);
            continue;
        }
        if(c == 1)
        {
            printf("Case %d: %d\n",o,b);
            continue;
        }
        mat[0][0] = 1;
        mat[0][1] =1;
        mat[1][0] = 1;
        mat[1][1] = 0;
        mod = 1;
        while(d--)
        {
            mod = mod * 10;
        }

       bigmod(c - 1);
        int res = (mat[0][0] * b) % mod + (mat[0][1] * a)%mod;
       printf("Case %d: %d\n",o, res % mod);

    }

}
