#include<stdio.h>
#include<stdlib.h>
int n;
struct process
{
	int pid;
	int at;
	int bt;
	int wt;
	int tat;
	int ct;
	int pr;
	int rnt;
	struct process * next;
};

typedef struct process node;
node * head;

/////////////////////////////////////////////input of the processes 
void input()
{
	printf("Enter the total no of processes\n");
	scanf("%d",&n);
	int i;
	node *p;

	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			p=(node *)malloc(sizeof(node));
			printf("Enter the pid   at   bt    pr\n");
			scanf("%d%d%d%d",&p->pid,&p->at,&p->bt,&p->pr);
			head=p;
			p->next=NULL;
		}

		else
		{
			p->next=(node *)malloc(sizeof(node));
                        printf("Enter the pid   at   bt    pr\n");
                        scanf("%d%d%d%d",&p->next->pid,&p->next->at,&p->next->bt,&p->next->pr);
			p=p->next;
		}

		p->wt=p->tat=0;
		p->rnt=p->bt;
	}
	p->next=NULL;
}

///////////////////////////////////////////////display the input processes 
void shownode()
{
	node * p=head;
	while(p!=NULL)
	{
		printf("%d ",p->pid);
		p=p->next;
	}
}

//////////////////////////////////////////////////fcfs
void fcfs()
{
        /////sorting
	node *p=head;
	while(p!=NULL)
	{
		node *q=p->next;
		while(q!=NULL)
		{
			if(p->at>q->at)
			{
				node * temp;
				temp->pid=p->pid;
                                temp->at=p->at;
                                temp->bt=p->bt;

                                p->pid=q->pid;
                                p->at=q->at;
                                p->bt=q->bt;

                                q->pid=temp->pid;
                                q->at=temp->at;
                                q->bt=temp->bt;
			}
			q=q->next;
		}
		p=p->next;
	}

        ////////calculating ->->->->->->->->->->->->->->->->->->->
	int tt=0;
	node * q=head;
	if(q->at==0)
	{tt+=q->at;}

	while(q!=NULL)
	{
		if(tt<q->at)
		{
			tt+=(q->at-tt);
		}
		else
		{
			tt+=q->bt;
		}
		q->ct=tt;
		q->tat=q->ct-q->at;
		q->wt=q->tat-q->bt;
		q=q->next;
	}

}

/////////////////////////////////sjf
void sjf()
{
	int i,tt=0;
	node *p;
	int complete=0;
	while(complete<n)
	{
		int mark=-1;
		int shortbt=9999;
		int j=0;
		p=head;
		while(p!=NULL)
		{
			if(p->at<=tt && p->bt<shortbt && p->tat==0)
			{
				shortbt=p->bt;
				mark=j;
			}
			j++;
			p=p->next;
		}
		if(mark==-1)
		{tt++;}

		else
		{
			node * temp=head;
			for(i=0;i<mark && temp!=NULL;i++)
			{temp=temp->next;}
			tt+=temp->bt;
			temp->ct=tt;
			temp->tat=temp->ct-temp->at;
			temp->wt=temp->tat-temp->bt;
			complete++;

		}

	}

}

////////////////////////////////priority
void priority()
{
	int i,rem=n,tt=0;
	node *p;
	while(rem>0)
	{
		int j=0,minpr=100,mark=-1;
		p=head;
		while(p!=NULL)
		{
			if(p->at<=tt && p->tat==0 && p->pr<minpr)
			{
				minpr=p->pr;
				mark=j;
			}
			j++;
			p=p->next;
		}

		if(mark==-1)
		{tt++;}
		else
		{
			node * temp=head;
			for(i=0;i<mark && temp!=NULL;i++)
			{
				temp=temp->next;
			}
			tt+=temp->bt;
			temp->tat=tt-temp->at;
			temp->wt=temp->tat-temp->bt;
			rem--;
		}
	}
}

//////////////////////////////////rr
void rr()
{
	node *p=head;
        node *temp;
        while(p!=NULL)
        {
                node * q=p->next;
                while(q!=NULL)
                {
                        if(p->at>q->at)
                        {
                                temp->pid=p->pid;
                                temp->at=p->at;
                                temp->bt=p->bt;

                                p->pid=q->pid;
                                p->at=q->at;
                                p->bt=q->bt;

                                q->pid=temp->pid;
                                q->at=temp->at;
                                q->bt=temp->bt;
                        }
                        q=q->next;
		}
                p=p->next;
	}
		int ts;
        float avgwt=0,avgtat=0;
        printf("Enter the time slice \n");
        scanf("%d",&ts);
        int ct,i,remain=n,flag=0;
        p=head;
        for(ct=0,i=0;remain!=0;)
        {
                if(p->rnt<=ts && p->rnt >0)
                {
                        ct+=p->rnt;
                        printf(" |P%d| ",p->pid);
                        p->rnt=0;
                        flag=1;
                }
                else if(p->rnt>0)
                {
                        p->rnt-=ts;
                        ct+=ts;
                        printf(" |P%d| ",p->pid);
                }
                if(p->rnt==0 && flag==1)
                {
                        remain--;
                        p->tat=ct-p->at;
                        p->wt=ct-p->at-p->bt;
                        avgwt+=ct-p->at-p->bt;
                        avgtat+=ct-p->at;
                        flag=0;
                }

                if(i==n-1)
                {
                        i=0;
                        p=head;

                }
                else if(p->next->at<=ct)
                {
                        i++;
                        p=p->next;
                }
                else
                {
                        i=0;
                        p=head;
		 }
        }
        printf("\nThe avg wt = %f\n",avgwt/n);
        printf("\nThe avg tat = %f\n",avgtat/n);

}
//////////////////////////////////show the table
void show()
{
        printf("\n");
        node *p=head;
        printf("\npid  at  bt  wt  tat\n");
        while(p!=NULL)
        {
                printf("%d    %d   %d   %d   %d  \n",p->pid,p->at,p->bt,p->wt,p->tat);
                p=p->next;
        }
        printf("\n");


}

////////////////////////////////////AVERAGE timings
void display()
{
        node *q=head;
        float avg_tat=0,avg_wt=0;
        while(q!=NULL)
        {
                avg_tat+=q->tat;
                avg_wt+=q->wt;
                q=q->next;
        }
        printf("\n%f %f\n",avg_wt,avg_tat);
        avg_wt/=n;
        avg_tat/=n;
        printf("The avg waiting time : %f\n",avg_wt);
        printf("The avg turnaround time : %f\n",avg_tat);

}
//////////////////////////////////////////////////main block
void main()
{
	input();
	sjf();
	show();
	display();
}











/*
include<stdio.h>
#include<stdlib.h>
int n;
typedef struct sch
{
        int at;
        int bt;
        int pid;
        int wt;
        int tat;
        int ct;
        int pr;
        int rnt;
        struct sch * next;
}node;

node *head;
node *head1;
node *head2;
node *head3;

void show()
{
        printf("\n");
        node *p=head;
        while(p!=NULL)
        {
                printf("%d    %d   %d   %d   %d  \n",p->pid,p->at,p->bt,p->wt,p->tat);
                p=p->next;
        }
        printf("\n");


}
void display()
{
        node *q=head;
        int total_time=0;
        float avg_tat=0,avg_wt=0;
        while(q!=NULL)
        {
                avg_tat+=q->tat;
                avg_wt+=q->wt;
                q=q->next;
        }

        avg_wt/=n;
        avg_tat/=n;

        node * p=head;
        printf("\npid  at  bt  wt  tat\n");

        /*while(p!=NULL)
        {
                printf("%d    %d   %d   %d   %d  \n",p->pid,p->at,p->bt,p->wt,p->tat);
                p=p->next;
        }*/
        printf("The avg waiting time : %f\n",avg_wt);
        printf("The avg turnaround time : %f\n",avg_tat);

}
void input(node *p)
{
        printf("Enter the number of processes \n");
        scanf("%d",&n);
        int i;
        printf("Enter the \n");
        for(i=0;i<n;i++)
        {
                if(i==0)
                {
                        p=(node*)malloc(sizeof(node));
                        printf("pid  at  bt pr\n");
                        scanf("%d%d%d%d",&p->pid,&p->at,&p->bt,&p->pr);
                        head=head=head=head=p;
                        p->next=NULL;
                }
                else
                {
                        p->next=(node*)malloc(sizeof(node));
                        printf("Enter the pid  at  bt \n");
                        scanf("%d%d%d%d",&p->next->pid,&p->next->at,&p->next->bt,&p->pr);
                        p=p->next;

                }
                p->wt=0;
                p->tat=0;
                p->rnt=p->bt;
        }
        p->next=NULL;



}


void fcfs()
{
        node *p=head;
        node * q=head->next;
        node *temp;
        while(p->next!=NULL)
        {
                while(q->next!=NULL)
                {
                        if(p->at>q->at)
                        {
                                temp->pid=p->pid;
                                temp->at=p->at;
                                temp->bt=p->bt;

                                p->pid=q->pid;
                                p->at=q->at;
                                p->bt=q->bt;

                                q->pid=temp->pid;
                                q->at=temp->at;
                                q->bt=temp->bt;
                        }
                        q=q->next;

                }
                p=p->next;

        }

        q=head;
        int total_time=0;
        if(q->at>0)
        {total_time+=q->at;}
        while(q!=NULL)
        {
                if(total_time < q->at)
                {
                        total_time+=(q->at-total_time);
                }
                else
                {
                        total_time+=q->bt;
                }
                q->ct=total_time;
                q->tat=q->ct-q->at;
                q->wt=q->tat-q->bt;
                q=q->next;

        }



}

void sjf()
{
        node *p=head1;
        int i,ct=0,j;
        node *temp=head1;

        int complete=0;
        while(complete<n)
        {
                int mark=-1;
                int short_bt=99999;
                j=0;
                p=head1;
                while(p!=NULL)
                {
                        if(p->at<=ct && p->bt<short_bt && p->tat==0)
                        {
                                short_bt=p->bt;
                                mark=j;

                        }
                        j++;
                        p=p->next;
                }

                if(mark==-1)
                {ct++;}
                else
                {
                        temp=head1;

                        for(i=0;i<mark && temp!=NULL ;i++)
                        {
                                temp=temp->next;
                        }
                        ct+=temp->bt;
                        temp->wt=ct-temp->at-temp->bt;
                        if(temp->wt<0)
                        {
                                temp->wt=0;
                        }
                        temp->tat=temp->wt+temp->bt;
                        complete++;
                }
        }

}
void priority()
{

        node *p=head2;
        node *temp;
        int remaining=n;
        int i,j,ct=0;
        while(remaining>0)
        {
                int mark=-1;
                int min_pr=100;
                j=0;
                p=head2;
                while(p!=NULL)
                {
                        if(p->at<=ct && p->bt>0 )
                        {
                                if(p->pr<min_pr)
                                {
                                        min_pr=p->pr;
                                        mark=j;
                                }

                        }
                        j++;
                        p=p->next;
                }

                if(mark==-1)
                {ct++;}
                else
                {
                        temp=head2;

                        for(i=0;i<mark && temp!=NULL ;i++)
                        {
                                temp=temp->next;
                        }
                        temp->wt=ct-temp->at;
                        ct+=temp->bt;

                        temp->bt=0;
                        temp->tat=ct-temp->at;
                        remaining--;
                }
                printf("completed %d process \n",temp->pid);
        }


}
void rr()
{
        node *p=head3;
        node *temp;
        while(p!=NULL)
        {
                node * q=p->next;

                while(q!=NULL)
                {
                        if(p->at>q->at)
                        {
                                temp->pid=p->pid;
                                temp->at=p->at;
                                temp->bt=p->bt;

                                p->pid=q->pid;
                                p->at=q->at;
                                p->bt=q->bt;

                                q->pid=temp->pid;
                                q->at=temp->at;
                                q->bt=temp->bt;
                        }
                        q=q->next;

                }
                p=p->next;

        }

        int ts;
        float avgwt=0,avgtat=0;
        printf("Enter the time slice \n");
        scanf("%d",&ts);
        int ct,i,remain=n,flag=0;
        p=head3;
        for(ct=0,i=0;remain!=0;)
        {
                if(p->rnt<=ts && p->rnt >0)
                {
                        ct+=p->rnt;
                        printf(" |P%d| ",p->pid);
                        p->rnt=0;
                        flag=1;
                }
                else if(p->rnt>0)
                {
                        p->rnt-=ts;
                        ct+=ts;
                        printf(" |P%d| ",p->pid);
                }
                if(p->rnt==0 && flag==1)
                {
                        remain--;
                        p->tat=ct-p->at;
                        p->wt=ct-p->at-p->bt;
                        avgwt+=ct-p->at-p->bt;
                        avgtat+=ct-p->at;
                        flag=0;
                }

                if(i==n-1)
                {
                        i=0;
                        p=head3;

                }
                else if(p->next->at<=ct)
                {
                        i++;
                        p=p->next;
                }
                else
                {
                        i=0;
                        p=head3;
                }
        }

        printf("\nThe avg wt = %f\n",avgwt/n);
        printf("\nThe avg tat = %f\n",avgtat/n);



}
oid copy(node *t,node *q,node *r,node *s)
{
        while(t!=NULL)
        {
                q->pid= r->pid =s->pid =t->pid;
                q->at= r->at =s->at =t->at;
                q->bt =r->bt =s->bt =t->bt;
                q->wt =r->wt =s->wt =t->wt;
                q->tat =r->tat =s->tat =t->tat;
                t=t->next;
        }

}
int main()
{
        node *t;
        node *q;
        node *r;
        node *s;
        input(t);

        void copy(t,q,r,s);
        head1=q;
        head2=r;
        head3=s;

/*      while(1)
        {
                printf("\nEnter the choice : \n1: FCFS\n2: SJF\n3: RR\n4: PS1\n");
                int ch;
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:
                                {
                                        fcfs();
                                        display();
                                        break;
                                }

                        case 2:
                                {
                                        sjf();
                                        display();
                                        break;
                                }
                        case 3:
                                {
                                        priority();
                                        display();
                                        break;
                                }
                        case 4:
                                {
                                        rr();
                                        break;
                                }
                        default:
                                {return;}
                }
        }*/
}



*/

