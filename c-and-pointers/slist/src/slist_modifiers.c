#include "slist.h"

void slist_push_front(slist* sl, void* item, size_t item_size)
{
    slist_node* tmp = sl->head;
    sl->head = (slist_node*) malloc(sizeof(slist_node));
    sl->head->item = item;
    sl->head->item_size = item_size;
    sl->head->next = tmp;
}
