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
    }
void delete_last(){
    struct node *to_delete = head;
    struct node *pointer_remove = head;
    while (to_delete->next){
        pointer_remove = to_delete;
        to_delete = to_delete-> next;
    }
    pointer_remove->next = NULL;
    to_delete->data = NULL;
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
        if(p->next == NULL){
            printf("%d",p->data);
        }else{
        printf("%d, ",p->data);}
        p = p->next;}
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
    printf("How long will your list be?\n");
    scanf("%d",&length);
    for(int i = 0; i<length; i++){
        int thing;
        printf("Insert integer to beginning: \n");
        scanf("%d", &thing);
        insert_at_start(thing);
        }
    print_list();

    int bonus;
    printf("Enter an integer to insert at the end: \n");
    scanf("%d",&bonus);
    insert_at_end(bonus);
    print_list();
    printf("Enter a number to search for: ");
    int to_search;
    scanf("%d",&to_search);
    if(isin(to_search)==1){
        printf("%d is in the list.\n",to_search);
    }else{
    printf("%d is not in the list.\n",isin(to_search));}

    printf("%d is at index spot %d.",to_search,first_item(to_search));
    delete_first();
    printf("Deleted the first item.\n");
    print_list();
    delete_last();
    printf("Deleted the last item.");
    print_list();
    }



