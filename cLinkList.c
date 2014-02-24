#include <stdio.h>
#include <stdlib.h>
#include "cLinkList.h"


#ifdef DEBUG_CLINKLIST
void CLinkList_printLink(struct CLinkList *list, void (*printFun)(void *data)){
    struct CLink *pL = NULL;
    unsigned int i = 0;
    
    if (list == NULL || list->length == 0) {
        return;
    }
    
    pL = list->head;
    
    while (pL != NULL) {
        printf("NO.%u:\n ", i++);
        printFun(pL->data);
        printf("\n");
        pL = pL->next;
    }
    
}
#endif

struct CLinkList *CLinkList_newList(){
    struct CLinkList *newList = NULL;
    
    newList = (struct CLinkList*)malloc(sizeof(struct CLinkList));
    
    newList->head = NULL;
    newList->tail = NULL;
    newList->length = 0;
    
    return newList;
}

struct CLink *newLink(){
    struct CLink *nL = NULL;
    
    nL = (struct CLink*)malloc(sizeof(struct CLink));
    
    if (nL == NULL) return NULL;
    
    nL->previous = NULL;
    nL->next = NULL;
    nL->data = NULL;
    
    return nL;
}

int CLinkList_insertFront(struct CLinkList *list, void *data){
    struct CLink *nL = NULL;
    struct CLink *pL = NULL;
    
    nL = newLink();
    
    if (nL == NULL) return -1;
    
    nL->data = data;
    
    if (list->length > 0) {
        nL->next = list->head;
        pL = list->head;
        list->head = nL;
        pL->previous = nL;
    }
    else {
        list->head = nL;
        list->tail = nL;
    }
    list->length++;
    return 0;
}

void CLinkList_destroyLink(struct CLinkList *list, void (*destruction)(void *data)){
    struct CLink *pL = NULL;
    struct CLink *pNL = NULL;
    pL = list->head;
    
    while (pL != NULL) {
        destruction(pL->data);
        
        pNL = pL->next;
        free(pL);
        pL = pNL;
    }
    free(list);
}