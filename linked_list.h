/*
* Doubly linked list with c-templates.
* 
* Before including this header you need to define one of macros responsible for using the type.
* This macros:
* CHAR_F		    - char
* BYTE_INT_F	  - byte/int8_t 
* UBYTE_INT_F	  - unsigned int8_t
* SHORT_INT_F	  - short int
* USHORT_INT_F	- unsigned short int
* INT_F			    - int
* UINT_F		    - unsigned int
* DOUBLE_F		  - double
* FLOAT_F		    - float
* LONG_INT_F	  - long long int
* ULONG_INT_F	  - unsigned long long int
* SIZE_T_F		  - size_t
* 
* In case you want to set multiple lists with different types, 
* you need to define two macros: NODE_NAME and LIST_NAME. 
* Set some names to it.
* 
* Example:
* #define CHAR_F	SET_THIS_TYPE
* #define NODE_NAME	CHAR_NODE
* #define LIST_NAME	CHAR_LIST
* 
*/

#include "inc/linked_list_decl.h"
#include "inc/linked_list_def.h"
