#ifndef UNORDERED_LIST_ORIGINAL_ORDER_RESTORER_HEADER
#define UNORDERED_LIST_ORIGINAL_ORDER_RESTORER_HEADER

#include <string.h>
#include "../constants/lists.h"

void restore_unordered_list_original_order()
{
    memcpy(UNORDERED_LIST, UNORDERED_LIST_BACKUP, LIST_SIZE * sizeof(int));
}

#endif
