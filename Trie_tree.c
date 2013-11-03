//Structure
#define MAX 26 //represent a dictionary 
struct trie_node{
  int count;
  struct trie_node * children[MAX];
}

typedef struct trie_node *trie_node_ptr;

trie_node_ptr new_node(){
  trie_node_ptr p=(trie_node_ptr)malloc(sizeof(struct trie_node));
  p->count=0;
  for(int i=0;i<MAX;i++)
    p->children[i]=NULL;
}

void insert(trie_node_ptr root, char * s){
  int level=0;
  int lengh=strlen(s);
  int index;
  trie_node_ptr p=root;
  for(;level<lengh;level++){
    index=s[level]-'a';
    if(p->children[index]==NULL)
      p->children[index]=new_node();
    p=p->children[index];
  }
  p->count++;// none zero---> leaf node, stranding for a string
}

int search(trie_node_ptr root, char *s){
  int level=0;
  int lengh=strlen(s);
  int index;
  trie_node_ptr p=root;  
  for(;level<lengh;level++){
    index=s[level]-'a';
    if(p->children[index]==NULL)
      return 0;
    p=p->children[index];  
  }
  return (p->count)?1:0;
}
