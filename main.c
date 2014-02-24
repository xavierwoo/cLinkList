#include <stdio.h>
#include <stdlib.h>
#include "cLinkList.h"

void pF(void *d){
    printf("%d\n", *(int *)d);
}

int main(int argc, char *argv[]){

    struct CLinkList *l=NULL;
    
    int *p;
    int i;
    
    l = CLinkList_newList();
    
    for (i=0; i<5; i++) {
        p = (int *)malloc(sizeof(int));
        *p = i;
        
        CLinkList_insertFront(l, p);
    }
    
    CLinkList_printLink(l, pF);
    
    CLinkList_destroyLink(l, free);
    
    return 0;
}
