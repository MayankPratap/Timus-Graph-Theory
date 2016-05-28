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

vl adjList(105);

int parent[105];
int status[105];

int n;

stack<int>toposorted;
bool check;

void dfs_explore(int start){

    status[start]=1;   // Goes into recursion stack

    list<int>::iterator it;

    for(it=adjList[start].begin();it!=adjList[start].end();++it){

        if(parent[*it]==-1){

            parent[*it]=start;
            dfs_explore(*it);

        }

        else{

            if(status[*it]==1)
               check=true;


        }


    }

    toposorted.push(start);

    status[start]=0;



}

void dfs(){

   for(int i=1;i<=n;++i){

       if(parent[i]==-1){

           check=false;
           parent[i]=0;

           dfs_explore(i);

           if(check==true)
               break;

       }
   }


}

int main(){

     scanf("%d",&n);

     int x;

     for(int i=0;i<105;++i)
        parent[i]=-1;

     for(int i=1;i<=n;++i){

         while(1){

            scanf("%d",&x);

            if(x==0)
              break;

            adjList[i].pb(x);

         }
     }

     dfs();

     if(check==false){

        while(!toposorted.empty()){

           printf("%d ",toposorted.top());
           toposorted.pop();
        }

        printf("\n");

     }

     return 0;
}
