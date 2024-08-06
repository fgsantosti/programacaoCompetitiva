
//https://vjudge.net/problem/UVA-573
#include <stdio.h>
#define EPS 1e-9

int main(int argc, char const *argv[])
{
    int h,u,d,_f,day,flag;
    double pos, pen, tmp,f;

    while (scanf("%d %d %d %d", &h,&u,&d,&_f), h){
        pos=0; day=0;flag=0;pen=0; f=(_f/100.)*u;
        do
        {
           tmp = u - pen;
           if(tmp > EPS) pos +=tmp;
           pen += f;
           if(pos > h + EPS) flag = 1;
           else{
            pos -= d;
            if(pos < -EPS) flag = 2;
           }
           day++;
        } while (!flag);
        printf("%s on day %d\n", 
                flag == 1 ? "success" : "failure", day);
    }
    
    return 0;
}
