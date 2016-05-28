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

vlp adjList(905);

int parent[905]; // Storing parent of a node
int dist[905];   // Storing distance of a node from start vertex

int status[905];

int level[905];  // Har level ki prevrank
int numnodes[35];  // Har level me kitni nodes

int n,vertices,prevrank;

map<int,pair<int,int> >mapa;  // Storing vertex info in Bellman Ford

       // Stores shortest distance and parent of a vertex

int relax(int u,int v,int w){

    if(dist[v]>dist[u]+w){

       dist[v]=dist[u]+w;
       parent[v]=u;
    }
}

int main(){

   prevrank=1;

   scanf("%d",&n);  // n denotesnumber of levels

   level[0]=1;

   for(int i=1;i<=n;){

       string str;
       cin>>str;

       if(str[0]=='*'){

          ++i;

       }

       else{

           int m=0;  // m denotes number of nodes in one level

           int power=1;

           for(int j=(int)str.size()-1;j>=0;--j){

               m+=(str[j]-'0')*power;
               power*=10;
           }

        //   printf("No of nodes in level %d is %d\n",i,m);
          // printf("Prev numbered node before this level %d\n",prevrank);

           numnodes[i]=m;

           level[i]=prevrank+1;

           while(m--){

               prevrank+=1;

               int count=0,num,val,x;

               while(1){

                  if(count%2==0){

                      scanf("%d",&x);

                      if(x==0)
                         break;

                      num=x;

                  }

                  else{

                      scanf("%d",&x);

                      val=x;

                      adjList[level[i-1]+num-1].pb(mp(prevrank,val));

                  }

                  ++count;

               }
           }

           if(i==n)
             break;
       }


   }

  /* printf("%d\n",prevrank);

   for(int i=1;i<=prevrank;++i){

      printf("%d -> ",i);

      list<pair<int,int> >::iterator it;

      for(it=adjList[i].begin();it!=adjList[i].end();++it){
          printf("%d %d  ",it->ff,it->ss);
      }
      printf("\n");
   }  */

  // Now I am going to apply BellMan-Ford

  int vertices=prevrank;

  dist[1]=0;
  parent[1]=-1;


  for(int i=2;i<=vertices;++i){

      dist[i]=INF;
      parent[i]=-1;

  }

  for(int i=1;i<=vertices-1;++i){

     for(int j=1;j<=vertices;++j){

         list<pair<int,int> >::iterator it;

         int u=j;

         for(it=adjList[j].begin();it!=adjList[j].end();++it){

             int v=it->ff;
             int w=it->ss;

             relax(u,v,w);

         }
     }

  }

   int ans=INF;

   for(int i=level[n];i<level[n]+numnodes[n];++i){

       ans=min(dist[i],ans);

   }

   printf("%d\n",ans);

   return 0;
}
