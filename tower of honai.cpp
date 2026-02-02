#include<stdio.h>
void towerofhonai(int n, char s, char d, char t) {
  if (n==1) {
printf("move disk %d from %c" , n,s,d);
return ;
  }
towerofhonai (n-1, s, t, d );
printf("\n move disk %d from %c to %c", n,s,d);
towerofhonai( n, s, d, t);
printf("\n move disk %d from %c to %c",n,s,d);
towerofhonai(n-1,t,d,s);
}





int main() {
  int n;
char s,d,t;
printf("enter the number of disks:");
scanf("%d" ,&n);
towerofhoani(n,'s','d','t');
}
