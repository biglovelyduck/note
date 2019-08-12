#include <stdio.h>
#include <stdlib.h>     //qsort()ͷ�ļ�

#define M 100002

typedef struct Edge     //��
{
    int S;      //����S
    int E;      //����E
    int L;      //ͨ��ʱ��L
} Edge;

Edge e[M];      //ʵ������

int far[M];     //����ָ��
int C[M];       //����ţ̸��ʱ��
int sum = 0;
int N, P;       //N����㣬P����

//qsort()��Ҫ���õ�ָ��
int cmp(const void *a, const void *b)
{
    Edge *c = (Edge *)a;        //��ָ��void *aǿ��ת����(Edge *)a������ָ��Edge *c
    Edge *d = (Edge *)b;        //��ָ��void *bǿ��ת����(Edge *)b������ָ��Edge *d
    return c->L - d->L;         //��С��������
}

//Ѱ�Ҹ���㣬�����м���ı�Ƕ�ָ������
int find(int x)
{
    int i, k, r;
    r = x;
    //Ѱ�Ҹ����
    while (far[r] >= 0)
        r = far[r];
    k = x;
    //����x���һֱ��������м����еĽ�����һ������Ƕ�ָ������
    while (k != r)
    {
        i = far[k];
        far[k] = r;
        k = i;
    }
    //���ظ����
    return r;
}

//�������������
void Union(int S, int E)
{
    int rS, rE;
    int num;
    rS = find(S);
    rE = find(E);
    num = far[rS] + far[rE];        //��Ϊ����
    //�������
    if(far[rS] < far[rE])
    {
        far[rE] = rS;
        far[rS] = num;
    }
    else
    {
        far[rS] = rE;
        far[rE] = num;
    }
}

//Kruskal�㷨����С������
int Kruskal()
{
    int i;
    int S, E;
    int sumweight = 0, count = 0;
    for(i = 0; i < N; i++)      //��ʼ��far
        far[i] = -1;
    qsort(e, P, sizeof(e[0]), cmp);     //�Աߵ�Ȩ������С��������
    for(i = 0; i < P; i++)
    {
        S = e[i].S;
        E = e[i].E;
        //���S�ĸ���㲻����E�ĸ���㣬˵��û�����ɻ�·����ѡȡ������
        if(find(S) != find(E))
        {
            sumweight += e[i].L;
            Union(S, E);
            count++;        //����
            if(count >= N - 1)
            {
                break;
            }
        }
    }
    return sumweight;
}

int main ()
{
    int i, min = M;
    int S, E, L;        //����S������E��ͨ��ʱ��L

    scanf ("%d %d", &N, &P);

    for (i = 0; i < N; i++)
    {
        scanf ("%d", &C[i]);
        //ѡȡ˯���ĵط�
        if (C[i] < min)
            min = C[i];
    }

    for (i = 0; i < P; i++)
    {
        scanf("%d %d %d",&S, &E, &L);
        //����Ǵ�0��ʼ�洢��������������Ľ����Ҫ��һ�洢
        e[i].S = S - 1;
        e[i].E = E - 1;
        //��С��������������Ҫ��Ҫ��ο���е���ţ���ͱ��뿼�ǵ�����
        e[i].L = L * 2 + C[S - 1] + C[E - 1];       //��һ����㵽��һ������ٷ�������ʱ�䣨����̸��ʱ�䣩
    }

    printf ("%d\n", min + Kruskal());       //��˯�����������̸һ�λ�
    return 0;
}
