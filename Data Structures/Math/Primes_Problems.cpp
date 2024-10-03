#include<bits/stdc++.h>
using namespace std;
int gcd(int , int );
int lcm(int* , int);
void prime_factors(int);
void seivesOfEratosthenis(int);
void test();
void spf(int );
void generate_prime_factors_seives(int );
int main(){
    // cout<<gcd(3,7);
    // int arr[]={2,4,6};
    // cout<<lcm(arr, 3);
    // prime_factors(100);
    // int n;
    // cin>>n;
    // seivesOfEratosthenis(n);
    // test();
    // spf(20); // Smallest Prime Factors - Seives Eratosthenis
    generate_prime_factors_seives(200);
}

int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int lcm(int arr[], int n){
    int res = arr[0];
    for(int i=1; i<n; i++){
        res = (res*arr[i])/gcd(res, arr[i]);
    }
    return res;
}

void prime_factors(int n){
    while(n%2==0){
        cout<<2<<" ";
        n/=2;
    }

    for(int i=3; i<=sqrt(n); i+=2){
        while(n%i==0){
            cout<<i<<" ";
            n/=i;
        }
    }

    if(n>2){
        cout<<n<<endl;
    }
}

void seivesOfEratosthenis(int n){
    bool arr[n+1];
    memset(arr, true, sizeof(arr));
    for(int i=2; i<=sqrt(n); i++){
        if(arr[i]){
            for(int j=i*i; j<=n; j+=i){
                arr[j]=false;
            }
        }
    }
    for(int k=2; k<=n; k++){
        if(arr[k])
            cout<<k<<" ";
    }
}

void test(){
    bool t[10]={true};
    memset(t, true, sizeof(t));
    for(bool i: t)
        cout<<i<<" ";
}

void spf(int n){
    int spf[n+1]={0};
    for(int i=2; i<=n; i++){
        if(spf[i]==0){
            for(int j=i; j<=n; j+=i){
                if(spf[j]==0){
                    spf[j]=i;
                }
            }
        }
    }

    for(int i=2; i<=n; i++){
        cout<<spf[i]<<" ";
    }
}

void generate_prime_factors_seives(int n){
    // To demonstrate seives method for pre-computation
    int spf[1000]={0};

    for(int i=2; i<1000; i++){
        if(spf[i]==0){
            for(int j=i; j<1000; j+=i){
                if(spf[j]==0){
                    spf[j]=i;
                }
            }
        }
    }

    vector<int> primeFactors;
    while(n!=1){
        primeFactors.push_back(spf[n]);
        n/=spf[n];
    }

    for(int  i : primeFactors){
        cout<<i<<" ";
    }
}