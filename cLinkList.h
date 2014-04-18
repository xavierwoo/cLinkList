#ifndef cLinkList_h
#define cLinkList_h

struct CLink{
	struct CLink *previous;
	struct CLink *next;
	struct CLinkList *list;
	void *data;
};


struct CLinkList{
	struct CLink *head;
	struct CLink *tail;
	unsigned int length;
};

struct CLinkList *CLinkList_newList();



int CLinkList_pushFront(struct CLinkList *list, void *data);
int CLinkList_pushBack(struct CLinkList *list, void *data);
int CLinkList_insert(struct CLink *link, void *data);

//send NULL to the 2nd parameter, if you do not want the API to manage your own data.
//But be careful doing so, for it may cause memory leaks.
void CLinkList_delete(struct CLink *link, void (*destruction)(void *data));
void CLinkList_destroyLink(struct CLinkList *list, void (*destruction)(void *data));


void CLinkList_sort(struct CLinkList *list, int (*compare)(const void *a, const void *b));

//return the pointer to the ith element of the list
//return NULL if i is larger than the list size
void *CLinkList_at(struct CLinkList *list, int i);

void CLinkList_printLink(struct CLinkList *list, void (*printFun)(const void *data));

#endif