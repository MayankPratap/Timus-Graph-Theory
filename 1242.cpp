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

vl parent(1005);
vl children(1005);

int n,count,visitedp[1005],visitedc[1005],notSuspect[1005];

void solveparent(int start){

   list<int>::iterator it;

   for(it=parent[start].begin();it!=parent[start].end();++it){

        if(visitedp[*it]==0){
            visitedp[*it]=1;
            notSuspect[*it]=1;
            solveparent(*it);
        }

   }

}

void solvechildren(int start){

   list<int>::iterator it;

   for(it=children[start].begin();it!=children[start].end();++it){

        if(visitedc[*it]==0){

            visitedc[*it]=1;
            notSuspect[*it]=1;
            solvechildren(*it);
        }

   }

}

int main(){

     scanf("%d",&n);


     while(1){

        string str1;
        cin>>str1;

        if(str1=="BLOOD")
           break;

        string str2;

        cin>>str2;

        int u=atoi(str1.c_str());
        int v=atoi(str2.c_str());

      //  printf("%d %d\n",u,v);

        parent[u].pb(v);
        children[v].pb(u);

     }



     for(int i=0;i<1005;++i){
        visitedp[i]=0;
        visitedc[i]=0;
        notSuspect[i]=0;

      }

      int x;

     while(scanf("%d",&x)!=EOF){

         //printf("Hello\n");
         notSuspect[x]=1;
         visitedc[x]=1;
         visitedp[x]=1;
         solveparent(x);
         solvechildren(x);

     }

     vector<int>ans;

    for(int i=1;i<=n;++i){

       if(notSuspect[i]==0){

         ans.pb(i);

       }

    }

    sort(ans.begin(),ans.end());

    if((int)ans.size()==0)
       printf("0\n");
    else{
      for(int i=0;i<(int)ans.size();++i)
         printf("%d ",ans[i]);

      printf("\n");

    }
    


    return 0;
}
