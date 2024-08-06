#include <stdio.h>
//#include<bits/stdc++.h>
//using namespace std;

#define MAX 1123456
typedef long long ll;
int a[MAX], flag[MAX];

int main(void){
    int n, i, nxt, stars=0;
    ll sheep =0;
    scanf("%d", &n);
    //memset(flag, 0, sizeof(flag));
    for (i = 1; i <= n; i++) flag[i]=0;
    for (i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        sheep += a[i];
    }
    i = 1;
    do{
        flag[i] = 1;
        nxt = i + ((a[i] & 1) ? 1 : -1);
        //nxt = i + ((a[i] % 2 == 1) ? 1 : -1);
        if(a[i]){ 
            a[i]--; 
            sheep--;
        }
        i = nxt;
    } while (i >= 1 && i <= n);
    for (i = 1; i <= n; i++) stars += flag[i];
    printf("%d %lld\n", stars, sheep);
    
    return 0;
}
