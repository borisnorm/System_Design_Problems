/*
EPI_18.3: Consider an object s which is read from and written to by many threads. (For
example, s could be the cache from Problem 18.1.) You need to ensure that no thread
may access s for reading or writing while another thread is writing to s. (Two or
more readers may access s at the same time.)
One way to achieve this is by protecting s with a mutex that ensures that two
threads cannot access s at the same time. However this solution is suboptimal
because it is possible that a reader R1 has locked s and another reader R2 wants to
access s. Reader R2 does not have to wait until R1 is done reading; instead, R2 should
start reading right away.  (Read_Write_Lock) 
*/

//Analysis: Use one mutex lock and two conditions to stand for  read and write locks(Could also use two mutexs)
//Use two counter variable to records the reader and writer numbers.
//When there is no ponding writing operation, reading operations are allowed.
//When there are no ponding writing and reading operations, writing are allowed.
//Use busy waiting to implement the above two rules and use signal() and wait() to save CPU cycles.

//mutex and conditions
pthread_mutex_t mylock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t read_cond=PTHREAD_COND_INITIALIZER;
pthread_cond_t write_conde=PTHREAD_COND_INITIALIZER;

//reader and writer counters
int NoOfReader=0;
int NoofWriter=0;
//could use number of waiting writers for more specific control

void r_lock(){
  pthread_mutex_lock(&mylock);
  while(NoOfWriter>0)
    pthread_cond_wait(&read_cond, &mylock);
  NoOfReader++;  
  pthread_mutex_unlock(&mylock);
}

void w_lock(){
  pthread_mutex_lock(&mylock);
  while(NoOfReader>0 || NoOfWriter>0)
    pthread_cond_wait(&write_cond,&mylock);
  NoOfWriter++;
  pthread_mutex_unlock(&mylock);
}

void r_unlock(){
  pthread_mutex_lock(&mylock);
  NoofReader--;
  if(NoOfReader==0)
    pthread_cond_signal(&write_cond); //send signal to one of the potential ponding writers
  pthread_mutex_unlock(&mylock);
}

void w_unlock(){
  pthread_mutex_lock(&mylock);
  NoOfWriter--;
  pthread_cond_signal(&write_cond); //send signal to one of the potential ponding writers
  pthread_cond_broadcast(&read_cond); //send signal to all potential ponding readers
  pthread_mutex_unlock(&mylock);
}

