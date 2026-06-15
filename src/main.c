#include <stdio.h>
#include "./algorithms/insertion_sort.h"
#include "./algorithms/selection_sort.c"
#include "./algorithms/shell_sort.c"
#include "./algorithms/pancake_sort.c"
#include "./algorithms/tim_sort.c"
#include "./algorithms/counting_sort.c"
#include "./algorithms/bucket_sort.c"
#include "./algorithms/radix_sort.c"
#include "./algorithms/heap_sort.c"
#include "./algorithms/quick_sort.c"
#include "./algorithms/three_way_quick_sort.c"
#include "./algorithms/top_down_merge_sort.c"
#include "./algorithms/bottom_up_merge_sort.c"
#include "./utilities/unordered_list_original_order_restorer.h"
#include "./constants/lists.h"

int main()
{
    printf("Insertion Sort:\n\n");

    execute_insertion_sort_client();

    restore_unordered_list_original_order();

    printf("\n\n");

    printf("Selection Sort:\n\n");

    execute_selection_sort_client();

    restore_unordered_list_original_order();

    printf("\n\n");

    printf("Shell Sort:\n\n");

    execute_shell_sort_client();

    restore_unordered_list_original_order();

    printf("\n\n");

    printf("Pancake Sort:\n\n");

    execute_pancake_sort_client();

    restore_unordered_list_original_order();

    printf("\n\n");

    printf("Tim Sort:\n\n");

    execute_tim_sort_client();

    restore_unordered_list_original_order();

    printf("\n\n");

    printf("Counting Sort:\n\n");

    execute_counting_sort_client();

    restore_unordered_list_original_order();

    printf("\n\n");

    printf("Bucket Sort:\n\n");

    execute_bucket_sort_client();

    restore_unordered_list_original_order();

    printf("\n\n");

    printf("Radix Sort:\n\n");

    execute_radix_sort_client();

    restore_unordered_list_original_order();

    printf("\n\n");

    printf("Heap Sort:\n\n");

    execute_heap_sort_client();

    restore_unordered_list_original_order();

    printf("\n\n");

    printf("Quick Sort:\n\n");

    execute_quick_sort_client();

    restore_unordered_list_original_order();

    printf("\n\n");

    printf("Three Way Quick Sort:\n\n");

    execute_three_way_quick_sort_client();

    restore_unordered_list_original_order();

    printf("\n\n");

    printf("Top Down Merge Sort:\n\n");

    execute_top_down_merge_sort_client();

    restore_unordered_list_original_order();

    printf("\n\n");

    printf("Bottom Up Merge Sort:\n\n");

    execute_bottom_up_merge_sort_client();

    return 0;
}
