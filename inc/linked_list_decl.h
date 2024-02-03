#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define LIST_FAILURE	0
#define LIST_SUCCESS	1

#define FIRST_INDEX		0
#define LAST_INDEX		list->length - 1
#define LIST_HEAD		list->head
#define LIST_TAIL		list->tail

#define NODE_FAIL		0
#define NO_ITEM			0
#define ITEM_IN_LIST	1

#define SET_THIS_TYPE	1

#ifdef CHAR_F
	#define FORMAT "%c\n"
	#define TYPE char 
#elif BYTE_INT_F
	#define FORMAT "%c\n"
	#define TYPE int8_t
#elif UBYTE_INT_F
	#define FORMAT "%hu\n"
	#define TYPE uint8_t
#elif SHORT_INT_F
	#define FORMAT "%hd\n"
	#define TYPE int16_t
#elif USHORT_INT_F
	#define FORMAT "%hu\n"
	#define TYPE uint16_t
#elif INT_F
	#define FORMAT "%d\n"
	#define TYPE int32_t 
#elif UINT_F
	#define FORMAT "%u\n"
	#define TYPE uint32_t
#elif LONG_INT_F
	#define FORMAT "%lld\n"
	#define TYPE int64_t
#elif ULONG_INT_F
	#define FORMAT "%llu\n"
	#define TYPE uint64_t
#elif DOUBLE_F
	#define FORMAT "%lf\n"
	#define TYPE double 
#elif FLOAT_F
	#define FORMAT "%f\n"
	#define TYPE float
#elif SIZE_T_F
	#define FORMAT "%u\n"
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

	struct NODE* next_big_mode_;
	struct NODE* prev_big_node_;
} NODE;

typedef struct LIST {
	uint64_t length;
	NODE* head;
	NODE* tail;

	size_t margin_between_big_nodes_;

} LIST;

static inline LIST*
LIST_TYPE(TYPE, create_list)();

static inline NODE*
NODE_TYPE(TYPE, create_node)(TYPE value);

static inline int
NODE_TYPE(TYPE, push_back)(LIST* list, TYPE value);

static inline int
NODE_TYPE(TYPE, push_front)(LIST* list, TYPE value);

static inline int
NODE_TYPE(TYPE, add_node_after)(LIST* list, TYPE value, int index);

static inline int
NODE_TYPE(TYPE, add_node_before)(LIST* list, TYPE value, int index);

static inline unsigned int
NODE_TYPE(TYPE, get_index)(LIST* list, TYPE value);

static inline int
NODE_TYPE(TYPE, find)(LIST* list, TYPE value);

static inline int
NODE_TYPE(TYPE, get_by_index)(LIST* list, unsigned int index, TYPE* destination);

static inline int
NODE_TYPE(TYPE, printNodes)(NODE* node);

static inline int
NODE_TYPE(TYPE, printList)(LIST* list);

static inline int
NODE_TYPE(TYPE, delete_node)(LIST* list, int index);

static inline int
NODE_TYPE(TYPE, delete_list)(LIST* list);
