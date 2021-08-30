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

void solve(vector<vector<int>> &e, vector<vector<int>> &v, int i, int n, int t){
    if(v[i][n]!=-1 && v[i][n]<=t){
        return;
    }
    v[i][n]=t;
    for(int k: e[n]){
        solve(e, v, i, k, t+1);
    }
    return;
}

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
        int n=s.size();
        int m;
        cin>>m;
        vector<vector<int>> e(26);
        while(m--){
            string ed;
            cin>>ed;
            e[ed[0]-'A'].push_back(ed[1]-'A');
        }
        vector<vector<int>> v(26, vector<int>(26, -1));
        for(int i=0; i<26; i++){
            solve(e, v, i, i, 0);
        }
        int ans=-1;
        // for(int i=0; i<26; i++){
        //     for(int j=0; j<26; j++){
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0; i<26; i++){
            int cc=0;
            for(auto &ch: s){
                int x = ch-'A';
                int c = v[x][i];
                if(c==-1){
                    cc=-1;
                    break;
                }
                cc+=c;
            }
            if(ans==-1 && cc>=0){
                ans=cc;
            }
            else if(cc>=0){
                ans=min(ans, cc);
            }
        }
        cout<<"Case #"<<tc<<": "<<ans<<endl;
        tc++;
    }
}
