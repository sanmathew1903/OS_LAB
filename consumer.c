#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<fcntl.h>
#include<sys/shm.h>
typedef struct mem
{
        int num;
}node ;

void main()
{
	node * com;
        int key =9876;
        int shmid=shmget(key,sizeof(node),IPC_CREAT| 0666);
        com=(node * )shmat(shmid,NULL,0);

        sem_t *empty=sem_open("ES",O_CREAT,0666,5);
        sem_t *full=sem_open("FS",O_CREAT,0666,0);
        sem_t *semaphore=sem_open("SS",O_CREAT,0666,1);

        while(10)
        {
                sem_wait(full);
                sem_wait(semaphore);
                printf("Consumed : %d\n",com->num);
                sem_post(semaphore);
                sem_post(empty);
	}
}

