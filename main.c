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

    l = CLinkList_newList();
    
    for (i=0; i<20; i++) {
        p = (int *)malloc(sizeof(int));
        *p = i;
        
        CLinkList_pushFront(l, p);
    
    }
    cl = l->head;
    
    CLinkList_delete(cl, free);
    
    CLinkList_printLink(l, pF);
    
    CLinkList_sort(l, compar);
    
    CLinkList_printLink(l, pF);
    
    CLinkList_destroyLink(l, free);
    
    return 0;
}
