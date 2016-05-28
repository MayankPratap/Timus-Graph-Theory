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

vl adjList(10005);
int n,m;
map<pair<int,int>,int>slope; // Tells whether uphill or downhill

int parent[10005];
int level[10005];
int gearchanges[10005];   // Stores the number of gear mode changes till vertex i

int howArrived[10005];   // Stores whether we have arrived at a vertex i using uphill or downhill

void bfs(int start){

   for(int i=1;i<=n;++i){

        level[i]=-1;
        howArrived[i]=-1;
   }

   level[start]=0;
   queue<int>VertexQueue; // Queue for implementation of bfs

   VertexQueue.push(start);

   list<int>::iterator it;

   while(!VertexQueue.empty()){

       int newVertex=VertexQueue.front();

       VertexQueue.pop();

       if(newVertex==start){

          for(it=adjList[newVertex].begin();it!=adjList[newVertex].end();++it){

               if(level[*it]==-1){

                    if(slope[mp(newVertex,*it)]==0)
                        howArrived[*it]=0;
                    else
                        howArrived[*it]=1;

                    gearchanges[*it]=0;

                    level[*it]=level[newVertex]+1;

                    VertexQueue.push(*it);
               }
          }

       }

       else{

          for(it=adjList[newVertex].begin();it!=adjList[newVertex].end();++it){

              if(level[*it]==-1){

                   if(slope[mp(newVertex,*it)]==0)
                       howArrived[*it]=0;
                   else
                       howArrived[*it]=1;

                    if(howArrived[*it]!=howArrived[newVertex])
                      gearchanges[*it]=gearchanges[newVertex]+1;
                    else
                      gearchanges[*it]=gearchanges[newVertex];

                    level[*it]=level[newVertex]+1;

                    VertexQueue.push(*it);

              }

              else{

                  if(slope[mp(newVertex,*it)]==0){

                      if(slope[mp(newVertex,*it)]!=howArrived[newVertex]){

                          if(gearchanges[*it]>gearchanges[newVertex]+1){
                              gearchanges[*it]=gearchanges[newVertex]+1;
                              howArrived[*it]=0;
                              level[*it]=level[newVertex]+1;
                          }

                      }

                      else{

                         if(gearchanges[*it]>gearchanges[newVertex]){
                            gearchanges[*it]=gearchanges[newVertex];
                            howArrived[*it]=0;
                            level[*it]=level[newVertex]+1;
                         }

                      }


                  }

                  else if(slope[mp(newVertex,*it)]==1){

                      if(slope[mp(newVertex,*it)]!=howArrived[newVertex]){

                          if(gearchanges[*it]>gearchanges[newVertex]+1){
                              gearchanges[*it]=gearchanges[newVertex]+1;
                              howArrived[*it]=1;
                              level[*it]=level[newVertex]+1;
                          }

                      }

                      else{

                         if(gearchanges[*it]>gearchanges[newVertex]){
                            gearchanges[*it]=gearchanges[newVertex];
                            howArrived[*it]=1;
                            level[*it]=level[newVertex]+1;
                         }

                      }


                  }
              }
          }

       }
   }

}


int main(){

    int u,v;
    scanf("%d %d",&n,&m);

    for(int i=1;i<=m;++i){

        scanf("%d %d",&u,&v);
        adjList[u].pb(v);
        adjList[v].pb(u);
        slope[mp(u,v)]=0;  // Downhill
        slope[mp(v,u)]=1;  // uphill
    }

    int start,end;
    scanf("%d %d",&start,&end);

    bfs(start);

    printf("%d\n",gearchanges[end]);



    return 0;
}
