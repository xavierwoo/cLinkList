#include <stdlib.h>
#include "cLinkList.h"

void main(){

    struct CLinkList *l=NULL;
    
    int *p;
    int i;
    
    l = CLinkList_newList();
    
    for (i=0; i<5; i++) {
        p = (int *)malloc(sizeof(int));
        *p = i;
        
        CLinkList_insertFront(l, p);
    }
}