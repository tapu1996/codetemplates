//idea is to use only the factors of the numbers

int sieve[15000005];
void primeSieve ( int n ) {
    sieve[0] = sieve[1] = 1;

    prime.push_back(2);
    for ( int i = 4; i <= n; i += 2 ) sieve[i] = 1;

    int sqrtn = sqrt ( n );
    for ( int i = 3; i <= sqrtn; i += 2 ) {
        if ( sieve[i] == 0 ) {
            for ( int j = i * i; j <= n; j += 2 * i ) sieve[j] = 1;
        }
    }

 //   for ( int i = 2; i <= 15000004; i += 2 ) if ( sieve[i] == 0 ) prime.push_back(i);
      for(int i=2;i*i<=15000004;i++){
            if(sieve[i]==0){
                for(int j=2*i;j<=15000004;j+=i){
                    sieve[j]=i;
                }
            }
        }
        for(int i=0;i<=15000004;i++) {
            if (sieve[i] == 0) {
                sieve[i] = i;
            }
        }
}


void factorize(int num) {
    while(num>1){

        int pr = sieve[num];
        aa[pr]++;
        ans  = max(ans,aa[pr]);
        while(num%pr==0){
            num=num/pr;
        }
    }
    
    }
