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

vl adjList(1005);
int parent[1005],pos[1005];

//stack<int>toposorted;

int n,m;

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

   for(int i=1;i<=n;++i)
       parent[i]=-1;

   for(int i=1;i<=n;++i){

      if(parent[i]==-1){

          parent[i]=0;
          dfs_explore(i);

      }
   }

}

int main(){

    scanf("%d %d",&n,&m);

    int u,v;

    for(int i=1;i<=m;++i){

        scanf("%d %d",&u,&v);
        adjList[u].pb(v);

    }

    int x;

    for(int i=1;i<=n;++i){
       scanf("%d",&x);
       pos[x]=i;
    }

    int flag=0;

    for(int i=1;i<=n;++i){

      list<int>::iterator it;

      for(it=adjList[i].begin();it!=adjList[i].end();++it){

          if(pos[*it]<pos[i]){

              flag=1;
              break;

          }
      }

      if(flag==1)
         break;

    }

    if(flag==1)
        printf("NO\n");

    else
        printf("YES\n");

    return 0;
}
