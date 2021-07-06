#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef tuple<int,int,int> tp;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int N;

const int MAX = 4000000;

long long minFactor[MAX];
vector<int> prime;

//에라토스테네스의 체
void eratosthenes(void){
    
    minFactor[0] = minFactor[1] = -1;

    for (long long i = 2; i < MAX; i++)
        minFactor[i] = i;

    for (long long i = 2; i < MAX; i++)
        if (minFactor[i] == i)
            for (long long j = i * i; j < MAX; j += i)
                if (minFactor[j] == j)
                    minFactor[j] = i;

    for (int i = 2; i < MAX; i++)
        if (minFactor[i] == i)
        prime.push_back(i);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    
    eratosthenes();
    
    int s=0, e=0, sum=prime[0], ans=0;

    while(s <= e && e < prime.size() && prime[s] <= N){
        if(sum == N) ans++;

        if(sum < N){
            e++;
            sum += prime[e]; 
        }
        else{
            sum -= prime[s];
            s++;

            if(s > e){
                e=s;
                sum = prime[e];
            }
        }
    }
    cout << ans;
}