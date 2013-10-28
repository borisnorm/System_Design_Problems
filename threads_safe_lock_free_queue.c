#include <stdio.h>
#include <stdlib.h>

struct node{
  int valie;
  struct node *next;
  };
typedef struct node* nodeptr;

nodeptr head=NULL;
nodeptr tail=NULL;

//atomic operation CAS
bool CAS(nodeptr addr, nodeptr old, nodeptr new){
 if(addr==old){
   add=new;
   return true;
 }
 else
  return false;
}


void enqueue(nodeptr p){
 if(CAS(tail,NULL,p)){
   head=p;
   return;
 }
 nodeptr q;
 while(1){
   q=tail;
   if(CAS(q->next,NULL,p))
     break;
   else 
    CAS(tail,q,q->next);
 }
 CAS(tail,q,p);
}


nodeptr dequeue(){
  nodeptr p;
  while(1){
    if(head==NULL){
      tail=NULL;
      return tail;
    }
    p=head;
    if(CAS(head,p,p->next))
     return p;
  }
}
