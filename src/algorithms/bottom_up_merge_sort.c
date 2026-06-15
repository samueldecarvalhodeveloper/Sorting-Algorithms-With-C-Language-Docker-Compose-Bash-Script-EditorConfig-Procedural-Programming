#include <stdlib.h>
#include "../utilities/list_printer.h"
#include "../constants/lists.h"

void bottom_up_copy_sorted_half_lists_to_list_with_all_values(const int lowest_value_index, int list_to_be_sorted[],
                                                              int first_half_list_to_be_sorted[],
                                                              int second_half_list_to_be_sorted[],
                                                              const int first_half_list_to_be_sorted_size,
                                                              const int second_half_list_to_be_sorted_size)
{
    int current_first_half_list_to_be_sorted_index = 0;
    int current_second_half_list_to_be_sorted_index = 0;
    int current_middle_value_index = lowest_value_index;

    while (current_first_half_list_to_be_sorted_index < first_half_list_to_be_sorted_size &&
           current_second_half_list_to_be_sorted_index < second_half_list_to_be_sorted_size)
    {
        if (first_half_list_to_be_sorted[current_first_half_list_to_be_sorted_index] <= second_half_list_to_be_sorted[current_second_half_list_to_be_sorted_index])
        {
            list_to_be_sorted[current_middle_value_index] = first_half_list_to_be_sorted[current_first_half_list_to_be_sorted_index];
            current_first_half_list_to_be_sorted_index++;
        }
        else
        {
            list_to_be_sorted[current_middle_value_index] = second_half_list_to_be_sorted[current_second_half_list_to_be_sorted_index];
            current_second_half_list_to_be_sorted_index++;
        }
        current_middle_value_index++;
    }

    while (current_first_half_list_to_be_sorted_index < first_half_list_to_be_sorted_size)
    {
        list_to_be_sorted[current_middle_value_index] = first_half_list_to_be_sorted[current_first_half_list_to_be_sorted_index];
        current_first_half_list_to_be_sorted_index++;
        current_middle_value_index++;
    }

    while (current_second_half_list_to_be_sorted_index < second_half_list_to_be_sorted_size)
    {
        list_to_be_sorted[current_middle_value_index] = second_half_list_to_be_sorted[current_second_half_list_to_be_sorted_index];
        current_second_half_list_to_be_sorted_index++;
        current_middle_value_index++;
    }
}

void bottom_up_merge_half_sorted_lists(int list_to_be_sorted[], const int lowest_value_index,
                                       const int middle_value_index, const int highest_value_index)
{
    const int first_half_list_to_be_sorted_size = middle_value_index - lowest_value_index + 1;
    const int second_half_list_to_be_sorted_size = highest_value_index - middle_value_index;

    int *first_half_list_to_be_sorted = (int *)malloc(first_half_list_to_be_sorted_size * sizeof(int));
    int *second_half_list_to_be_sorted = (int *)malloc(second_half_list_to_be_sorted_size * sizeof(int));

    for (int i = 0; i < first_half_list_to_be_sorted_size; i++)
        first_half_list_to_be_sorted[i] = list_to_be_sorted[lowest_value_index + i];

    for (int j = 0; j < second_half_list_to_be_sorted_size; j++)
        second_half_list_to_be_sorted[j] = list_to_be_sorted[middle_value_index + 1 + j];

    bottom_up_copy_sorted_half_lists_to_list_with_all_values(lowest_value_index, list_to_be_sorted,
                                                             first_half_list_to_be_sorted, second_half_list_to_be_sorted,
                                                             first_half_list_to_be_sorted_size, second_half_list_to_be_sorted_size);

    free(first_half_list_to_be_sorted);
    free(second_half_list_to_be_sorted);
}

void sort_with_bottom_up_merge_sort(int list_to_be_sorted[], const int list_size)
{
    for (int subarray_size = 1; subarray_size < list_size; subarray_size *= 2)
    {

        for (int left = 0; left < list_size - subarray_size; left += 2 * subarray_size)
        {
            int middle = left + subarray_size - 1;
            int right = (left + 2 * subarray_size - 1 < list_size) ? (left + 2 * subarray_size - 1) : (list_size - 1);

                bottom_up_merge_half_sorted_lists(list_to_be_sorted, left, middle, right);
        }
    }
}

void execute_bottom_up_merge_sort_client()
{
    sort_with_bottom_up_merge_sort(UNORDERED_LIST, LIST_SIZE);

    print_list(UNORDERED_LIST, LIST_SIZE);
}
