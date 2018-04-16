/// Sieve : For generating all primes

vector<int> prime; /*Stores generated primes*/
char sieve[SIZE]; /*0 means prime*/
void primeSieve ( int n ) {
    sieve[0] = sieve[1] = 1; /*0 and 1 are not prime*/
 
    prime.push_back(2); /*Only Even Prime*/
    for ( int i = 4; i <= n; i += 2 ) sieve[i] = 1; /*Remove multiples of 2*/
 
    int sqrtn = sqrt ( n );
    for ( int i = 3; i <= sqrtn; i += 2 ) {
        if ( sieve[i] == 0 ) {
            for ( int j = i * i; j <= n; j += 2 * i ) sieve[j] = 1;
        }
    }
 
    for ( int i = 3; i <= n; i += 2 ) if ( sieve[i] == 0 ) prime.push_back(i);
}

///factorization of a number
vector<int>factors;
void factorize( int n ) {
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
    if ( sieve[n] == 0 ) break; /*Checks if n is prime or not*/
        if ( n % prime[i] == 0 ) {
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                factors.push_back(prime[i]);
            }
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1 ) {
        factors.push_back(n);
    }
}

///Number of divisors
///formula : σ(N)=(a1+1)×(a2+1)×...(ax+1) ex: N=252=2^2×3^2×7 . NOD(N)=(2+1)×(2+1)×(1+1)=18.

int NOD ( int n ) {
    int sqrtn = sqrt ( n );
    int res = 1;
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            int p = 0; /*Counter for power of prime*/
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                p++;
            }
            sqrtn = sqrt ( n );
            p++;/*Increase it by one at end*/
            res *= p; /*Multiply with answer*/
        }
    }
    if ( n != 1 ) {
        res *= 2; /*Remaining prime has power p^1. So multiply with 2*/
    }
    return res;
}

/// SOD 
///SOD(12)=(2^0+2^1+2^2)×(3^0+3^1)
int SOD( int n ) {
    int res = 1;
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            int tempSum = 1; //Contains value of (p^0+p^1+...p^a)
            int p = 1;
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                p *= prime[i];
                tempSum += p;
            }
            sqrtn = sqrt ( n );
            res *= tempSum;
        }
    }
    if ( n != 1 ) {
        res *= ( n + 1 ); //Need to multiply (p^0+p^1)
    }
    return res;
}


///euler totient function
///it is used to calculate number of coprimes
/*
1) For a prime number p, ?(p) is p-1. For example ?(5) is 4, ?(7) is 6 and ?(13) is 12. This is obvious, gcd of all numbers from 1 to p-1 will be 1 because p is a prime.

2) For two numbers a and b, if gcd(a, b) is 1, then ?(ab) = ?(a) * ?(b). For example ?(5) is 4 and ?(6) is 2, so ?(30) must be 8 as 5 and 6 are relatively prime.

3) For any two prime numbers p and q, ?(pq) = (p-1)*(q-1). This property is used in RSA algorithm.

4) If p is a prime number, then ?(pk) = pk – pk-1. This can be proved using Euler’s product formula.

5) Sum of values of totient functions of all divisors of n is equal to n.
For example, n = 6, the divisors of n are 1, 2, 3 and 6. According to Gauss, sum of ?(1) + ?(2) + ?(3) + ?(6) should be 6. 
We can verify the same by putting values, we get (1 + 1 + 2 + 2) = 6.*/
///code
int phi(int n)
{
    int result = n; // Initialize result as n
 
    // Consider all prime factors of n and subtract their
    // multiples from result
    for (int p = 2; p * p <= n; ++p) {
         
        // Check if p is a prime factor.
        if (n % p == 0) {
             
            // If yes, then update n and result
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
 
    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result -= result / n;
    return result;
}

