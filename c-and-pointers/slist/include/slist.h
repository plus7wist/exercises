#ifndef _SLIST_NODE_
#define _SLIST_NODE_

#include <stdlib.h>

typedef struct slist_node
{
    void* item;
    size_t item_size;
    struct slist_node* next;
} slist_node;

typedef struct slist
{
    slist_node* head;
    size_t count;
} slist;

// construct
slist* new_slist_empty(void);
slist* new_slist_fill(size_t n, void* item, size_t item_size);

// clone
slist* slist_clone(const slist*);
slist* slist_clone_range(const slist*, slist_node* start, size_t n);

// member functions
void slist_push_front(slist*, void* item, size_t item_size);

#endif
