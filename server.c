#include<stdio.h>
#include<sys/shm.h>

typedef struct memory
{
	int matrix[10][10];
	int result[100];
	int n;
	int m;
}node ;
node *com;
void main()
{
	int shmid,i,j;
	int key=12345;
	shmid=shmget(key,sizeof(node *),IPC_CREAT | 0666);
	com=(node *) shmat(shmid,NULL,0);
		printf("Success\n");
		printf("Enter the values of n m:\n");
		scanf("%d%d",&com->n,&com->m);
		printf("Enter the matrix \n");
		for(i=0;i<com->n;i++)
		{
			for(j=0;j<com->m;j++)
			{
				scanf("%d",&com->matrix[i][j]);
			}
		}

	sleep(5);
	for(i=0;i<3;i++)
	{
		printf("%d ",com->result[i]);
	}

}
