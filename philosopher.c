#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
sem_t s[10];
void * philo(void * n)
{
	int ph=*(int *)n;
	printf("Philosopher %d came to eat \n",ph);

	printf("Philosopher %d takes left fork \n",ph);
	sem_wait((&s[ph]));

	printf("Philosopher %d takes right fork \n",ph);
        sem_wait(&s[(ph+1)%5]);

	printf("\nPHILOSOPHER %d COMPLETES EATING \n\n ",ph);

	printf("Philosopher %d keeps back left fork \n",ph);
        sem_post(&s[ph]);

        printf("Philosopher %d keeps back  right fork \n",ph);
        sem_post(&s[(ph+1)%5]);
}

int main()
{
	int i,p[5];
	pthread_t thread[5];
	for(i=0;i<5;i++)
	{
		sem_init(&s[i],0,1);
	}

	for(i=0;i<5;i++)
	{
		p[i]=i;
		pthread_create(&thread[i],NULL,philo,(void*)&p[i]);
	}

	for(i=0;i<5;i++)
	{
		pthread_join(thread[i],NULL);
	}
}
