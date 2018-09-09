//
//  main.cpp
//  occ
//
//  Created by Peeraphat Komolruchinonth on 9/9/18.
//  Copyright © 2018 Peeraphat Komolruchinonth. All rights reserved.
//

#include <iostream>
using namespace std;
void preBmBc(char *x,int m,int bmBc[]);
void BM (char *x,int m ,char *y,int n);
void preBmGs (char *x,int m,int bmGs[]);
int MAX(int a ,int b);
int main() {
    int bmBc[255],bmGs[255];
//    preBmBc("Text",4,bmBc);
    BM("ANPANMAN",8,"ANPAXMANPANMANMANPANMAN",23);
//    preBmGs(x,m,bmGs);
}
void preBmBc(char *x,int m,int bmBc[])
{
    int i;
    for(i=0;i <= 255 ; ++i)
        bmBc[i] = m;
    for(i = 0;i < m; ++i){
        bmBc[x[i]] = m-i-1;
        printf("bmBc[%c] = %d/n",x[i],bmBc[x[i]]);
    }
}
void BM (char *x,int m ,char *y,int n)
{
    int i,j,bmGs[255],bmBc[255];
    preBmGs(x,m,bmGs);
    printf("\n");
    preBmBc(x,m,bmBc);
    
    j=0;
    while(j <= n-m){
        for(i = m-1;i >= 0 && x[i] == y[i+j]; --i);
        if(i < 0) {
            printf("Found at %d \n",j);
            j += bmGs[0];
        }
        else {
            /*printf("bmBc[%c] = %d m = %d\n",y[i+j],bmBc[y[i+j]],m);
            printf("j = %d\n",j);
            j += bmBc[y[i+j]] - m + 1 + i;
            printf("j = %d\n",j);*/
            j += MAX(bmGs[i],bmBc[y[i+j]] - m + 1 + i);
        }
    }
}
void suffixes(char *x,int m ,int *suff)
{
    int f,g,i;
    
    suff[m-1] =m;
    g = m-1;
    for (i = m - 2 ; i >=0 ; --i){
        if(i > g && suff[i + m -1 - f] < i - g)
            suff[i] = suff[i + m - 1 -f];
        else {
            if (i < g)
                g = i ;
            f = i;
            while (g > 0 && x[g] == x[g + m - 1 -f])
                --g;
            suff[i] = f - g;
        }
    }
    for(i = 0;i < m ; i++)
    {
        printf("suff[%d] = %d\n",i,suff[i]);
    }
}
void preBmGs (char *x,int m,int bmGs[])
{
    int i,j,suff[255];
    suffixes(x,m,suff);
    
    for(i = 0; i < m; ++i)
        bmGs[i] = m;
    j = 0;
    
//section 1
    for ( i = m - 1; i >= -1 ; --i)
        if(i == -1 || suff[i] == i+1)
            for(; j < m - 1 - i ; ++j)
                if(bmGs[j] == m){
                    bmGs[j] = m - 1 - i;
                }
//section 2
    for ( i = 0; i <= m - 2 ; ++i){
        bmGs[m - 1 - suff[i]] = m - 1 - i;
    }
    for(i = 0 ; i < m ; ++i)
    printf("bmGs[%d] = %d\n",i,bmGs[i]);
}
int MAX(int a ,int b)
{
    if (a>b) return a;
    else return b;
}
