/*  
   Mayank Pratap Singh
   MNNIT, 2nd year IT
         
   AC ho.
*/
#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define MOD 1000000007

typedef long long ll;
typedef long double ld;

const int INF=(int)(1e9);
const ll INF64=(ll)(1e18);
const ld EPS=1e-9;
const ld PI=3.1415926535897932384626433832795;


typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef vector<list<int> > vl;
typedef map<int,int> mi;
typedef map<string,int> ms;
typedef set<int> si;

double dp[1005][1005];

int n,m,k,u,v;

int visited[1001][1001];

int main(){

    scanf("%d %d",&n,&m);

    for(int i=0;i<=n;++i)
       dp[i][0]=i*100;

    for(int i=0;i<=m;++i)
       dp[0][i]=i*100; 

    scanf("%d",&k);

    for(int i=1;i<=k;++i){

        scanf("%d %d",&u,&v);

        visited[u][v]=1; 

    }
  

    for(int i=1;i<=n;++i){

        for(int j=1;j<=m;++j){
            
             double ans1=dp[i][j-1]+100;
             double ans2=dp[i-1][j]+100;

             if(visited[i][j]==1){
                 double ans3=dp[i-1][j-1]+sqrt(2)*100;

                 dp[i][j]=min(ans1,min(ans2,ans3));

             }

             else{
 
                 dp[i][j]=min(ans1,ans2);

             }

        }
    }

    printf("%0.0lf\n",dp[n][m]);



	return 0;
}
