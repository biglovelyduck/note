#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{

	char name[100];
    int id;
}Student;
/*���ַ�������*/

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
	printf("����Ҫ��ӵ�ѧ������:");
	scanf("%d",&n);
    Student*  s=(Student*)malloc(sizeof(Student)*n);
	for(int i=0;i<n;i++){
	
		printf("�������%d��ѧ������:",i+1);
        fflush(stdin);
		scanf("%s",&s[i].name);
	//	getchar();
		printf("�������%d��ѧ��ѧ��:",i+1);
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
	printf("�����������Ľ��Ϊ:\n");
	for(int k=0;k<n;k++) printf("%s  ",name_arr[k]);
	free(s);
	s=NULL;
}