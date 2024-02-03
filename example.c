#include <assert.h>

//set list to int values
#define INT_F		SET_THIS_TYPE
#include "linked_list.h"


//set list to long long int values
#define NODE_NAME	LL_INT_NODE
#define LONG_INT_F	SET_THIS_TYPE
#define LIST_NAME	LL_INT_LIST
#include "linked_list.h"


//set list to char values
#define NODE_NAME	CHAR_NODE
#define CHAR_F		SET_THIS_TYPE
#define LIST_NAME	CHAR_LIST
#include "linked_list.h"

int main() {

	int assert_1[3];

	LIST* list = int32_t_create_list();
	int32_t_push_back(list, 4);
	int32_t_push_back(list, 5);
	int32_t_push_back(list, 6);

	int32_t_get_by_index(list, 0, &assert_1[0]);
	int32_t_get_by_index(list, 1, &assert_1[1]);
	int32_t_get_by_index(list, 2, &assert_1[2]);

	assert(assert_1[0] == 4 && assert_1[1] == 5 && assert_1[2] == 6);

	int32_t_printList(list);
	int32_t_delete_list(list);

	//------------------------------------------------------------------------

	LIST* list_ll = int64_t_create_list();
	int64_t_push_back(list_ll, 50);
	int64_t_push_back(list_ll, 60);
	int64_t_add_node_after(list_ll, 55, 0);

	int64_t_printList(list_ll);
	int32_t_delete_list(list_ll);

	//------------------------------------------------------------------------

	LIST* list_c = char_create_list();
	char_push_back(list_c, 'h');
	char_push_back(list_c, ' ');
	char_push_back(list_c, 'u');
	char_push_front(list_c, 'I');
	char_add_node_before(list_c, 'l', 1);
	char_add_node_after(list_c, 'e', 1);
	char_add_node_after(list_c, 'v', 1);
	char_add_node_after(list_c, 'o', 1);
	char_add_node_before(list_c, ' ', 1);
	int index = char_get_index(list_c, 'h');
	char_delete_node(list_c, index);
	
	char_printList(list_c);
	//char_delete_list(list_c);

	return 0;
}