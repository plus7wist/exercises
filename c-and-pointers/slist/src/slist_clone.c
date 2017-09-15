#include "slist.h"

slist* slist_clone(const slist* sl)
{
    slist* new_sl = new_slist_empty();
    slist_node* node = sl->head;

    for (; node != NULL; node = node->next) {
        slist_push_front(new_sl, node->item, node->item_size);
    }

    return new_sl;
}

slist* slist_clone_range(const slist* sl, slist_node* start, size_t n)
{
    slist* new_sl = new_slist_empty();
    size_t i = 0;

    while ( start != NULL && i < n) {
        slist_push_front(new_sl, start->item, start->item_size);
        
        ++i;
        start = start->next;
    }

    return new_sl;
}
