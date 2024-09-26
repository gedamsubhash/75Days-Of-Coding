#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
vector<int> findPrimeFactors(int );
vector<int> leastPrimeFactorTillN(int );
int findLeastPrimeFactor(int );
int main(){
    int n;
    cout<<"Enter the value: ";
    cin>>n;

    // vector<int> result = findPrimeFactors(n);
    
    // for(int x: result)
    //     cout<<x<<" ";

    // cout<<findLeastPrimeFactor(n);

    vector<int> result = leastPrimeFactorTillN(n);
    for(int x: result)
        cout<<x<<" ";

    return 0;
}

vector<int> findPrimeFactors(int n){
    int i=2;
    vector<int> ans;
    while(n%2==0){
        ans.push_back(2);
        n/=2;
    }

    for(++i; i<=sqrt(n); i+=2){
        while(n%i==0){
            ans.push_back(i);
            n/=i;
        }
    }

    if(n>2)
        ans.push_back(n);
    return ans;
}

int findLeastPrimeFactor(int n){
    if(n%2==0)
        return 2;
    for(int i=3; i<=sqrt(n); i+=2){
        while(n%i==0){
            return i;
        }
    }

    return n;
}

vector<int> leastPrimeFactorTillN(int n){
    vector<int> least_primes(n+1, 0);
    least_primes[1]=1;
    for(int i=2; i<=n; i+=2){
        if(least_primes[i]==0){
            least_primes[i]=i;

            for(int j=i*i; j<=n; j+=i){
                if(least_primes[j]==0){
                    least_primes[j]=i;
                }
            }
        }
    }

    return least_primes;
}