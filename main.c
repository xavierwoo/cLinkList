#include <stdio.h>
#include <stdlib.h>
#include "cLinkList.h"

void pF(const void *d){
    printf("%d\n", *(int *)d);
}

int compar (const void *a ,const void *b)
{

    int *aa=(int * ) a,*bb = (int * )b;
    if( * aa >* bb)return 1;
    else if( * aa == * bb) return 0;
    else return -1;
    
}

int main(int argc, char *argv[]){

    struct CLinkList *l=NULL;
    struct CLink *cl = NULL;
    int *p;
    int i;
    
    //Create a link list
    l = CLinkList_newList();
    
    for (i=0; i<20; i++) {
        p = (int *)malloc(sizeof(int));
        *p = i;
        
        //Add an element to the list.
        CLinkList_pushFront(l, p);
    
    }
    cl = l->head;
    
    //Delete an element.
    CLinkList_delete(cl, free);
    
    //Print the list to the console.
    CLinkList_printLink(l, pF);
    
    //Sort the list, "compar" is a compare function like in the qsort.
    CLinkList_sort(l, compar);
    
    CLinkList_printLink(l, pF);
    
    //The list should be destroyed after use, otherwise there will be memory leaks.
    CLinkList_destroyLink(l, free);
    
    return 0;
}
