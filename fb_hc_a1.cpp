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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int tc=1;
    while(t--){
        string s;
        cin>>s;
        int vc=0, cc=0;
        int mvc=0, mcc=0;
        int n=s.size();
        map<char, int> m;
        for(auto &c: s){
            m[c]++;
            if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
                mvc=max(mvc, m[c]);
                vc++;
            }
            else{
                mcc=max(mcc, m[c]);
                cc++;
            }
        }
        int ans=cc+(2*(vc-mvc));
        ans=min(ans, vc+(2*(cc-mcc)));
        cout<<"Case #"<<tc<<": "<<ans<<endl;
        tc++;
    }
}