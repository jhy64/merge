#include <stdio.h>
#include <stdlib.h>


struct node{
    struct node * next;
    int value;
} node;

typedef struct node Node;


Node * newList( int num ){
    Node * list = 0;
    Node * cur = 0;
    Node * head = 0;
    int val = 0;
    int variance = 10;
    int i;

    if( num == 0 ) {
        return 0;
    }
    cur = (Node *)malloc( sizeof(Node) );
    cur->value = rand() % variance;
    cur->next = 0;
    head = cur;
    list = cur;

    for( i = 1; i < num; i++ ) {
        cur = (Node *)malloc( sizeof(Node) );
        cur->next = 0;
        cur->value = list->value + (rand() % variance);
        list->next = cur;
        list = cur;
        
    }   
    return head;
}

Node * mergeList( Node *a, Node *b) {
    Node * head;
    Node * c;
    // initial
    if( !a ) return b;
    if( !b ) return a;
    if( a->value < b->value ) {
        c = a;
        a = a->next;
    } else {
        c = b;
        b = b->next;
    }
    head = c;
    // loop
    while( a && b ) {
        if( a->value < b->value ) {
            c->next = a;
            a = a->next;
        } else {
            c->next = b;
            b = b->next;
        }
        c = c->next;
    }

    // final
    c->next = a ? b : a;
    return head;
}

void showList( Node *a ) {
    while( a ) {
        printf( "%d ", a->value );
        a = a->next;
    }
    printf("\n");
}

void cleanList( Node *a ) {
}

void mergeTest() {
    int num = 10;
    Node *list1 = newList( num );
    Node *list2 = newList( num );
    printf("Before:\n");
    showList( list1 );
    showList( list2 );
    Node *list3 = mergeList( list1, list2 );
    printf("After:\n");
    showList( list3 );
    cleanList( list3 );
}


int main() {

    printf("Hello Jay\n");
    mergeTest();
}

