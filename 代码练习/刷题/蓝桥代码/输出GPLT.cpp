#include <stdio.h>
#include <string.h>
int main(){
    char a[10010];//存取输入的字符串 
    int e=0,b=0,c=0,d=0;
    scanf("%s",a);
    int n=strlen(a);
    for (int i=0;i<n;i++){//判断各自的数量 
        if (a[i]=='G'||a[i]=='g'){
        b++;
        }
        else if (a[i]=='P'||a[i]=='p'){
            c++;
        }
        else if (a[i]=='L'||a[i]=='l'){
            d++;
        }
        else if (a[i]=='T'||a[i]=='t'){
            e++;
        }
    }
    while(1){
        if (b>0){
            printf("G");
            b--;
        }
        if (c>0){
            printf("P");
            c--;
        }
        if (d>0){
            printf("L");
            d--;
        }
        if (e>0){
            printf("T");
            e--;
        }
        if (b==0&&c==0&&d==0&&e==0){
            printf("\n");
            break;
        }
    }
    return 0;
}
