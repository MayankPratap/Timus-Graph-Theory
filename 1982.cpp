/* Author:- Mayank Pratap Singh

   2nd year, MNNIT

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

const int N=105;

vector<list<pair<int,int> > >adjList(N+1);
vector<list<pair<int,int> > >spanning_tree(N+1);
list<pair<int,int> >::iterator it;
int parent[N+1];
int level[N+1];
int visited[N+1];

int phouse[N+1];
int n,k,x;

vector<int>powerhouses(105);


priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;

ll sum;

void solve(){

   int count=k;  // Count of Powerhouses at each step, number of powerhouses increases by 1
   int u;
   for(int i=1;i<=n;++i)
      visited[i]=0;

   while(count!=n){

      if(count==k){


         for(int i=0;i<(int)powerhouses.size();++i){

             list<pair<int,int> >::iterator it;

             u=powerhouses[i];

             for(it=adjList[u].begin();it!=adjList[u].end();++it){

                 int v=it->ff;
                 int w=it->ss;

                 if(phouse[v]==0)
                   pq.push(mp(w,mp(u,v)));
             }
         }


    }

    else{



         list<pair<int,int> >::iterator it;

         for(it=adjList[u].begin();it!=adjList[u].end();++it){

            int v=it->ff;
            int w=it->ss;

            if(phouse[v]==0)
               pq.push(mp(w,mp(u,v)));
         }
    }

      while(!pq.empty()){

        int w=pq.top().ff;
        int v1=pq.top().ss.ff;
        int v2=pq.top().ss.ss;

        pq.pop();

         if(visited[v2]==1)
           continue;

         else{

            u=v2;
            phouse[u]=1;
            ++count;
            visited[u]=1;
            sum+=w;
            break;

         }

      }  // close to while(!pq.empty())
   }   // Close to while(count!=n)
}   // close to solve

int main(){

    scanf("%d %d",&n,&k);

    for(int i=1;i<=n;++i){
        phouse[i]=0;
    }

    for(int i=1;i<=k;++i){

        scanf("%d",&x);
        powerhouses.pb(x);
        phouse[x]=1;

    }

    for(int i=1;i<=n;++i){

        for(int j=1;j<=n;++j){

            scanf("%d",&x);
            if(i!=j)
                adjList[i].pb(mp(j,x));
        }
    }

    sum=0;



    solve();

    printf("%lld\n",sum);

	return 0;
}
