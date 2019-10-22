#include <stdio.h>

void clear();

int main(){
  // Place your magic here
  clear();
  return 0;
}

void clear() {
  printf("\e[1;1H\e[2J"); 
}
