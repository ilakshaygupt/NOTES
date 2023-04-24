







primality test -> test for prime


brute
bool isPrime(int n)
{
    static int i = 2;
 
    // corner cases
    if (n == 0 || n == 1) {
        return false;
    }
 
    // Checking Prime
    if (n == i)
        return true;
 
    // base cases
    if (n % i == 0) {
        return false;
    }
    i++;
    return isPrime(n);
}

better -> all divisors of n occur in pair (a,b) such a*b=n

i.e. one divisor<sqrt(n) and one>sqrt(n)



bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}
----------------------------------------------------------------------------
sieve
 precrocess time O(Nlog(logN))
 extra space O(N)

The number of prime numbers less than or equal to  n is approximately  n / ln(n) 
 int n;
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}




find n th prime number

#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<bool> vec(90000001, true);
vector<int> ans;

void pre_cal()
{
    for (int i = 2; i <= 90000000; i++)
    {
        if (vec[i] == true)
        {
            ans.push_back(i);
            for (int j = i * i; j <= 90000001; j += i)
            {
                vec[j] = false;
            }
        }
    }
}

int32_t main()
{
    int q;
    cin >> q;
    pre_cal();

    while (q--)
    {
        int n;
        cin >> n;
        cout << ans[n - 1] << endl;
    }

    return 0;
}

-----------------------------------------------------------------------------------

find prime  ors of number

brute

void primeFactors(int n)
{

    while (n % 2 == 0)//kill all even no i.e. power of two
    {
        cout << 2 << " ";
        n = n/2;
    }
 
optimize if n is a composite number there exist t least 1 prime number of n below sqrt(n)

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
   
        while (n % i == 0)
        {
            cout << i << " ";
            n = n/i;
        }
    }


    if (n > 2)
        cout << n << " ";
}



void primeFactors(int n)
{
    int c=2;
    while(n>1)
    {
        if(n%c==0){
        cout<<c<<" ";
        n/=c;
        }
        else c++;
    }
}








-----------------------------------------------------------------------------------



binary exponenetiation

calculate a^n in O(logN)

 int (int base,int power)
 {int ans=1;
    for(int i=1;i<=power;i++)
    {
        ans*=base;
    }
    cout<<ans;
 }




 optimize


 res       base         power
 1          2           13
 2          2           12
 2          4           6
 2          16          3
 32         16          2
 32         256         1
 8192       256         0


 recursive

 long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

iterative

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}



for modular exponenetiation


iterative

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}




recursive
int power(int a, int b)
{
    if(b == 0) return 1;
    a = a % m;
    int temp = power(a, b/2);
    if(b&1)
        return (((temp * temp) % m) * a) % m;
    else
        return (temp * temp) % m;
}



-----------------------------------------------------------------------------------
prime factor using sieve




void sieveOfEratosthenes(int N) {
   
   N+=2;
   primes[1] = 1;
   for (int i=2; i<N; i++)
      primes[i] = i;//assign every number ints index for if (primes[i] == i) condition
   for (int i=4; i<N; i+=2)
      primes[i] = 2;//assign every even number 2 as lowest prime factor
   for (int i=3; i*i<N; i++) {
      if (primes[i] == i) {
         for (int j=i*i; j<N; j+=i)
            if (primes[j]==j)
               primes[j] = i;// stores number j lowest prime factor
      }
   }
}
void findPrimeFactors(int num) {
   
   sieveOfEratosthenes(num);
   int factor;
   while (num != 1) {
      factor = primes[num];//find lowest prime factor of num
      cout<<factor<<" ";
      num /= factor;
   }
}

int main() {             
   int N = 71;
   cout<<"Prime factorization of the number "<<N<<" using sieve is ";
   findPrimeFactors(N);
   return 0;
}


----------------------------------------------------------------------------
calculate matrix raised to some power 


brute O(M^3 n)
optimized O(M^3 * log n)






----------------------------------------------------------------------------


n th number of a recuurence relation







using binet formulae
cout<<round(pow((1 + sqrt(5)) / 2, n) / sqrt(5));


by matrix exponenetiation

using ll = long long;

const ll MOD = 1e9 + 7;

using Matrix = array<array<ll, 2>, 2>;

Matrix mul(Matrix a, Matrix b) {
	Matrix res = {{{0, 0}, {0, 0}}};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				res[i][j] += a[i][k] * b[k][j];
				res[i][j] %= MOD;
			}
		}
	}

	return res;
}

int main() {
	ll n;
	cin >> n;

	Matrix base = {{{1, 0}, {0, 1}}};
	Matrix m = {{{1, 1}, {1, 0}}};

	for (; n > 0; n /= 2, m = mul(m, m)) {
		if (n & 1) base = mul(base, m);
	}

	cout << base[0][1];
}



----------------------------------------------------------------------------


gcd by euclid's theorem



int gcd(int a,int b)
{
    if(b==0)
    {
        return a;

    }
    else{
        if(a>b) swap(a,b);
        gcd(b,a%b);
    }
}







 void lowestFraction(int num1, int num2){
      int denom=__gcd(num1,num2);
      num1/=denom;
      num2/=denom;
      cout<<num1<<"/"<<num2;
}
-------------------------------------------------------------------------------------
a congurent b is a%x==b%x
                replace a with b
    13%7=6
    42%7=6
    (13+35+5)%7=53%7=4
    (6+0+5)%7=11%7  =4(35%7==0%7)



    IF(A*B==C)
    THEN (A%N *B%N  == C%N )



    LAST DIGIT OF   2573*34268


    2573%10 * 34268%10
    (3*8)%10
    24%10
    4


    (142+143+324+781+523+250+313)%2==??
    (0+1+0+1+1+0+1)%2
    4%2
    0



    You know 1378^n   1378^n % 10 =8^n%10
    If n=0 answer is 1, otherwise, you can prove with induction that if:
 if n mod 4
==0 then answer is 6.

==1 then answer is 8.

==2  then answer is 4.

==3  then answer is 2.





Fermat’s little theorem states that 
if p is a prime number, then for any integer a,
 the number a^p - a is an integer multiple of p. 

Here p is a prime number 
a^p ≡ a (mod p).



Special Case: If a is not divisible by p, 
Fermat’s little theorem is equivalent to the statement that
 a ^(p-1)-1 is an integer multiple of p. 
 

a^(p-1) ≡ 1 (mod p) 
OR 
a^(p-1) % p = 1 
Here a is not divisible by p. 




void modInverse(int a, int m)
{
    if (__gcd(a, m) != 1)
        cout << "Inverse doesn't exist";
 
    else {
 
        cout << "Modular multiplicative inverse is "
             << power(a, m - 2, m);
    }
}

P = an integer Prime number   
 a = an integer which is not multiple of P  
 Let a = 2 and P = 17 
 
 According to Fermats little theorem 
  2 ^(17 - 1)     ≡ 1 mod(17)
 we got  65536 % 17 ≡ 1   
 that mean (65536-1) is an multiple of 17 


-----------------------------------------------------------------------------


segmented sieve


---------------------------------------------------------------------------
