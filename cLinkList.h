#define DEBUG_CLINKLIST

struct CLink{
	struct CLink *previous;
	struct CLink *next;
	void *data;
};


struct CLinkList{
	struct CLink *head;
	struct CLink *tail;
	unsigned int length;
};

struct CLinkList *CLinkList_newList();

int CLinkList_insertFront(struct CLinkList *list, void *data);

void CLinkList_destroyLink(struct CLinkList *list, void (*destruction)(void *data));

#ifdef DEBUG_CLINKLIST
void CLinkList_printLink(struct CLinkList *list, void (*printFun)(void *data));
#endif
