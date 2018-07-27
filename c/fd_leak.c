#include<stdio.h>
main() {

FILE * fp_leak;

while(1) {
//sleep(1);
fp_leak = fopen("test.txt","w+");
printf("file opened : %p\n",fp_leak);
fwrite("c",1,1,fp_leak);
printf(" Waiting .... \n ");

}
}
