#include <bits/stdc++.h> 
using namespace std;
#define ll           long long int
#define vint         vector<int>
#define vll          vector<ll>
#define vstr         vector<string>
#define vvint        vector<vector<int> >
#define vvll         vector<vector<ll> >
#define vip          vector<pair<int,int> >
#define vlp          vector<pair<ll,ll> >
#define input(arr)   for(auto &x:arr) cin>>x;
#define output(arr)   for(auto &x:arr) cout<<x<<" ";
#define all(x)       (x).begin(), (x).end()
#define rall(x)      (x).rbegin(), (x).rend()
 
const int N = 100005;
const ll mod = 1000000007;
const ll inf = 1e17;
const long double pi = (acos(-1));

long long int solve(vector<long long int> &a, vector<vector<int>> &v, int i, bool nft, int k){
    //cout<<i<<endl;
    if(nft && i==0){
        return 0;
    }
    long long int ans = INT_MIN;
    for(int j=0; j<a.size(); j++){
        long long int tv=a[i];
        a[i]=0;
        if(i!=j){
            if(v[i][j]==1){
                v[i][j]=0;
                v[j][i]=0;
                ans=max(ans, tv+solve(a, v, j, true, k));
                v[i][j]=1;
                v[j][i]=1;
            }
            else if(k>=1){
                ans=max(ans, tv+solve(a, v, j, true, k-1));
            }
        }
        a[i]=tv;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int tc=1;
    while(t--){
        int n, k;
        cin>>n;
        cin>>k;
        vector<long long int> a(n);
        vector<vector<int>> v(n, vector<int>(n, 0));
        input(a);
        for(int i=0; i<n-1; i++){
            int x, y;
            cin>>x>>y;
            v[x-1][y-1]=1;
            v[y-1][x-1]=1;
        }
        long long int ans = max(a[0], solve(a, v, 0, false, k));
        cout<<"Case #"<<tc<<": "<<ans<<endl;
        tc++;
    }
}
