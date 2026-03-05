/*
给定一个长度为n仅含有字符A和字符B构成的字符串，再给定一个期望值k，你可以将字符串中包括第i个位置以及之前的所有字符都换成A或B，使得字符串中B的个数有k个。

你需要编写程序，求出可以达成期望的i，并给出用于替换的字符。

输入格式:
测试数据有T组(1≤T≤100)。
对于每组样例，第一行输入n(1≤n≤100)和k(1≤k≤n)。
第二行，输入长度为n仅含有字符A和字符B构成的字符串s。

输出格式:
若不需要进行替换，则输出一行0
若需要进行替换，输出一行，先输出开始替换的位置i，然后再输出用于替换的字符，之间用空格隔开。
如果i有多种可能，输出最小的一种即可。
*/


#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        int m,k;int cst=0;
        scanf("%d %d",&m,&k);
        char str[10000]={0};
        getchar();
        gets(str);

        for(int j=0;j<m;j++){
            if(str[j]=='B'){
                cst++;
            }
        }
        if(cst==k){
            printf("0\n");
            continue;
        }
        else if(k>cst){
            int count=k-cst;
            for(int x=0;x<n;x++){
                if(str[x]=='A'){
                    count--;
                    if(count==0){
                        printf("%d B\n",x+1);
                    }
                }
            }

        }
        else{
            int count=-k+cst;
            for(int x=0;x<n;x++){
                if(str[x]=='B'){
                    count--;
                    if(count==0){
                        printf("%d A\n",x+1);
                    }
                }
            }

        }
    }
}