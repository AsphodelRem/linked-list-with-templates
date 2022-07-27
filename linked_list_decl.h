/*
Simple doubly list with c-templates.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define SET_LIST_TYPE

#define LIST_FAILURE	0
#define LIST_SUCCESS	1

#define LAST_INDEX		list->length - 1
#define FIRST_INDEX		0
#define LIST_HEAD		list->head
#define LIST_TAIL		list->tail

#define NODE_FAIL		0
#define NO_ITEM			0
#define ITEM_IN_LIST	1

#ifdef CHAR_F
#define FORMAT "%c "
#define TYPE char 

#elif INT_F
#define FORMAT "%d "
#define TYPE int32_t 

#elif UINT_F
#define FORMAT "%u "
#define TYPE uint32_t

#elif SHORT_INT_F
#define FORMAT "%h "
#define TYPE int16_t

#elif USHORT_INT_F
#define FORMAT "%h "
#define TYPE uint16_t

#elif DOUBLE_F
#define FORMAT "%lf "
#define TYPE double 

#elif FLOAT_F
#define FORMAT "%lf "
#define TYPE float

#elif LL_INT
#define FORMAT "%ll "
#define TYPE int64_t

#elif ULL_INT
#define FORMAT "%llu "
#define TYPE uint64_t

#elif SIZE_T_F
#define FORMAT "%u "
#define TYPE size_t
#endif


#ifndef LIST_TYPE
#define LIST_TEMP(type, function_name) type##_##function_name
#define LIST_TYPE(type, function_name) LIST_TEMP(type, function_name)
#endif

#ifndef NODE_TYPE
#define NODE_TEMP(type, function_name) type##_##function_name
#define NODE_TYPE(type, function_name) NODE_TEMP(type, function_name)
#endif

#define LIST LIST_NAME
#define NODE NODE_NAME

typedef struct NODE {
	struct NODE* next;
	struct NODE* prev;
	TYPE value;
} NODE;

typedef struct LIST {
	TYPE length;
	NODE* head;
	NODE* tail;
} LIST;

static inline LIST*
LIST_TYPE(TYPE, createList)();

static inline NODE*
NODE_TYPE(TYPE, createNode)(TYPE value);

static inline int
NODE_TYPE(TYPE, push_back)(LIST* list, TYPE value);

static inline int
NODE_TYPE(TYPE, push_front)(LIST* list, TYPE value);

static inline int
NODE_TYPE(TYPE, addNodeAfter)(LIST* list, TYPE value, int index);

static inline int
NODE_TYPE(TYPE, addNodeBefore)(LIST* list, TYPE value, int index);

static inline unsigned int
NODE_TYPE(TYPE, getIndex)(LIST* list, TYPE value);

static inline int
NODE_TYPE(TYPE, searchValue)(LIST* list, TYPE value);

static inline int
NODE_TYPE(TYPE, getByIndex)(LIST* list, unsigned int index, void** destination);

static inline int
NODE_TYPE(TYPE, printNodes)(NODE* node);

static inline int
NODE_TYPE(TYPE, printList)(LIST* list);

static inline int
NODE_TYPE(TYPE, deleteNode)(LIST* list, int index);

static inline int
NODE_TYPE(TYPE, deleteList)(LIST* list);
