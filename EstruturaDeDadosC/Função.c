#include<stdio.h>

int main (){
    
    int n,i,f = 1;
    printf("Dingite n: \n");
    scanf("%d" , &n);
    for( i = 1 ; i <= n; i++);
    f=f*i;
    printf(" FActorial de n = %d\n" , f);


    return 0;
}