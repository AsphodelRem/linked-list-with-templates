static inline LIST*
LIST_TYPE(TYPE, create_list)()
{
	LIST* newList = (LIST*)malloc(sizeof(LIST));
	newList->head	= NULL;
	newList->tail	= NULL;
	newList->length = 0;
	return newList;
}

static inline NODE*
NODE_TYPE(TYPE, create_node)(TYPE value)
{
	NODE* newNode	= (NODE*)malloc(sizeof(NODE));
	newNode->next	= NULL;
	newNode->prev	= NULL;
	newNode->value	= value;

	return newNode;
}

static inline int
NODE_TYPE(TYPE, push_back)(LIST* list, TYPE value)
{
	if (!list) return LIST_FAILURE;

	NODE* node = NODE_TYPE(TYPE, create_node)(value);

	if (!list->length)
	{
		list->head = node;
		list->tail = node;
		list->length++;
		return LIST_SUCCESS;
	}

	node->next = NULL;
	node->prev = list->tail;
	list->tail->next = node;
	list->tail = node;
	list->length++;

	return LIST_SUCCESS;
}

static inline int
NODE_TYPE (TYPE, push_front)(LIST* list, TYPE value)
{
	if (!list)	 return LIST_FAILURE;

	NODE* node = NODE_TYPE(TYPE, create_node)(value);
	if (!list->length) 
	{
		list->head		= node;
		list->tail		= node;
		list->length++;
		return LIST_SUCCESS;
	}
	node->prev			= NULL;
	list->head->prev	= node;
	node->next			= list->head;
	list->head			= node;
	list->length++;

	return LIST_SUCCESS;
}

static inline int
NODE_TYPE(TYPE, add_node_before)(LIST* list, TYPE value, int index)
{
	if (!list)	return LIST_FAILURE;

	if (index == FIRST_INDEX || index >= list->length) 
		return NODE_TYPE(TYPE, push_front)(list, value);

	NODE* newNode	= NODE_TYPE(TYPE, create_node)(value);
	NODE* iter		= (NODE*)malloc(sizeof(NODE));

	iter = LIST_HEAD;
	for (int id = 0; id < index; id++)
		iter = iter->next;

	newNode->next		= iter;
	newNode->prev		= iter->prev;
	iter->prev->next	= newNode;
	iter->prev			= newNode;
	list->length++;

	return LIST_SUCCESS;
}

static inline int
NODE_TYPE(TYPE, add_node_after)(LIST* list, TYPE value, int index)
{
	if (!list) return LIST_FAILURE;
	if (index >= LAST_INDEX)
		return NODE_TYPE(TYPE, push_back)(list, value);

	NODE* newNode = NODE_TYPE(TYPE, create_node)(value);
	NODE* iter = (NODE*)malloc(sizeof(NODE));

	iter = LIST_HEAD;
	for (int id = 0; id < index; id++)
		iter = iter->next;

	newNode->next		= iter->next;
	newNode->prev		= iter;
	iter->next->prev	= newNode;
	iter->next			= newNode;
	list->length++;

	return LIST_SUCCESS;
}

static inline int
NODE_TYPE(TYPE, find)(LIST* list, TYPE value)
{
	if (!list) return LIST_FAILURE;

	NODE* iter = LIST_HEAD;
	for (int id = LIST_HEAD; id <= LAST_INDEX; id++)
	{
		if (iter->value == value) return ITEM_IN_LIST;
		iter = iter->next;
	}

	return NO_ITEM;
}

static inline unsigned int
NODE_TYPE (TYPE, get_index)(LIST* list, TYPE value)
{
	if (!list)   return LIST_FAILURE;

	NODE* temp = LIST_HEAD;
	for (unsigned int id = FIRST_INDEX; id <= LAST_INDEX; id++)
	{
		if (temp->value == value) return id;
		temp = temp->next;
	}

	return NO_ITEM;
}

static inline int
NODE_TYPE(TYPE, get_by_index)(LIST* list, unsigned int index, TYPE* destination)
{
	if (!list || index > list->length) return LIST_FAILURE;

	int middle = list->length / 2;
	if (index > middle)
	{
		NODE* iter = LIST_TAIL;
		for (int id = LAST_INDEX; id >= FIRST_INDEX; id--)
		{
			if (id == index)
			{
				*destination = iter->value;
				return LIST_SUCCESS;
			}
			iter = iter->prev;
		}
	}
	else
	{
		NODE* iter = LIST_HEAD;
		for (int id = FIRST_INDEX; id <= LAST_INDEX; id++)
		{
			if (id == index)
			{
				*destination = iter->value;
				return LIST_SUCCESS;
			}
			iter = iter->next;
		}
	}

	return NO_ITEM;
}

static inline int
NODE_TYPE(TYPE, printNodes)(NODE* node) 
{
	if (!node) return NODE_FAIL;

	while (node) {
		printf(FORMAT, node->value);
		node = node->next;
	}
	printf("\n");
	
	return LIST_SUCCESS;
}

static inline int
NODE_TYPE(TYPE, printList)(LIST* list)
{
	if (!list) return LIST_FAILURE;

	NODE* iter = (NODE*)malloc(sizeof(NODE));

	iter = LIST_HEAD;
	while (iter) {
		printf(FORMAT, (TYPE)iter->value);
		iter = iter->next;
	}
	printf("\n");

	return LIST_SUCCESS;
}

static inline int
NODE_TYPE(TYPE, delete_node)(LIST* list, int index)
{
	if (list->length == 0 || index > list->length || !list)	
		return LIST_FAILURE;

	NODE* iter	= (NODE*)malloc(sizeof(NODE));
	iter		= list->head;

	if (index == FIRST_INDEX) 
	{
		iter->next->prev	= NULL;
		list->head			= iter->next;
		list->length--;
		free(iter);
		return LIST_SUCCESS;
	}

	if (index == LAST_INDEX) 
	{
		iter				= list->tail;
		iter->prev->next	= NULL;
		list->tail			= iter->prev;
		list->length--;
		free(iter);
		return LIST_SUCCESS;
	}

	for (int id = 0; id < index; id++)
		iter = iter->next;

	iter->prev->next		= iter->next;
	iter->next->prev		= iter->prev;
	list->length--;
	free(iter);

	return LIST_SUCCESS;
}

static inline int
NODE_TYPE(TYPE, delete_list)(LIST* list)
{
	if (!list) return LIST_FAILURE;

	NODE* current = LIST_HEAD;
	while (current != NULL) {
		NODE* next = current->next;
		free(current);
		current = next;
	}
	free(list);

	return LIST_SUCCESS;
}

#undef	TYPE
#undef	FORMAT 
#undef	LIST_NAME
#undef	NODE_NAME

#ifdef	CHAR_F
#undef	CHAR_F
#elif	BYTE_INT_F
#undef	BYTE_INT_F
#elif	UBYTE_INT_F
#undef	BYTE_INT_F
#elif	INT_F
#undef	INT_F
#elif	UINT_F
#undef	UINT_F
#elif	SHORT_INT_F
#undef	SHORT_INT_F
#elif	USHORT_INT_F
#undef	USHORT_INT_F
#elif	DOUBLE_F
#undef	DOUBLE_F
#elif	FLOAT_F
#undef	FLOAT_F
#elif	LONG_INT_F
#undef	LONG_INT_F
#elif	ULONG_INT_F
#undef	ULONG_INT_F
#elif	SIZE_T_F
#undef	SIZE_T_F
#endif
