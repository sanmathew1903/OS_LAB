#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/shm.h>
typedef struct mem
{
        int n,m;
        int num[3][3];
        int trans[3][3];
}node ;

void main()
{
        node * com;
        int key =98765;
        int shmid=shmget(key,sizeof(node),IPC_CREAT| 0666);
        com=(node * )shmat(shmid,NULL,0);
///////get the sizes
        int n=com->n;
        int m=com->m;
        int i,j;
///////calculate the transpose of the matrix
        for(i=0;i<m;i++)
        {
                for(j=0;j<n;j++)
                {
                        com->trans[i][j]=com->num[j][i];
                }
        }
///////print the transpose
        printf("The Transpose of the matrix is :\n");
        for(i=0;i<n;i++)
        {
                printf("\n");
                for(j=0;j<m;j++)
                {
                        printf(" %d ",com->trans[i][j]);
                }
        }
        printf("\n");
}
