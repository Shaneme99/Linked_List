#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
    };

struct node *head = NULL;
struct node *next = NULL;

void insert_at_start(int data){
    struct node *begin = (struct node*) malloc(sizeof(struct node));
    begin->data = data;
    begin->next = head;
    head = begin;
           }
void delete_last(){
    struct node *to_delete = head;
    struct node *new_head = to_delete -> next;
    to_delete->next = NULL;
    head = new_head;
    printf("Head is %d",head->data);

    }

void print_list(){
    struct node *p = head;
    printf("\n[");
    while(p){
        printf("%d",p->data);
        p = p->next;
    }
    printf("]\n");
    }

void main(){
    int length;
    printf("Hello! How long will your list be?\n");
    scanf("%d",&length);
    for(int i = 0; i<length; i++){
        int thing;
        printf("Insert number: \n");
        scanf("%d", &thing);
        insert_at_start(thing);
    }
    print_list();
    delete_last();
    print_list();
    }

