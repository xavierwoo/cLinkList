

struct CLinkList{
	struct CLink *head;
	struct CLink *tail;
	unsigned int length;
};

struct CLinkList *CLinkList_newList();

int CLinkList_insertFront(struct CLinkList *list, void *data);