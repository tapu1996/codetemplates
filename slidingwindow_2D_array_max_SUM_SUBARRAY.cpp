
///time complexity o(n)

#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,m;
    while(cin>>n){
        m=n;
            if(n==0 ) break;
        int v[n+1][m+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>v[i][j];
                //if(v[i][j]==0)v[i][j]=1;
                //else v[i][j]=0;
            }
        }

         for(int i=1;i<=n;i++)
        {
            int cumsum=0;
            for(int j=1;j<=m;j++){
             cumsum+=v[i][j];
             v[i][j]=cumsum;
            }
        }


   for(int i=1;i<=m;i++)
        {
            int cumsum=0;
            for(int j=1;j<=n;j++){
             cumsum+=v[j][i];
             v[j][i]=cumsum;
            }
        }
        int res=0;
        for(int i=0;i<=m;i++)v[0][i]=0;
        for(int i=0;i<=n;i++)v[i][0]=0;
        for(int r1=1;r1<=n;r1++){
            for(int c1=1;c1<=m;c1++){
                for(int r2=r1;r2<=n;r2++){
                    for(int c2=c1;c2<=m;c2++){
int sot=0;

                    sot=v[r2][c2]-v[r1-1][c2]-v[r2][c1-1]+v[r1-1][c1-1];

                        res=max(res,sot);

                    }
                }
            }
        }
        cout<<res<<endl;

    }


}
