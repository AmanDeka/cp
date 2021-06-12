#include<bits/stdc++.h>
#include<iostream>
#include<vector> 
#include<map>
#include<cstdlib>
#include<cmath>
#include<numeric>

#define ll long long

using namespace std; 

void solve(int);

#define m1(x) template<class T, class... U> void x(T&& a, U&&... b)

#define m2(x) (int[]){(x forward<U>(b),0)...}

m1(pr) { cout << forward<T>(a);  m2(cout << " " <<); cout << "\n"; } 

m1(re) { cin >> forward<T>(a); m2(cin >>); }

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


int main() 
{ 
   ios_base::sync_with_stdio(false);cin.tie(NULL); 
   
   #ifndef ONLINE_JUDGE 
   freopen("input.txt", "r", stdin); 
   freopen("error.txt", "w", stderr); 
   freopen("output.txt", "w", stdout); 
   #endif 
   
   int t=1; 
   /*is Single Test case?*///re(t); 
   while(t--) 
   { 
      solve(t); 
      cout<<'\n';
   } 
   
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
}

ll dp[101][101][11][2];

void solve(int test) 
{
  int N1,N2,K1,K2;
  re(N1,N2,K1,K2);

  for(int i=0;i<=N1;i++){
    for(int j=0;j<=K1;j++){
      if(j==i){
        dp[i][0][j][1] = 1;
        dp[0][i][j][2] = 1;
      }
      else{
        dp[i][0][j][1] = 0;
        dp[0][i][j][2] = 0;
      }
    }
  
  }

  for(int i=0;i<=N2;i++){
    for(int j=0;j<=K2;j++){
      if(j==i){
        dp[0][i][j][2] = 1;
      }
      else{
        dp[0][i][j][2] = 0;
      }
    }
  }

  for(int n1=1;n1<=N1;n1++){
    for(int n2 = 1;n2<=N2;n2++){
      for(int k=1;k<=min(n1,K1);k++){
        dp[n1][n2][k][1] = 0;
        for(int k2 = 1;k2<=min(K2,N2);k2++){
          dp[n1][n2][k][1] = (dp[n1][n2][k][1]+dp[n1-k][n2][k2][2])%100000000;
        }
      }

      for(int k=1;k<=min(n2,K2);k++){
        dp[n1][n2][k][2] = 0;
        for(int k1 = 1;k1<=min(K1,N1);k1++){
          dp[n1][n2][k][2] = (dp[n1][n2][k][2]+dp[n1][n2-k][k1][1])%100000000;
        }
      }
    }
  }

  ll ans = 0;
  for(int i=1;i<=K1;i++){
    ans = (ans + dp[N1][N2][i][1])%100000000;
  }
  for(int i=1;i<=K2;i++){
    ans = (ans + dp[N1][N2][i][2])%100000000;
  }
  pr(ans);

}

