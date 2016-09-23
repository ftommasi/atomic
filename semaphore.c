#include <stdio.h>
int main(int argc ,char** argv){
  int count = 0;
  printf("count = %d\n",count);
  __sync_add_and_fetch(&count,1);
  printf("count = %d\n",count);
  return 0;
}

