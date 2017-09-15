#include <slist_node.h>

struct _SList
{
    SListNode *head;
    size_t item_size;
};

typedef struct _SList SList;

// construct an empty list
SList *newSList(size_t item_size);

// modifiers: copy version(default)
void slistPushFront(SList* slist, const void* item_pointer)
void slistPushFront_range(SList* slist,
        const void* begin, size_t length);
void slistInsertAfter(SList*, const void*);
void slistInsertAfter_range(SList*, const void* begin, size_t length);

// modifiers: move version
void slistPushFront_move(SList*, void*)
void slistPushFront_range_move(SList* slist,
        const void* begin, size_t length);
void slistInsertAfter_move(SList*, void*);
void slistInsertAfter_range_move(Slist*, void* begin, size_t length);

struct Object
{
    void* pointer;
    size_t size;
};

Object *newObject(void* pointer, size_t size)
{
    Object *o = (Object*) malloc(sizeof(Object));
    o->size = size;
    o->pointer = malloc(size);
    memcpy(o->pointer, pointer, size);
    return o;
}

Object *newObject_move(void pointer, size_t size)
{
    Object *o = (Object*) malloc(sizeof(Object));
    o->size = size;
    o->pointer = pointer;
    return o;
}

#define newObjectFrom(data) newObject(&data, sizeof(data))
#define newObjectFrom_move(data) newObject_move(&data, sizeof(data))

