#include "../utilities/list_printer.h"
#include "../constants/lists.h"

void heapify_subtree(int list_to_be_sorted[], const int list_size, const int current_value_index)
{
    const int left_child_index = 2 * current_value_index + 1;
    const int right_child_index = 2 * current_value_index + 2;
    int largest_index = current_value_index;

    if (left_child_index < list_size && list_to_be_sorted[left_child_index] > list_to_be_sorted[largest_index])
        largest_index = left_child_index;

    if (right_child_index < list_size && list_to_be_sorted[right_child_index] > list_to_be_sorted[largest_index])
        largest_index = right_child_index;

    if (largest_index != current_value_index)
    {
        const int item_to_be_swapped = list_to_be_sorted[current_value_index];

        list_to_be_sorted[current_value_index] = list_to_be_sorted[largest_index];

        list_to_be_sorted[largest_index] = item_to_be_swapped;

        heapify_subtree(list_to_be_sorted, list_size, largest_index);
    }
}

void sort_with_heap_sort(int list_to_be_sorted[], const int list_size)
{
    for (int current_value_index = list_size / 2 - 1; current_value_index >= 0; current_value_index--)
        heapify_subtree(list_to_be_sorted, list_size, current_value_index);

    for (int heap_size = list_size - 1; heap_size > 0; heap_size--)
    {
        const int item_to_be_swapped = list_to_be_sorted[0];

        list_to_be_sorted[0] = list_to_be_sorted[heap_size];

        list_to_be_sorted[heap_size] = item_to_be_swapped;

        heapify_subtree(list_to_be_sorted, heap_size, 0);
    }
}

void execute_heap_sort_client()
{
    sort_with_heap_sort(UNORDERED_LIST, LIST_SIZE);

    print_list(UNORDERED_LIST, LIST_SIZE);
}
