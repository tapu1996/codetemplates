#include<bits/stdc++.h>
using namespace std;
unsigned long long phi[5000009];

// Computes and prints totien of all numbers
// smaller than or equal to n.
void computeTotient(int n)
{
    phi[0]=0;
    // Create and initialize an array to store
    // phi or totient values

    for (long long int i=1; i<=n; i++)
        phi[i] = i; // indicates not evaluated yet
                    // and initializes for product
                    // formula.

    // Compute other Phi values
    for (long long int p=2; p<=n; p++)
    {
        // If phi[p] is not computed already,
        // then number p is prime
        if (phi[p] == p)
        {
            // Phi of a prime number p is
            // always equal to p-1.
            phi[p] = p-1;

            // Update phi values of all
            // multiples of p
            for (long long int i = 2*p; i<=n; i += p)
            {
               // Add contribution of p to its
               // multiple i by multiplying with
               // (1 - 1/p)
               phi[i] = (phi[i]/p) * (p-1);
            }
        }
    }

    // Print precomputed phi values
    for (int i=2; i<=n; i++)
      {
          phi[i] = phi[i-1] + (phi[i]*phi[i]);

      }
     // cout<<phi[2]<<endl;
}


main(){
computeTotient(5000002);

int t;

cin>>t;
for(int tc=1;tc<=t;tc++){
  long long  int a,b;
   scanf("%lld %lld",&a,&b);
    unsigned long long int ans = phi[b]-phi[a-1];
     printf("Case %d: %llu\n",tc,ans);
}

}
