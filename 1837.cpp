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

//mi ans;
map<string,list<string> >adjList;

ms level;
map<string,string>parent;

ms visited;

void bfs(string start){

    list<string>::iterator it;

    level[start]=0;
    queue<string>vq; 

    vq.push(start);

    while(!vq.empty()){

       string newV=vq.front();
       it=adjList[newV].begin();

       while(it!=adjList[newV].end()){

           if(level[*it]==-1){

              level[*it]=level[newV]+1;

              parent[*it]=newV;
               
              vq.push(*it); 

           }

           ++it;
       }

       vq.pop();
    }

}

int main(){

   int n;

   string str1,str2,str3;
 
   scanf("%d",&n);  
 
   for(int i=1;i<=n;++i){

        cin>>str1>>str2>>str3;

        visited[str1]=1;
        visited[str2]=1;
        visited[str3]=1;

        level[str1]=-1;
        level[str2]=-1;
        level[str3]=-1;

        list<string>temp=adjList[str1];

        temp.pb(str2);
        temp.pb(str3);

        adjList[str1]=temp;

        temp=adjList[str2];

        temp.pb(str1);
        temp.pb(str3);

        adjList[str2]=temp;

        temp=adjList[str3];

        temp.pb(str1);
        temp.pb(str2);

        adjList[str3]=temp;


        
    }

    bfs("Isenbaev");
    ms::iterator it;

  //  cout<<level.size()<<"\n";

    for(it=level.begin();it!=level.end();++it){
 
       // cout<<it->first<<" "<<it->second<<"\n";

        if(it->second==-1)
        	 if(visited[it->first]==1)
           	   cout<<it->first<<" "<<"undefined"<<"\n";
        if(it->second!=-1){
         
           if(visited[it->first]==1)
              cout<<it->first<<" "<<it->second<<"\n";
        }

    }
    
	return 0;
}
