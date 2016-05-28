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
typedef vector<list<pair<int,int> > > vlp;
typedef map<int,int> mi;
typedef map<string,int> ms;
typedef set<int> si;

vl adjList(105);

int n,m;  // n means number of vertices and m means number of edges
ll minCost;
ll d,a;
char output[105][105],input[105][105];

int parent[105];
int visited[105];

priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;

map<pair<int,int>,int>spanning_tree; // Which edge is in spanning tree

void prims(int start){

   int count=0,u=start;

   for(int i=1;i<=n;++i)
      visited[i]=0;

  list<int>::iterator it;    

   while(count<n){

       it=adjList[u].begin();

       ++count;

       visited[u]=1;

       while(it!=adjList[u].end()){

           int v=*it;
           int w=1;

           pq.push(mp(w,mp(u,v)));
           ++it;


       }

       while(!pq.empty()){

           int w=pq.top().ff;
           int v1=pq.top().ss.ff;
           int v2=pq.top().ss.ss;

           pq.pop();


           if(visited[v2]==1){

                if(spanning_tree[mp(v2,v1)]==1)
                   continue;

                else{

                    output[v1][v2]='d';

                }


           }

           else{

               spanning_tree[mp(v1,v2)]=1;
               u=v2;
               break;

           }
       }
   }

}

void dfs_explore(int start){

   list<int>::iterator it;

   for(it=adjList[start].begin();it!=adjList[start].end();++it){

      if(parent[*it]==-1){

         parent[*it]=start;
         dfs_explore(*it);
      }

   }

}

void dfs(){

  for(int i=0;i<105;++i)
     parent[i]=-1;

  for(int i=1;i<=n;++i){

     if(parent[i]==-1){

        if(i!=1){

          output[i][i-1]='a';
          output[i-1][i]='a';
          adjList[i].pb(i-1);
          adjList[i-1].pb(i);
          minCost+=a;

          ++m;

        }
        parent[i]=0;
        dfs_explore(i);
     }
  }

}

int main(){
    scanf("%d",&n);
    scanf("%lld %lld",&d,&a);

    for(int i=1;i<=n;++i){

       string str;
       cin>>str;

       for(int j=1;j<=n;++j){

           input[i][j]=str[j-1];
           if(input[i][j]=='1'){
              adjList[i].pb(j);
              ++m;
           }

       }

    }

    m=m/2;  // Consider only one edge b/w two vertices

/*
    for(int i=1;i<=n;++i){

        list<int>::iterator it;

         printf("%d -> ",i);

        for(it=adjList[i].begin();it!=adjList[i].end();++it){

            printf("%d ",*it);


        }

        printf("\n");

    }

    */

    for(int i=1;i<=n;++i){

       for(int j=1;j<=n;++j)
          output[i][j]='0';

    }



    minCost=0;

    dfs();

    prims(1);

    printf("%lld\n",minCost+(m-n+1)*d);

    for(int i=1;i<=n;++i){

      for(int j=1;j<=n;++j){

         printf("%c",output[i][j]);

      }

      printf("\n");
    }



    return 0;
}
