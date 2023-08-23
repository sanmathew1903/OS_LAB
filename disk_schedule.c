#include<stdio.h>
#include<stdlib.h>
int initial;
int r[10];
int sk,n;
void input()
{
	printf("Enter the no of process \n");
	scanf("%d",&n);
	printf("Enter the initial position \n");
	scanf("%d",&initial);
	printf("Enter the p sequence \n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&r[i]);
	}
}

void fcfs()
{
	for(int i=0;i<n;i++)
	{
		sk+=abs(r[i]-initial);
		initial=r[i];
	}
	printf("Seek time : %d" ,sk);
}

void sstf()
{
	sk=0;
	int index[10],min,pos,kk=0,seq[10];
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
	        {
	                index[i]=abs(r[i]-initial);
	        }

		min=index[0];
		pos=0;
		for(int p=0;p<n;p++)
		{
			if(index[p]<min)
			{
				min=index[p];
				pos=p;
			}
		}

		seq[kk]=r[pos];
		kk++;
		r[pos]=999;
	}
	sk+=abs(initial-seq[0]);
                for(int i=1;i<n;i++)
                {
                        sk+=abs(seq[i-1]-seq[i]);
                }

                printf("total movement : %d",sk);

}

void scan()
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(r[i]>r[j])
            {
                int temp=r[i];
                r[i]=r[j];
                r[j]=temp;
            }
        }
    }

    int pos;
    for(int i=0;i<n;i++)
    {
        if(r[i]>initial)
        {
            pos=i;
            break;
        }
    }
    sk+=abs(initial-r[pos]);
    printf("%d - %d",initial,r[pos]);
    for(int i=pos;i<n-1;i++)
    {
        sk+=abs(r[i]-r[i+1]);
        printf("-%d",r[i+1]);
    }
    sk+=abs(r[n-1]-199);
    printf("-199");

    sk+=abs(199-initial);
    
    sk+=abs(initial-r[pos-1]);
    printf("-%d",r[pos-1]);

    for(int i=pos-1;i>0;i--)
    {
        sk+=abs(r[i]-r[i-1]);
        printf("-%d",r[i-1]);
    }

    printf("\ntime: %d",sk);

}

void cscan()
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(r[i]>r[j])
            {
                int temp=r[i];
                r[i]=r[j];
                r[j]=temp;
            }
        }
    }

    int pos;
    for(int i=0;i<n;i++)
    {
        if(r[i]>initial)
        {
            pos=i;
            break;
        }
    }
    sk+=abs(initial-r[pos]);
    printf("%d - %d",initial,r[pos]);
    for(int i=pos;i<n-1;i++)
    {
        sk+=abs(r[i]-r[i+1]);
        printf("-%d",r[i+1]);
    }
    sk+=abs(r[n-1]-199);
    printf("-199");

    sk+=abs(199-0);
    printf("-0");
    
    sk+=abs(0-r[0]);
    printf("-%d",r[0]);

    for(int i=0;i<pos-1;i++)
    {
        sk+=abs(r[i]-r[i+1]);
        printf("-%d",r[i+1]);
    }

    printf("\ntime: %d",sk);
}

int main()
{
	input();
	sstf();
}
