//Segmental tree contains the interval: [a,b]  its left children contains interval [a,(a+b)/2] and the right children contains interval [(a+b)/2,b]
//Segmental tree is a complete binary tree, so could be implemented by array

struct seg_node{
  int a; //interval lower bound
  int b; //interval upper bound
  int cover; //for covering problem
  struct seg_node *left;
  struct seg_node *right;
};

typedef struct seg_node * seg_nptr;


seg_nptr build(int l,int r){
  seg_nptr root=(seg_nptr)malloc(sizeof(struct seg_node));
  root->a=l;
  root->b=r;
  root->cover=0;
  if(1+l<r){
      root->left=build(l,(l+r)/2);
      root->right=build((l+r)/2,r);
  }
  return root;
}


//use cover to count the intersection
void insert(int l, int r, seg_nptr root){
  int mind;
  if(root->cover==0){
    m=root->a+root->b;
    if(l==root->a && r==root->b)
      root->cover=1;
    else if(r<=root->a || l>=root->b)
      return;
    else if(r<=m)
      insert(l,r,root->left);
    else if(l>=m)
      insert(l,r,root->right);
    else{
      insert(l,m,root->left);
      insert(m,r,root->right);
    }  
  }
}

//count the lenght to be covered
int count(seg_nptr root){
  if(root->cover)
    reurn root->b-root->a;
  else if(root->b-root->a==1)
    return 0;
  return count(root->left+root->right);
}




