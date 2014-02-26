#include <stdio.h>
#include <stdlib.h>
#include "cLinkList.h"

void pF(void *d){
    printf("%d\n", *(int *)d);
}

int main(int argc, char *argv[]){

    struct CLinkList *l=NULL;
    struct CLink *cl = NULL;
    int *p;
    int i;

    l = CLinkList_newList();
    
    for (i=0; i<5; i++) {
        p = (int *)malloc(sizeof(int));
        *p = i;
        
        CLinkList_pushFront(l, p);
    
    }
    cl = l->head;
    
    CLinkList_delete(cl, free);
    
    CLinkList_printLink(l, pF);
    
    CLinkList_destroyLink(l, free);
    
    return 0;
}
