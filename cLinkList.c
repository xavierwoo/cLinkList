#include <stdio.h>
#include <stdlib.h>
#include "cLinkList.h"


int (*g_cmpFun)(const void *a, const void *b) = NULL;;


#ifdef DEBUG_CLINKLIST
void CLinkList_printLink(struct CLinkList *list, void (*printFun)(const void *data)){
    struct CLink *pL = NULL;
    unsigned int i = 0;
    
    if (list == NULL || list->length == 0) {
        return;
    }
    
    pL = list->head;
    printf("List :\n");
    while (pL != NULL) {
        printf(" NO.%u:\n  ", i++);
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
    nL->list = NULL;
    nL->data = NULL;
    
    return nL;
}

void CLinkList_delete(struct CLink *link, void (*destruction)(void *data)){
    struct CLinkList *l = NULL;
    
    if (link == NULL) return;
    
    l = link->list;
    
    if (l->length == 1) {
        l->head = NULL;
        l->tail = NULL;
    }
    else if (l->head == link) {
        l->head = link->next;
        link->next->previous = NULL;
    }
    else if (l->tail == link) {
        l->tail = link->previous;
        link->previous->next = NULL;
    }
    else {
        link->previous->next = link->next;
        link->next->previous = link->previous;
    }
    
    l->length--;
    
    destruction(link->data);
    free(link);
}

int CLinkList_insert(struct CLink *link, void *data){
    struct CLink *nL = NULL;
    struct CLinkList *l = NULL;
    if (link == NULL) return -1;
    
    nL = newLink();
    
    if (nL == NULL) return -1;
    l = link->list;
    nL->data = data;
    nL->list = l;
    
    if (l->head == link) {
        l->head = nL;
        nL->next = link;
        link->previous = nL;
    }
    else {
        nL->previous = link->previous;
        nL->next = link;
        link->previous->next = nL;
        link->previous = nL;
    }
    l->length++;
    
    return 0;
}

int CLinkList_pushBack(struct CLinkList *list, void *data){
    struct CLink *nL = NULL;
    
    nL = newLink();
    
    if (nL == NULL) return -1;
    
    nL->data = data;
    nL->list = list;
    if (list->length > 0) {
        nL->previous = list->tail;
        list->tail->next = nL;
        list->tail = nL;
    }
    else {
        list->head = nL;
        list->tail = nL;
    }
    list->length++;
    return 0;
}

int CLinkList_pushFront(struct CLinkList *list, void *data){
    struct CLink *nL = NULL;
    
    nL = newLink();
    
    if (nL == NULL) return -1;
    
    nL->data = data;
    nL->list = list;
    if (list->length > 0) {
        nL->next = list->head;
        list->head->previous = nL;
        list->head = nL;
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

//***********************************************************************//
// This function is written for CLinkList_sort                           //
// It uses the global pointer g_cmpFun                                   //
//***********************************************************************//
int cmpForSort(const void *a, const void *b){
    struct CLink **lA = NULL;
    struct CLink **lB = NULL;
    
    lA = (struct CLink**)a;
    lB = (struct CLink**)b;
    
    return g_cmpFun((*lA)->data, (*lB)->data);
}

void CLinkList_sort(struct CLinkList *list, int (*compare)(const void *a, const void *b)){
    struct CLink **array = NULL;
    struct CLink *pL = NULL;
    int i;
    
    if (list == NULL || list->length <= 1) return;
    
    array = (struct CLink **)malloc(list->length * sizeof(struct CLink **));
    
    pL = list->head;
    
    for (i = 0; pL != NULL; i++, pL = pL->next) {
        array[i] = pL;
    }
    
    if (g_cmpFun != NULL) {
        printf("WARNING: The pointer g_cmpFun was occupied some where!\n");
    }
    g_cmpFun = compare;
    qsort(array, list->length, sizeof(struct CLink*), cmpForSort);
    g_cmpFun = NULL;

    pL = array[0];
    
    list->head = pL;
    pL->previous = NULL;
    
    for (i = 1; i < list->length; i++) {
        pL = array[i];
        
        pL->previous = array[i-1];
        array[i-1]->next = pL;
    }
    
    pL->next = NULL;
    list->tail = pL;
    
    free(array);
}