/*������������ģ�� ������-������ ����*/
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

/*������Ϊ��������,�豻����������*/
struct msg {
    struct msg *next;
    int num;
};

struct msg *head;
struct msg *mp;

/* ��̬��ʼ�� һ���������� �� һ��������*/
pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *consumer(void *p)
{
    for (;;) {
        pthread_mutex_lock(&lock);
        while (head == NULL) {           //ͷָ��Ϊ��,˵��û�нڵ�    ����Ϊif��
            pthread_cond_wait(&has_product, &lock);
        }
        mp = head;      
        head = mp->next;    //ģ�����ѵ�һ����Ʒ
        pthread_mutex_unlock(&lock);

        printf("-Consume ---%d\n", mp->num);
        free(mp);
        mp = NULL;
        sleep(rand() % 5);
    }
}

void *producer(void *p)
{
    for (;;) {
        mp = malloc(sizeof(struct msg));
        mp->num = rand() % 1000 + 1;        //ģ������һ����Ʒ
        printf("-Produce ---%d\n", mp->num);

        pthread_mutex_lock(&lock);
        mp->next = head;
        head = mp;
        pthread_mutex_unlock(&lock);

        pthread_cond_signal(&has_product);  //���ȴ��ڸ����������ϵ�һ���̻߳���
        sleep(rand() % 3);
    }
}

int main(int argc, char *argv[])
{
    pthread_t pid, cid;
    srand(time(NULL));

    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);

    pthread_join(pid, NULL);
    pthread_join(cid, NULL);

    return 0;
}
