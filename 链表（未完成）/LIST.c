#include <stdio.h>
#include <stdlib.h>
//我觉得所有的指针都可以理解成一个整型变量存地址嘛，不要收到前面的类型影响 

typedef struct Node
{
	struct Node* ago;
	int data;
	struct Node* next;
} Node;

/*typedef struct _list
{
	Node* head;
//	Node* tail;
}List;*/
Node* create(Node* head;);
void add(Node* head,int number);
void backspace(Node* head,int number);
//void combine();
void print(Node* head);
int main()
{
	Node* head=NULL;
	head=create(head); 
	print(head);
	add(head,2);
	print(head);
}

Node* create ( Node* head )
{ int i;
    head = ( Node* ) malloc ( sizeof ( Node ) );
    head -> ago = NULL;
    head -> next = NULL;
    head -> data=1;
   	
	Node * list=head;//生成第一个 
    for (  i = 2; i <= 3 ; i++ )
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

void add(Node* head,int number)
{
	Node* add;
	Node* search;	
	add=(Node*)malloc(sizeof(Node));
	add->next =NULL;
	add->data =number;
	Node* q;
	for ( q = head  , search = head; search->next!=NULL ; q = search , search = search -> next )
	{
		if( (q->data)<=number&&number<=search->data )
		{	search -> next = add;
			add->ago =search;
		}
	}
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


