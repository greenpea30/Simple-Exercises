#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char *p[1000];
    int i=0;
    //read in
    p[i] = (char*)malloc(1000);
    gets(p[i]);
    while(strcmp(p[i],"#")!=0){
        i++;
        p[i] = (char*)malloc(1000);
        gets(p[i]);
    }
    //sorting
    int len=-1;
    for (int m = 0; m < i - 1; m++) {           // 外层：控制轮数
        for (int j = 0; j < i - 1 - m; j++) {   // 内层：相邻比较
            if (strlen(p[j]) > strlen(p[j+1])) {
                char *temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    for(int j=0;j<i;j++){
        printf("%s ",p[j]);
        free(p[j]);
    }

    return 0;
}