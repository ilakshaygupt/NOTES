
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
        for (int j = 2 * i; j <= n; j += i)
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

find prime  factors of number

brute
void print prime(int n)
{int count=0;
    for(int i=1,i<sqrt(1e5);i++)
    {
        if(n%i==0)
        {cout<<i<<endl;
        count++;
            if(i!=n%i)
            {
                cout<<n/i<<endl;
                count++;
            }
        }
    }
    cout<<count;
}


int countPrimeFactors(int n) {
    vector<int> count(n+1, 0);
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (count[i] == 0) {
            for (int j = i; j <= n; j += i) {
                count[j]++;
            }
        }
        if (count[i] == 1) {
            ans++;
        }
    }
    return ans;
}

int main() {
    int n = 24;
    cout << "Number of prime factors of " << n << ": " << countPrimeFactors(n) << endl;
    return 0;
}




    int num;
    cin>>num;
    int i = 0;
    while (num != 1) {
        if (num % prime[i] == 0) {
            cout << prime[i] << " ";
            num /= prime[i];
        }
        else {
            i++;
        }
    }


int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;
    cout << "The prime factors of " << num << " are: ";
    print_prime_factors(num);
    cout << endl;
    return 0;
}




-----------------------------------------------------------------------------------



binary exponenetiation

calculate a^n in O(logN)

 int paber(int base,int power)
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

----------------------------------------------------------------------------
// matrix exponentation
any general recursive reln can be represented as 
		M * currentState = nextState    (M is a matrix , we currently dont know)
fibbo relation ->  f(n) = f(n-1) + f(n-2)   and f(0)=0 and f(1) = 1 
so we have f(0) and f(1) [i.e. 2 states] hence M would be of 2 X 2

		| a  b |  *  | f(n-1) |  =  | f(n)  |
		| c  d |     | f(n-2) |     | f(n-1)|

i.e.       M    *  currentState  =  nextState 

now lets calulate M 
	
	a*f(n-1) + b*f(n-2) = f(n)
	c*f(n-1) + d*f(n-2) = f(n-1)
	a=1, b=1, c=1, d=0
	
	lets calulate for f(2)
	| 1  1 |  *  | f(1) |  =  | f(2) |
	| 1  0 |     | f(0) |     | f(1) |
	
	lets calulate for f(3)
	| 1  1 |  *  | f(2) |  =  | f(3) |
	| 1  0 |     | f(1) |     | f(2) |
	
	ie
	
	| 1  1 |  *  | 1 1 | * | f(1) |  =  | f(3) |
	| 1  0 |     | 1 0 |   | f(0) |     | f(2) |
	
	ie
	for general n 
	M^(n-1) * | f(1) |  =  | f(n)   |
			  | f(0) |     | f(n-1) |
			  

    A=|1 1|^n   =|f(n+1) f(n)  |
      |1 0|      |f(n)   f(n-1)|
	how to find M^(n-1) ? use  exponentation !
	
	let A = M^(n-1) ;
	
	then f(n) = A[0][0] * f(1) + A[0][1] * f(0)
		 f(n) = A[0][0]   //   f(0) = 0 and f(1) = 1 


by matrix exponenetiation

void multiply(vector<vector<int>> &M ,vector<vector<int>> &A){
        int M11 = M[0][0] * A[0][0] + M[0][1] * A[1][0];
        int M12 = M[0][0] * A[0][1] + M[0][1] * A[1][1];
        int M21 = M[1][0] * A[0][0] + M[1][1] * A[1][0];
        int M22 = M[1][0] * A[0][1] + M[1][1] * A[1][1];
        
        M[0][0] = M11 , M[0][1] =M12 , M[1][0] =M21 , M[1][1] = M22;   
    }
    void power(vector<vector<int>> &M , int k){  
        if(k==0 or k==1)
            return ;
        power(M , k/2);
        multiply(M,M);
        if(k&1){
            vector<vector<int> > A {{1,1},{1,0}};
            multiply(M, A);
        }
    }
public:
    int fib(int n) {
       if(n==0) return  0 ;
        vector<vector<int> > M {{1,1},{1,0}};
        power(M , n-1);
        return M[0][0];
    }



----------------------------------------------------------------------------


gcd by euclid's theorem
        gcd(a,b)=gcd(a-b,b)  a>b


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


    extended euclidean theorem

    ax + by = gcd(a, b)
    gcd(a, b) = gcd(b%a, a)
    gcd(b%a, a) = (b%a)x1 + ay1
    ax + by = (b%a)x1 + ay1
    ax + by = (b - [b/a] * a)x1 + ay1
    ax + by = a(y1 - [b/a] * x1) + bx1

    Comparing LHS and RHS,
    x = y1 - ⌊b/a⌋ * x1
    y = x1


int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
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
a^(p-1) % p = 1   al primes 1<=a<=p-1 
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
