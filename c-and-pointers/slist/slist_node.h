#ifndef _SLIST_NODE_
#define _SLIST_NODE_

#include <slist_common.h>

struct _SListNode
{
    struct _SListNode* next;
    void* data;
};

typedef struct _SListNode SListNode;

SListNode *newSListNode(void* item_pointer, size_t item_size,
        SListNode *next);
SListNode *newSListNode_move(void* item_pointer, SListNode *next);

void deleteSListNode(SListNode *slist);

#endif // _SLIST_NODE_
