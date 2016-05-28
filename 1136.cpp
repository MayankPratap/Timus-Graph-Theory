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

struct bstNode{

   ll data;
   struct bstNode *left;
   struct bstNode *right;

};

ll inorder[65536],leftright[65536];

struct bstNode* getNewNode(int val){

     struct bstNode* newNode=(struct bstNode*)malloc(sizeof(struct bstNode));
     newNode->data=val;
     newNode->left=NULL;
     newNode->right=NULL;

     return newNode;

}

int binary_search(int low,int high,ll val){

    int mid;

    while(low<high){

       mid=(low+high)/2;

       if(inorder[mid]==val){

           return mid;

       }

       else if(val>inorder[mid])
            low=mid+1;

       else
            high=mid-1;

    }

}

struct bstNode* solve(int start1,int end1,int start2,int end2,struct bstNode* root){

    int n=end1-start1+1;

    if(n>0){

       ll val=leftright[end2];

    // Now I do binary search in inorder array to get position of root

       int pos=binary_search(start1,end1,val);
       root=getNewNode(val);

       root->left=solve(start1,pos-1,start2,start2+pos-start1-1,root->left);
       root->right=solve(pos+1,end1,start2+pos-start1,end2-1,root->right);

       return root;
    }

    return NULL;
}

void printRightToLeft(struct bstNode* root){

    if(root==NULL)
       return;

    printRightToLeft(root->right);
    printRightToLeft(root->left);

    printf("%lld\n",root->data);

}

int main(){

   struct bstNode *root=NULL;   // Creating an empty tree

   int n;

   scanf("%d",&n);

   for(int i=0;i<n;++i){

      scanf("%lld",&leftright[i]);
      inorder[i]=leftright[i]

   }

   sort(inorder,inorder+n);

   root=solve(0,n-1,0,n-1,root);

   //printf("\n");

  printRightToLeft(root);

/*  printf("%d\n",root->left->left->data);
  printf("%d\n",root->left->right->data);
  printf("%d\n",root->left->data);
  printf("%d\n",root->data);
  printf("%d\n",root->right->data);
  printf("%d\n",root->right->right->left->left->data);
  printf("%d\n",root->right->right->left->data);
  printf("%d\n",root->right->right->data);
  printf("%d\n",root->right->right->right->data);

 */

   return 0;
}
