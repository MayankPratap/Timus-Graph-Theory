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

vector<list<pair<int,char> > >adjList(10005);

int parent[10005],removedBridges,n,k,m;

void dfs_explore(int start){

   list<pair<int,char> >::iterator it;

   for(it=adjList[start].begin();it!=adjList[start].end();++it){

    //   printf("%d %c\n",it->ff,it->ss);

       if(parent[it->ff]==-1){

          parent[it->ff]=start;
          dfs_explore(it->ff);

       }

       else{

           if(parent[start]!=it->ff){

               if(it->ss=='m')
                  removedBridges++;

           }


       }


   }



}

void dfs(){

   for(int i=1;i<=n;++i){

       parent[i]=-1;

   }

   for(int i=1;i<=n;++i){

       if(parent[i]==-1){

           parent[i]=0;
           dfs_explore(i);


       }

   }



}

int main(){



    removedBridges=0;

    scanf("%d %d %d",&n,&k,&m);

    for(int i=1;i<=k;++i){

        int u,v;

        scanf("%d %d",&u,&v);

        adjList[u].pb(mp(v,'k'));
        adjList[v].pb(mp(u,'k'));

    }

    for(int i=1;i<=m;++i){

       int u,v;

       scanf("%d %d",&u,&v);

       adjList[u].pb(mp(v,'m'));
       adjList[v].pb(mp(u,'m'));

    }

    dfs();

  //  printf("%d\n",removedBridges);

    printf("%d\n",m-removedBridges/2);



    return 0;
}
