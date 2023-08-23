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
		int k=0;
                for(i=0;i<com->n;i++)
                {
                        for(j=0;j<com->m;j++)
                        {
				com->result[k]=com->matrix[i][j];
				k++;
                        }
                }
		printf("\n");

	for(i=0;i<com->n*com->m;i++)
	{
		for(j=i+1;j<com->n*com->m;j++)
		{
			int temp;
			if(com->result[i]<com->result[j])
			{
				temp=com->result[i];
				com->result[i]=com->result[j];
				com->result[j]=temp;
			}
		}
	}

}
