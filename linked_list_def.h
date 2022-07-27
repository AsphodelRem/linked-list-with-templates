static inline LIST*
LIST_TYPE(TYPE, createList)()
{
	LIST* newList = (LIST*)malloc(sizeof(LIST));
	newList->head	= NULL;
	newList->tail	= NULL;
	newList->length = 0;
	return newList;
}

static inline NODE*
NODE_TYPE(TYPE, createNode)(TYPE value)
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

	NODE* node = NODE_TYPE(TYPE, createNode)(value);

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

	NODE* node = NODE_TYPE(TYPE, createNode)(value);
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
NODE_TYPE(TYPE, addNodeBefore)(LIST* list, TYPE value, int index)
{
	if (!list)	return LIST_FAILURE;

	if (index == FIRST_INDEX || index >= list->length) 
		return NODE_TYPE(TYPE, push_front)(list, value);

	NODE* newNode	= createNode(value);
	NODE* temp		= (NODE*)malloc(sizeof(NODE));

	temp = LIST_HEAD;
	for (int id = 0; id < index; id++)
		temp = temp->next;

	newNode->next		= temp;
	newNode->prev		= temp->prev->next;
	temp->prev->next	= newNode;
	temp->prev			= newNode;
	list->length++;

	return LIST_SUCCESS;
}

static inline int
NODE_TYPE(TYPE, addNodeAfter)(LIST* list, TYPE value, int index)
{
	if (!list) return LIST_FAILURE;
	if (index >= LAST_INDEX)
		return NODE_TYPE(TYPE, push_back)(list, value);

	NODE* newNode = NODE_TYPE(TYPE, createNode)(value);
	NODE* temp = (NODE*)malloc(sizeof(NODE));

	temp = LIST_HEAD;
	for (int id = 0; id < index; id++)
		temp = temp->next;

	newNode->next = temp->next;
	newNode->prev = temp;
	temp->next->prev = newNode;
	temp->next = newNode;
	list->length++;

	return LIST_SUCCESS;
}

static inline int
NODE_TYPE(TYPE, searchValue)(LIST* list, TYPE value)
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
NODE_TYPE (TYPE, getIndex)(LIST* list, TYPE value) 
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
NODE_TYPE(TYPE, getByIndex)(LIST* list, unsigned int index, void** destination)
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
	return LIST_SUCCESS;
}

static inline int
NODE_TYPE(TYPE, deleteNode)(LIST* list, int index) 
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
NODE_TYPE(TYPE, deleteList)(LIST* list) 
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

#undef TYPE
#undef FORMAT