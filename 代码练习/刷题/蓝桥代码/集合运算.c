
/*��������
��������������������A��B��������ǵĽ����������Լ�B��A�е��༯��
�����ʽ
������һ��Ϊһ������n����ʾ����A�е�Ԫ�ظ�����
�����ڶ�����n��������ͬ���ÿո��������������ʾ����A�е�Ԫ�ء�
����������Ϊһ������m����ʾ����B�е�Ԫ�ظ�����
������������m��������ͬ���ÿո��������������ʾ����B�е�Ԫ�ء�
���������е�����Ԫ�ؾ�Ϊint��Χ�ڵ�������n��m<=1000��
�����ʽ
������һ�а���С�����˳�����A��B�����е�����Ԫ�ء�
�����ڶ��а���С�����˳�����A��B�����е�����Ԫ�ء�
���������а���С�����˳�����B��A�е��༯�е�����Ԫ�ء�
��������
5
1 2 3 4 5
5
2 4 6 8 10
�������
2 4
1 2 3 4 5 6 8 10
1 3 5
��������
4
1 2 3 4
3
5 6 7
�������
1 2 3 4 5 6 7
1 2 3 4*/ 
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



#define MAXS 1000
int i,j,temp;
//���뺯��
void scan(int *colc,int n)
{
    int i;
    for (i = 0; i < n ; i ++)
    {
        scanf("%d",&colc[i]);    
    }    
}
//������
void sort(int *colc,int n)
{
    for (i = 0; i < n-1; i ++)
    {
        for (j = 0; j < n-1-i; j ++)
        if(colc[j]>colc[j+1])
        {
            temp = colc[j];
            colc[j] = colc[j+1];
            colc[j+1] = temp;
        }
    }
}

int main()
{
    int n,m,a=0;
    int colcn[MAXS],colcm[MAXS];
    scanf("%d",&n);    
    scan(colcn,n);
        
    scanf("%d",&m);
    scan(colcm,m);    
    
    sort(colcn,n);
    sort(colcm,m);
    //A��B����
    i=0,j=0;
    while(i < n && j < m)
    {
        if(colcn[i] > colcm[j])//���Ѿ��ź��� 
        j++;
        else if(colcn[i] < colcm[j])
        i ++;
        else//������� 
        {
            printf("%d ",colcn[i]);
            i ++;//�����ͬ���� 
            j ++;
        }
    }
     printf("\n");
     //A��B����
     i=0,j=0;
     while(i < n && j < m)
    {
        if(colcn[i] > colcm[j])
        printf("%d ",colcm[j++]);
        else if(colcn[i] < colcm[j])
        printf("%d ",colcn[i++]);
        else
        {
            printf("%d ",colcn[i]);    
            i ++;
            j ++;
        }
    }        
    while (i < n) printf("%d ", colcn[i++]);
    while (j < m) printf("%d ", colcm[j++]);
     printf("\n");
     //B��A�е��༯
     i=0,j=0;
     while(i < n && j < m)
    {
        if(colcn[i] > colcm[j])
        j++;
        else if(colcn[i] < colcm[j])
        printf("%d ",colcn[i++]);
        else
        {    
            i ++;
            j ++;
        }
    }
    while (i < n) printf("%d ", colcn[i++]);
     printf("\n");
    return 0;
}
