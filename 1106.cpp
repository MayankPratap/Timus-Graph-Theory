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

int parent[105],status[105],n,m,group[105];

bool check; // For checking cycle


void dfs_explore(int start){

   list<int>::iterator it;

  // printf("Hello\n");

   for(it=adjList[start].begin();it!=adjList[start].end();++it){

      //  printf("Hello\n");

       if(parent[*it]==-1){

           parent[*it]=start;

           group[*it]=!group[start];

           dfs_explore(*it);  

       }
   }

}

void dfs(){

   for(int i=1;i<=n;++i)
       group[i]=0;

   for(int i=1;i<=n;++i)
      parent[i]=-1;	

 //  printf("Hello\n");

   for(int i=1;i<=n;++i){

       if(parent[i]==-1){

           parent[i]=0;

           dfs_explore(i);

          

       }
   }

}

int main(){

    int x;

    scanf("%d",&n); 

    for(int i=1;i<=n;++i){

       while(1){

           scanf("%d",&x);
           if(x==0)
           	  break;
           adjList[i].pb(x);
       }
    }
 
    dfs();

    vector<int>team1,team2;

    for(int i=1;i<=n;++i){
   
        if(group[i]==0)
            team1.pb(i);

        else
            team2.pb(i);      
  
    }

  //  printf("%d %d\n",team1.size(),team2.size());

    if(team1.size()!=0 && team2.size()!=0){

        printf("%d\n",team1.size());
      
        for(int i=0;i<team1.size();++i){

            printf("%d ",team1[i]);

        }

        printf("\n");

    } 

    else{

    	printf("0\n");
    } 


	return 0;
}
