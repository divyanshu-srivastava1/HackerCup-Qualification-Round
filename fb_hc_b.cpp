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
        int n;
        cin>>n;
        vector<string> v(n);
        vector<int> row, col;
        int cnt=0;
        input(v);
        int ans=-1;
        for(int i=0; i<n; i++){
            int c=0;
            for(int j=0; j<n; j++){
                if(v[i][j]=='.'){
                    c++;
                }
                else if(v[i][j]=='O'){
                    c=-1;
                    break;
                }
            }
            if(c!=-1){
                if(ans==-1){
                    ans=c;
                    cnt++;
                    row.push_back(i);
                }
                else if(ans==c){
                    row.push_back(i);
                    cnt++;
                }
                else if(ans>c){
                    row.clear();
                    row.push_back(i);
                    ans=c;
                    cnt=1;
                }
            }
        }
        //cout<<ans<<" "<<cnt<<endl;
        for(int i=0; i<n; i++){
            int c=0;
            for(int j=0; j<n; j++){
                //cout<<j<<i<<" ";
                if(v[j][i]=='.'){
                    c++;
                }
                else if(v[j][i]=='O'){
                    c=-1;
                    break;
                }
            }
            //cout<<"-> "<<c<<"; \n";
            if(c!=-1){
                if(ans==-1){
                    ans=c;
                    cnt++;
                    col.push_back(i);
                }
                else if(ans==c){
                    cnt++;
                    col.push_back(i);
                }
                else if(ans>c){
                    row.clear();
                    col.clear();
                    col.push_back(i);
                    cnt=1;
                    ans=c;
                }
            }
            //cout<<ans<<" "<<cnt<<endl;
        }
        if(ans==1){
            set<pair<int, int>> st;
            for(int i: row){
                for(int j=0; j<n; j++){
                    if(v[i][j]=='.'){
                        st.insert({i, j});
                    }
                }
            }
            for(int i: col){
                for(int j=0; j<n; j++){
                    if(v[j][i]=='.'){
                        st.insert({j, i});
                    }
                }
            }
            cnt=st.size();
        }
        cout<<"Case #"<<tc<<": ";
        if(ans==-1){
            cout<<"Impossible"<<endl;
        }
        else{
            cout<<ans<<" "<<cnt<<endl;
        }
        tc++;
    }
}