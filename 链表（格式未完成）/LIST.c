#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	struct Node* ago;
	int data;
	struct Node* next;
} Node;
typedef struct _list
{
	Node* head;
	Node* tail;
}List;
Node* create(Node* head,int size);
Node* add(Node* head,int number);
void backspace(Node* head,int number);
void combine(Node *s1,Node *s2);
void print(Node* head);
int main()
{
	Node* head=NULL;
	Node* head_1=NULL;
	Node* head_final=NULL;
	head=create(head,7); 	
	print(head);
	head_1=create(head_1,3);
	combine(head_1,head);
	print(head_1);
}

Node* create ( Node* head ,int size)
{ int i;
    head = ( Node* ) malloc ( sizeof ( Node ) );
    head -> ago = NULL;
    head -> next = NULL;
    head -> data=1;
   	
	Node * list=head;//生成第一个 
    for (  i = 2; i <= size ; i++ )
    {
        Node * body=(Node*)malloc(sizeof(Node));
        body->ago=NULL;
        body->next=NULL;
        body->data=i;
      
        list->next=body;
        body->ago=list;
        
		list=list->next;
    }
    return head; 
}

Node* add(Node* head,int number)
{
	Node* add;
	Node* search;	
	add=(Node*)malloc(sizeof(Node));
	add->next =NULL;
	add->data =number;
	Node* q;
	for ( q = head  , search = head; search->next!=NULL; q = search , search = search -> next )
	{
		if( (q->data)<number&&number<=search->data )
		{		
			q->next =add;
			add->ago =q;
			add -> next = search;
			search->ago = add;
		}	
	}
	if( (q->data)<number&&number<=search->data )
		{		
			q->next =add;
			add->ago =q;
			add -> next = search;
			search->ago = add;
		}
	if(head->data>=number)
	{
		Node *m;
		m=head;
		head=add;
		head->next=m;
		head->ago =NULL;
		m->ago =head; 
	}
	return head;	
}
void backspace(Node* head,int number)
{
	Node * search;
	search = head;
	while(search -> data != number)
	{
		search = search -> next;
	}

	search -> ago -> next = search -> next;
	search -> next -> ago = search -> ago;

}

void print(Node* head)
{
	Node* search;
	search = head;
	while(search != NULL)
	{
		printf("%d ",search -> data);
		search = search -> next;

	}

}

void combine(Node *s1,Node *s2)
{
	Node *p1=s1->next,*p2=s1,*q1=s2->next,*q2=s2;
	if(s1==NULL)
	{
		s1=s2;
	}
	while(p1!=NULL&&q1!=NULL)
	{
		if(p1->data<q1->data )
		{
			p1=p1->next ;
			p2=p2->next ;
		}
		else
		{
			q2->next =q1->next ;
			q1->next =p2->next ;
			p2->next =q1;
			q1=q2->next ;
		}
	}
	if(q1!=NULL)
	{
		p2->next =q1;
	}
}

