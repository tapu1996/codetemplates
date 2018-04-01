#include<bits/stdc++.h>
using namespace std;

 /// a^b mod m where a,b both are large (100+ digits )
unsigned long int modtoint(string a,unsigned long int mod){
///for converting a to a%m (where a is large)
unsigned long int res=0;
unsigned long  int siz=a.size();
for(unsigned long int i=0;i<siz;i++){
char d=a[i];
 unsigned long int digit = d - '0';
 res = res*10+digit;

 if(mod<=res) res=res%mod;

}
return res;
}

unsigned long int bigmod(unsigned long int  b,unsigned long int p,unsigned long int m ) {
    if ( p == 0 ) return 1%m;

    if ( p % 2 == 0 ) {


      unsigned long  int y = bigmod ( b, p / 2, m );
        return ( y * y ) % m;
    }
    else {
       unsigned long int k = b;
        return ( k * bigmod( b, p - 1, m ) ) % m;
    }
}

unsigned long int hornet(unsigned long int num,string b,unsigned long int m)
{
   unsigned long int len = b.size();
   unsigned long int k = b[0] - '0';

 unsigned long  int  ans = bigmod(num,k,m);
  //  string ans1 = tos(ans);
    for(unsigned long int i = 1;i<len;i++){

        unsigned long int k = b[i] - '0';
        ans = ((bigmod(ans,10,m)%m ) * (bigmod(num,k,m)%m) )%m;
        //ans1 = tos(ans);
    }

    return ans;

}
main()
{



string a,b;
unsigned long int m;
while(cin>>a>>b>>m){


if(a=="0" && b=="0" && m==0)break;
unsigned long int ab = modtoint(a,m);
//cout<<ab<<endl;
//cout<<ab<<endl;
cout<<hornet(ab,b,m)<<endl;

}


}
