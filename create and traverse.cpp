#include<stdio.h>
#include<cstdlib>
#include<iostream>
using namespace std;

// struct data type contain 4 byte for int(data) and 4 byte for pointer to node(link)
struct node
{
    int data;
    node* link;
};

int main()
{

    node* A; // A is created to store pointer to head node
    /*
    pointer to node temp is created for storing the new node (which consists of two part- one
    for value and another for address for next node)

    temp is used for creating isolate memory block for node
    */
    node* temp=new node(); // this allocates memory block for temp(pointer to node) [C++ version]

    /* this intial the head block of linked list */
    temp->data=0;
    temp->link=NULL;

    // address of head block is stored in A
    A=temp;

    node* t=A; // this is for adding new memory block/ node to linked list

    for(int i=0; i<4; i++)
    {
        temp=(node*) malloc(sizeof(node)); // this is version of creating memory block for temp
        int x; // for taking user input
        cin>>x;
        /*
        first assign this value to data and set link to null because I am not sure there will
        be anymore element or not
        */
        temp->data=x;
        temp->link=NULL;

        t->link=temp; /* here t contains prevoius nodes values and address of
					  the newly created node's address which actuall denote the previous node*/

        t=t->link;  /* increment the t for pointing the new node, noew t is poining
					to new node which have new value and next node address NULL */
    }

    node *p=A; // assign the pointer to head node to another pointer to traverse the list

    while(p!=NULL)  /* here p denotes the address
					(when we write p it means address and *p or p-> means dereferencing) */
    {
        printf("%d\n", p->data );
        p=p->link;
    }
    return 0;
}
