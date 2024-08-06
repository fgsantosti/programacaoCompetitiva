#include<stdio.h>

#define MAX 1123456
typedef long long ll;
int a[MAX], flag[MAX];

int main(){
    int x;

    while (scanf("%d", &x) != EOF){
    if(x>=0 && x<=100)
        if(x==0)printf("vai ter copa!\n");
        else printf("vai ter duas!\n");
    }
    return 0;
}