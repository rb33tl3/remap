#include<stdio.h>
#include<stdlib.h>

struct Node 
    {
        int coeff;
        int exp;
        struct Node* next;

    };

struct Node* createnode(int coeff,int exp)
    {
        struct Node* newnode;
        newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->coeff=coeff;
        newnode->exp=exp;
        newnode->next=NULL;
        return newnode;
    };

struct Node* insertterm(struct Node* head,int coeff,int exp)
    {

        struct Node* newnode,*temp;
        newnode=(createnode(coeff,exp));

        if (head==NULL)
            {
                return newnode;
            }
    
        else
            {
                temp=head;
                while (temp->next!=NULL)
                    {
                        temp=temp->next;
                    }
                temp->next=newnode;
                return head;
            }
            
    }

void display(struct Node* head)
    {
        struct Node* temp=head;
        while(temp!=NULL)
            {
                printf("%dx^%d",temp->coeff,temp->exp);
                
                if(temp->next!=NULL)
                    {
                        printf("+");
                       
                   }
            
            temp=temp->next;    
            }
            printf("\n");
    
    
        }   


struct Node* addpolunomials(struct Node* p1,struct Node* p2)
    {
        struct Node* result=NULL;
        while(p1!=NULL&&p2!=NULL)
            {

                if(p1->exp==p2->exp)
                    {

                        result=insertterm(result,p1->coeff+p2->coeff,p1->exp);
                        p1=p1->next;
                        p2=p2->next;
                    }

                else if(p1->exp>p2->exp)
                    {

                        result=insertterm(result,p1->coeff,p1->exp);
                        p1=p1->next;
                    }
                    else
                    {

                        result=insertterm(result,p2->coeff,p2->exp);
                        p2=p2->next;
                    }
            }
        while(p1!=NULL)
            {
                result=insertterm(result,p1->coeff,p1->exp);
                p1=p1->next;
                
            }
        while(p2!=NULL)
            {
                result=insertterm(result,p2->coeff,p2->exp);
                p1=p1->next;
                
            }
        return result;
    
    }


        
int main()
    {
        struct Node* p1=NULL;
        struct Node* p2=NULL;
        struct Node* sum=NULL;

        int exp,coeff,n1,n2,i;

        printf("enter the nof terms in 1st polynomial");
        scanf("%d",&n1);

        printf("enter the nof terms in 2nd polynomial");
        scanf("%d",&n2);
        printf("Enter the coeff and expression of 1st polynomial");

        for(i=0;i<n1;i++)
            {
                
                scanf("%d %d",&coeff,&exp);
               p1=insertterm(p1,coeff,exp);

            }
        display(p1);
         printf("Enter the coeff and expression of 2nd polynomial");

        for(i=0;i<n2;i++)
            {
                
                scanf("%d %d",&coeff,&exp);
                p2=insertterm(p2,coeff,exp);

            }    
        display(p2);
        printf("SUM");
        sum=addpolunomials(p1,p2);
        display(sum);
        return 0;
        }