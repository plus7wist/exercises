#include "slist.h"

slist* new_slist_empty(void)
{
    slist* sl = (slist*) malloc(sizeof(slist));

    sl->head = NULL;
    sl->count = 0;

    return sl;
}

slist* new_slist_fill(size_t n, void* item, size_t item_size)
{
    slist* sl = new_slist_empty();

    while (n--) {
        slist_push_front(sl, item, item_size);
    }

    return sl;
}
