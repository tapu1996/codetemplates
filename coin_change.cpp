// Unlimited supply of coins
#include<bits/stdc++.h>
using namespace std;
main()
{
   int arr[]={1,5,10,25,50}; // coins
   int coin_change[5][7490]; // have tp make 7489 at most

   for(int i=0;i<5;i++){
    coin_change[i][0]=1;
   }

   for(int i=0;i<5;i++) {
    for(int j=1;j<7490;j++){
            int dp;
            if(i==0) dp = 0 ;
            else dp = coin_change[i-1][j];
          //  cout<<dp<<endl;

        if(arr[i]>j) {

            coin_change[i][j]=dp;
        }
        else coin_change[i][j] = dp + coin_change[i][j-arr[i]];

    }

   }

   int n;
   while(cin>>n){
    cout<<coin_change[4][n]<<endl;
   }

}
