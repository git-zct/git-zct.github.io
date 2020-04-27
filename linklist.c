#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	int age;
	char name[20];
	struct node *next;
}Node;
typedef struct {
	Node *head;
	Node *tail; 
	int size;
}List;
void add(List *,char *name,int age);
void dele(List *,char *name);
void sort(List *);
void swap(Node *,Node *);
void freelist(List *);
void print(List *);
int isPalindrome(List*);
int main()
{
	List list;
	list.head=NULL;
	list.size=0;
	list.tail=NULL;
	int age;
	char name[10];
	while(~scanf("%d %s",&age,name)){
			add(&list,name,age);
	} 
//	printf("print:\n");
//	print(&list);
	//printf("输入姓名删除");
//	scanf("%s",name);
//	dele(&list,name);
//		printf("print%d 个元素:\n",list.size);	print(&list);
//	printf("排序后\n");
//	sort(&list);
//	print(&list);
	printf("~~%d~~\n",isPalindrome(&list));
	Node *p=list.head;
	Node *q=NULL;
	int cnt=0;
	for(;p;p=q){
		q=p->next;
		free(p);
		cnt++;
	} 
	printf("删除了%d个元素",cnt);
}
void add(List *list,char *name,int age){
	Node *p=list->head;
	Node *q=(Node *)malloc(sizeof(Node));
	q->next=NULL;
	q->age=age;
	strcpy(q->name,name);
	if(list->tail){
		list->tail->next=q;
		list->tail=q;
		list->size++;
	} else{
		list->head=q;
		list->tail=q;
		list->size++; 
	}
}
int isPalindrome(List* list ){
    // if(!head)
    //     return true;
    Node *q=list->head; 
    Node* p=NULL,*temp=NULL,*first=q;
    while(q){//q but temp
        temp=q->next;
        q->next=p;
        p=q;
        q=temp;
    }
    list->head=p; 
    print(list);
    printf("**");
    list->head=first; 
    print(list);
    while(p&&first){
        if(p->age!=first->age)
            return -1;
        p=p->next;
        first=first->next;
    }
    return 1;
}
void dele(List *list,char *name){
	Node *q=list->head,*p=NULL;
	for(;q;p=q,q=q->next){
		if(strcmp(q->name,name)==0){
			if(p==NULL){
				list->head=q->next;
			}else{
				p->next=q->next;
			}
			free(q);
			list->size--;
			return ;
		}
	} 
}
void sort(List *list){
	Node *p=list->head,*q=NULL;
	for(;p->next;p=p->next){
		for(q=p->next;q;q=q->next){
			if(strcmp(p->name,q->name)>0){
				swap(p,q);
			}
		}
	}
}
void swap(Node *a,Node *b){
	Node temp;
	temp=*a;
	temp.next=b->next;
	b->next=a->next;
	*a=*b;
	*b=temp; 	
}
void freelist(List *);
void print(List *list){
	Node *p=list->head;
	for(;p;p=p->next){
		printf("%s %d\n",p->name,p->age);
	}
}
//12 sd
//16 asd
//14 csdd
//12 bdf
