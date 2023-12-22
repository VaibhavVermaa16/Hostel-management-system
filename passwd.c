#include<stdio.h>

int main(){
    FILE *fptr = fopen("Password.txt", "w");
    int x;
    scanf("%d", &x);
    fwrite(&x,sizeof(x) ,1,fptr);
    fclose(fptr);
    
}