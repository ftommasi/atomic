#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define INCSIZE 1
#define LOOPSIZE 20000000
int race = 0;
void* subtractor(void * args){
    int i =0;
  for(i;i<LOOPSIZE;i++){
   __sync_fetch_and_sub(&race, INCSIZE);
  }

    return NULL;

}
void* adder(void* args){
  
  int i =0;
  for(i;i<LOOPSIZE;i++){
    __sync_fetch_and_add(&race, INCSIZE);
  }

   return NULL;
}

int main(int argc, char** argv){
  pthread_t id1,id2;
  int test;

  test = pthread_create(&id1,NULL,adder,NULL);
  test = pthread_create(&id2,NULL,subtractor,NULL);

  test = pthread_join(id1,NULL);
  test = pthread_join(id2,NULL);

  printf("race is %d\n",race);

  return 0;
}
