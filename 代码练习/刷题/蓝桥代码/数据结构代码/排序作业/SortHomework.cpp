#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{

	char name[100];
    int id;
}Student;
/*按字符串排序*/

void sort1(char *a[],int n)
{
    int i,j;
    char *temp;
	//int len=sizeof(a)/sizeof(a[0]);
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(strcmp(a[j],a[j+1])>0)
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void main(){

	int n;	
	printf("输入要添加的学生个数:");
	scanf("%d",&n);
    Student*  s=(Student*)malloc(sizeof(Student)*n);
	for(int i=0;i<n;i++){
	
		printf("请输入第%d个学生姓名:",i+1);
        fflush(stdin);
		scanf("%s",&s[i].name);
	//	getchar();
		printf("请输入第%d个学生学号:",i+1);
		fflush(stdin);
		scanf("%d",&s[i].id);

	}
	//for(int j=0;j<n;j++) printf("%s",s[j].name);

	char *name_arr[100];
	char *p;
	for(int j=0;j<n;j++){
	
		name_arr[j]=s[j].name;
		
		//sprintf(p,"%d",s[j].id);
		//strcat(name_arr[j],p);
	}
	//for(int m=0;m<n;m++) printf("%s",name_arr[m]);

	sort1(name_arr,n);
	printf("按名字排序后的结果为:\n");
	for(int k=0;k<n;k++) printf("%s  ",name_arr[k]);
	free(s);
	s=NULL;
}