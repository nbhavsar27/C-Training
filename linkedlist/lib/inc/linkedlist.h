/*!
 * \author Dhaval Joshi
 * \date 15-02-21
 * \mainpage Linked List 
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include "./structureDefinition.h"

void createlist(int n);
void print_node(struct node *ptr);
void add_node(int a);
void add_begin(int a);
void pos_node(struct node *ptr,int a ,int pos);
struct node* node_begin(int a);
struct node* del_begin();
struct node* del_pos(int pos);
struct node* del_entire();
void del_end();

