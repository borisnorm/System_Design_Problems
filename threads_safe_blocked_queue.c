#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct node{
  int valie;
  struct node *next;
  };
typedef struct node* nodeptr;

nodeptr head=NULL;
nodeptr tail=NULL;
static pthread_mutex_t mylock=PTHREAD_MUTEX_INITIALIZER;


void enqueue(nodeptr p){
  pthread_mutex_lock(&mylock);
  if(tail==NULL){
    head=tail=p;
  }
  else{
    tail->next=p;
    tail=tail->next;
  }
  pthread_mutex_unlock(&mylock);  
  }
}


nodeptr dequeue(){
  pthread_mutex_lock(&mylock);
  if(head==NULL){
    tail=NULL;
    return NULL;
  }
  else{
    nodeptr p=head;
    head=head->next;
    return p;
  }
  pthread_mutex_unlock(&mylock);
}
