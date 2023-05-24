#include <stdio.h>
#include <stdlib.h>
/*
Linked List implementation by Shane Menzigian
Started on 5/23/23
Description: A linked list contains nodes, each one pointing to another node. Combined, they somewhat follow a list.
This program has methods for adding and deleting the first node (the head), changing specific values, and adding and deleting a node at the end of the chain.
*/
struct node{
    int data;
    struct node* next;
    };

struct node *head = NULL;

void insert_at_start(int data){
    struct node *to_add = (struct node*) malloc(sizeof(struct node));
    to_add->data = data;
    to_add->next = head;
    head = to_add;
           }

void delete_first(){
    struct node *to_delete = head;
    struct node *new_head = to_delete -> next;
    to_delete->next = NULL;
    head = new_head;
    printf("Head is %d",head->data);
    }

void insert_at_end(int data){
    struct node *first = head;
    while(first->next){
        first = first ->next;}
    struct node *to_add = (struct node*) malloc(sizeof(struct node));
    to_add->data = data;
    to_add->next = NULL;
    first->next = to_add;
    }

void print_list(){
    struct node *p = head;
    printf("\n[");
    while(p){
        printf("%d, ",p->data);
        p = p->next;
    }
    printf("]\n");
    }
int isin(int target){
    struct node *current = head;
    while(current){
        if(current->data == target){
            return 1;
        }else{current = current->next;}
        }
    return 0;
    }
int first_item(int target){
    int counter = 0;
    if(isin(target)==1){
        struct node *current =head;
        while(current){
            if(current->data == target){
                return counter;
            }
            else{
            current = current ->next;
            counter ++;}
        }
    }
    else{
        return -1;
    }}
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
    insert_at_end(10);
    print_list();
    printf("%d\n",isin(5));
    printf("%d\n",first_item(5));
    }

