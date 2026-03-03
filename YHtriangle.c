#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int num[100][100]={0};
    num[0][0]=1;
    for(int i=0;i<n;i++){
        num[i][0]=1;
    }

    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            num[i][j]=num[i-1][j]+num[i-1][j-1];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            printf("%4d",num[i][j]);
        }
        printf("\n");
    }
    return 0;
}