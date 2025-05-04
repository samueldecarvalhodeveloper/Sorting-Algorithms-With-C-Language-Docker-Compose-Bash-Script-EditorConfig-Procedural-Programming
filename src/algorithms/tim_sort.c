#include <stdlib.h>
#include "../utilities/list_printer.h"
#include "../constants/lists.h"

void merge_back_half_lists(int list_to_be_sorted[], int first_half_list_to_be_sorted[],
                           int second_half_list_to_be_sorted[], const int first_half_list_to_be_sorted_size,
                           const int second_half_list_to_be_sorted_size,
                           const int list_starting_index)
{
    int current_list_starting_index = list_starting_index;
    int first_half_list_to_be_sorted_current_index = 0;
    int second_half_list_to_be_sorted_current_index = 0;

    while (first_half_list_to_be_sorted_current_index < first_half_list_to_be_sorted_size &&
           second_half_list_to_be_sorted_current_index < second_half_list_to_be_sorted_size)
        if (first_half_list_to_be_sorted[first_half_list_to_be_sorted_current_index] <= second_half_list_to_be_sorted[second_half_list_to_be_sorted_current_index])
            list_to_be_sorted[current_list_starting_index++] = first_half_list_to_be_sorted[first_half_list_to_be_sorted_current_index++];
        else
            list_to_be_sorted[current_list_starting_index++] = second_half_list_to_be_sorted[second_half_list_to_be_sorted_current_index++];

    while (first_half_list_to_be_sorted_current_index < first_half_list_to_be_sorted_size)
        list_to_be_sorted[current_list_starting_index++] = first_half_list_to_be_sorted[first_half_list_to_be_sorted_current_index++];
    while (second_half_list_to_be_sorted_current_index < second_half_list_to_be_sorted_size)
        list_to_be_sorted[current_list_starting_index++] = second_half_list_to_be_sorted[second_half_list_to_be_sorted_current_index++];
}

void copy_data_to_half_lists(int list_to_be_sorted[], int first_half_list_to_be_sorted[],
                             int second_half_list_to_be_sorted[], const int list_starting_index,
                             const int list_middle_index, const int first_half_list_to_be_sorted_size,
                             const int second_half_list_to_be_sorted_size)
{
    for (int i = 0; i < first_half_list_to_be_sorted_size; i++)
        first_half_list_to_be_sorted[i] = list_to_be_sorted[list_starting_index + i];

    for (int i = 0; i < second_half_list_to_be_sorted_size; i++)
        second_half_list_to_be_sorted[i] = list_to_be_sorted[list_middle_index + 1 + i];
}

void merge_sorted_sublist(int list_to_be_sorted[], const int list_starting_index, const int list_middle_index,
                          const int list_ending_index)
{
    const int first_half_list_to_be_sorted_size = list_middle_index - list_starting_index + 1;
    const int second_half_list_to_be_sorted_size = list_ending_index - list_middle_index;
    int *first_half_list_to_be_sorted = malloc(first_half_list_to_be_sorted_size * sizeof(int));
    int *second_half_list_to_be_sorted = malloc(second_half_list_to_be_sorted_size * sizeof(int));

    copy_data_to_half_lists(list_to_be_sorted, first_half_list_to_be_sorted, second_half_list_to_be_sorted,
                            list_starting_index, list_middle_index, first_half_list_to_be_sorted_size,
                            second_half_list_to_be_sorted_size);

    merge_back_half_lists(list_to_be_sorted, first_half_list_to_be_sorted, second_half_list_to_be_sorted,
                          first_half_list_to_be_sorted_size, second_half_list_to_be_sorted_size, list_starting_index);

    free(first_half_list_to_be_sorted);
    free(second_half_list_to_be_sorted);
}

void merge_sorted_list_chunks(int list_to_be_sorted[], const int list_size)
{
    for (int current_list_size = NUMBER_OF_ITEM_IN_A_LIST_CHUNK; current_list_size < list_size; current_list_size *= 2)
    {
        for (int current_list_starting_index = 0; current_list_starting_index < list_size; current_list_starting_index += 2 * current_list_size)
        {
            const int list_middle_index = current_list_starting_index + current_list_size - 1;
            const int list_ending_index = current_list_starting_index + 2 * current_list_size - 1 < list_size - 1
                                              ? current_list_starting_index + 2 * current_list_size - 1
                                              : list_size - 1;

            if (list_middle_index < list_ending_index)
                merge_sorted_sublist(
                    list_to_be_sorted, current_list_starting_index, list_middle_index, list_ending_index);
        }
    }
}

void position_value_on_its_correct_position_on_list(int list_to_be_sorted[], const int current_value,
                                                    const int current_value_index, const int list_starting_index)
{
    int value_current_index = current_value_index - 1;

    while (value_current_index >= list_starting_index && list_to_be_sorted[value_current_index] > current_value)
    {
        list_to_be_sorted[value_current_index + 1] = list_to_be_sorted[value_current_index];

        value_current_index--;
    }

    list_to_be_sorted[value_current_index + 1] = current_value;
}

void perform_insertion_sort_on_sublist(int list_to_be_sorted[], const int list_starting_index,
                                       const int list_ending_index)
{
    for (int current_value_index = list_starting_index + 1; current_value_index <= list_ending_index; current_value_index++)
    {
        const int current_value = list_to_be_sorted[current_value_index];

        position_value_on_its_correct_position_on_list(list_to_be_sorted, current_value, current_value_index,
                                                       list_starting_index);
    }
}

void sort_list_chunks(int list_to_be_sorted[], const int list_size)
{
    for (int current_list_starting_index = 0; current_list_starting_index < list_size; current_list_starting_index +=
                                                                                       NUMBER_OF_ITEM_IN_A_LIST_CHUNK)
    {
        const int list_ending_index = current_list_starting_index + NUMBER_OF_ITEM_IN_A_LIST_CHUNK - 1 < list_size - 1
                                          ? current_list_starting_index + NUMBER_OF_ITEM_IN_A_LIST_CHUNK - 1
                                          : list_size - 1;

        perform_insertion_sort_on_sublist(list_to_be_sorted, current_list_starting_index, list_ending_index);
    }
}

void sort_with_tim_sort(int list_to_be_sorted[], const int list_size)
{
    sort_list_chunks(list_to_be_sorted, list_size);

    merge_sorted_list_chunks(list_to_be_sorted, list_size);
}

void execute_tim_sort_client()
{
    sort_with_tim_sort(UNORDERED_LIST, LIST_SIZE);

    print_list(UNORDERED_LIST, LIST_SIZE);
}
