/*��������
����������ǰ��ʱ�䣬����Ӣ�ĵĶ���������������
����ʱ����ʱh�ͷ�m��ʾ����Ӣ�ĵĶ����У���һ��ʱ��ķ����ǣ�
�������mΪ0����ʱ��������Ȼ����ϡ�o'clock������3:00������three o'clock����
�������m��Ϊ0����ʱ��������Ȼ�󽫷ֶ���������5:30������five thirty����
����ʱ�ͷֵĶ���ʹ�õ���Ӣ�����ֵĶ���������0~20������
����0:zero, 1: one, 2:two, 3:three, 4:four, 5:five, 6:six, 7:seven, 8:eight, 9:nine, 10:ten, 11:eleven, 12:twelve, 13:thirteen, 14:fourteen, 15:fifteen, 16:sixteen, 17:seventeen, 18:eighteen, 19:nineteen, 20:twenty��
����30����thirty��40����forty��50����fifty��
�������ڴ���20С��60�����֣����ȶ���ʮ������Ȼ���ټ��ϸ�λ������31���ȶ�30�ټ�1�Ķ�����������thirty one����
����������Ĺ���21:54������twenty one fifty four����9:07������nine seven����0:15������zero fifteen����
�����ʽ
����������������Ǹ�����h��m����ʾʱ���ʱ�ͷ֡����������ǰû��ǰ��0��hС��24��mС��60��
�����ʽ
�������ʱ��ʱ�̵�Ӣ�ġ�
��������
0 15
�������
zero fifteen
*/ 
#include <stdio.h>  
  
void printTime(int n)  
{  
    switch(n)  
    {  
        case 0: printf("zero"); break;  
        case 1: printf("one") ; break;  
        case 2: printf("two"); break;  
        case 3: printf("three"); break;  
        case 4: printf("four"); break;  
        case 5: printf("five"); break;  
        case 6: printf("six"); break;  
        case 7: printf("seven"); break;  
        case 8: printf("eight"); break;  
        case 9: printf("nine"); break;  
        case 10: printf("ten"); break;  
        case 11: printf("eleven"); break;  
        case 12: printf("twelve"); break;  
        case 13: printf("thirteen"); break;  
        case 14: printf("fourteen"); break;  
        case 15: printf("fifteen"); break;  
        case 16: printf("sixteen"); break;  
        case 17: printf("seventeen"); break;  
        case 18: printf("eighteen"); break;  
        case 19: printf("nineteen"); break;  
        case 20: printf("twenty"); break;  
        default:  
            if(n<40)  
            printf("thirty");  
            else if(n<50)  
            printf("forty");  
            else if(n<60)  
            printf("fifty");  
  
            break;  
    }  
      
    return ;  
}  
  
main()  
{  
    unsigned int h,m;  
      
    scanf("%d%d",&h,&m);  
      
      if(h<=24&&m<=60){
      
    //���Сʱ   
    if(h>20)  
    {  
        printTime(20);  
        printf(" ");  
        printTime(h%10);  
        printf(" ");  
    }  
    else  
    {  
        printTime(h);  
        printf(" ");  
    }  
    //�������  
    if(m)  
    {  
            if(m>20)  
            {  
                printTime(m/10*10);  
                printf(" ");  
                printTime(m%10);  
            }  
            else  
            {  
                printTime(m);  
            }  
    }  
    else  
    {  
        printf("o'clock");  
    }  
      
    printf("\n");  
  }
    return 0;  
}   
