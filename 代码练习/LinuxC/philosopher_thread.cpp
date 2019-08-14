#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t m[5];			//五把锁 

void *tfn(void *arg)
{
	int i, l, r;				//编号，左右手加锁 

	srand(time(NULL));
	i = (int)arg;

	if (i == 4)					//第四个哲学家有毛病，非得反着来 
		l = 0, r = i;
	else
		l = i; r = i+1;

	while (1) {
		pthread_mutex_lock(&m[l]);		//先加左手锁 
		if (pthread_mutex_trylock(&m[r]) == 0) {	//尝试加右手锁 
			printf("\t%c is eating \n", 'A'+i);
			pthread_mutex_unlock(&m[r]);
		}
		pthread_mutex_unlock(&m[l]);
		sleep(rand() % 5);				//释放cpu给其他线程 
	}

	return NULL;
}

int main(void)
{
	int i;
	pthread_t tid[5];			//五个线程 
	
	for (i = 0; i < 5; i++)
		pthread_mutex_init(&m[i], NULL);	//初始化五把锁 

	for (i = 0; i < 5; i++)
		pthread_create(&tid[i], NULL, tfn, (void *)i);	//创建五个线程并传入编号 

	for (i = 0; i < 5; i++)					//回收五个子线程 
		pthread_join(tid[i], NULL);
	
	for (i = 0; i < 5; i++)					//销毁五把锁 
		pthread_mutex_destroy(&m[i]);

	return 0;
}


