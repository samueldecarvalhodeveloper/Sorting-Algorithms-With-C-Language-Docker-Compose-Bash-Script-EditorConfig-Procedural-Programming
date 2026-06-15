#include <stdlib.h>
#include "../utilities/list_printer.h"
#include "../constants/lists.h"

int get_from_list_highest_value(int list[], const int list_size)
{
    int list_highest_value = list[0];

    for (int current_value_index = 1; current_value_index < list_size; current_value_index++)
        if (list[current_value_index] > list_highest_value)
            list_highest_value = list[current_value_index];

    return list_highest_value;
}

void count_occurrences_of_digits(int list_of_digits[], const int current_sorting_digit, int list_to_be_sorted[],
                                 const int list_size)
{
    for (int current_value_index = 0; current_value_index < list_size; current_value_index++)
    {
        const int current_value_digit = list_to_be_sorted[current_value_index] / current_sorting_digit % 10;

        list_of_digits[current_value_digit]++;
    }
}

void store_cumulative_position_into_list_of_digits(int list_of_digits[])
{
    for (int current_value_index = 1; current_value_index < 10; current_value_index++)
        list_of_digits[current_value_index] += list_of_digits[current_value_index - 1];
}

void populate_list_of_sorted_value_with_sorted_values(int *list_of_sorted_value, int list_of_digits[],
                                                      const int current_sorting_digit, int list_to_be_sorted[],
                                                      const int list_size)
{
    for (int current_value_index = list_size - 1; current_value_index >= 0; current_value_index--)
    {
        const int current_value_digit = list_to_be_sorted[current_value_index] / current_sorting_digit % 10;

        list_of_sorted_value[list_of_digits[current_value_digit] - 1] = list_to_be_sorted[current_value_index];

        list_of_digits[current_value_digit]--;
    }
}

void copy_sorted_values_into_list_to_be_sorted(const int *list_of_sorted_value, int list_to_be_sorted[],
                                               const int list_size)
{
    for (int current_value_index = 0; current_value_index < list_size; current_value_index++)
        list_to_be_sorted[current_value_index] =
            list_of_sorted_value[current_value_index];
}

void counting_sort(int list_to_be_sorted[], const int list_size, const int current_sorting_digit)
{
    int *list_of_sorted_value = malloc(list_size * sizeof(int));
    int list_of_digits[10] = {0};

    count_occurrences_of_digits(list_of_digits, current_sorting_digit, list_to_be_sorted, list_size);

    store_cumulative_position_into_list_of_digits(list_of_digits);

    populate_list_of_sorted_value_with_sorted_values(list_of_sorted_value, list_of_digits, current_sorting_digit,
                                                     list_to_be_sorted, list_size);

    copy_sorted_values_into_list_to_be_sorted(list_of_sorted_value, list_to_be_sorted, list_size);

    free(list_of_sorted_value);
}

void sort_with_radix_sort(int list_to_be_sorted[], const int list_size)
{
    const int list_highest_value = get_from_list_highest_value(list_to_be_sorted, list_size);

    for (int current_sorting_digit = 1; list_highest_value / current_sorting_digit > 0; current_sorting_digit *=
                                                                                        10)
        counting_sort(list_to_be_sorted, list_size, current_sorting_digit);
}

void execute_radix_sort_client()
{
    sort_with_radix_sort(UNORDERED_LIST, LIST_SIZE);

    print_list(UNORDERED_LIST, LIST_SIZE);
}
