#include <stdio.h>
#include "AVL.h"

int main () {
    Node * root = create () ;

    for (int i = 0; i < 8; i ++) {
        root = insert ( root , i *10) ;
        printf (" Height : %d\n", height ( root ) ) ;
    }

    Node * node = search ( root , 70) ;
    if ( node == NULL ) {
    printf (" Node not found \n") ;
    } else {
    printf (" Node : %d\n", node -> key ) ;
    }
    printf (" Traversal : ") ;
    traversal ( root ) ;
    printf ("\n") ;
    for (int i = 0; i < 8; i ++) {
    root = deleteNode ( root , i *10) ;
    printf (" Height : %d\n", height ( root ) ) ;
    }
    return 0;
}
