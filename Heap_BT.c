#include <stdio.h>
#include <stdlib.h>

void solve();

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // scanf("%d", &t);
    while (t--)
        solve();

    return 0;
}

void max_Heapify(int arr[], int n, int index)   //# This Case index Start With 1 not Zero for Calculation Purpose
{
    // if index is leaf node then return
    if ((2 * index) > n)
        return;
    // find out the min vaule index from the right and left child of the index node
    int max_index = (2 * index == n) ? 2 * index : (arr[2 * index - 1] > arr[2 * index]) ? (2 * index) : (2 * index + 1);
    // Swap the index with min_index if the min_index vaule in bigger than the index
    if (arr[index - 1] < arr[max_index - 1])
    {
        int temp = arr[index - 1];
        arr[index - 1] = arr[max_index - 1];
        arr[max_index - 1] = temp;
    }

    // Calling the max_Heapify function for min_index
    max_Heapify(arr, n, max_index);
    return;
}

void build_Max_Heap(int arr[], int n)
{
    // Try see all the index is satisfy the heap property so run max_Heapify for all element
    for (int i = n; i > 0; i--)
        max_Heapify(arr, n, i);

    return;
}



void min_Heapify(int arr[], int n, int index)   //# This Case index Start With 1 not Zero for Calculation Purpose
{
    // if index is leaf node then return
    if ((2 * index) > n)
        return;
    // find out the min vaule index from the right and left child of the index node
    int min_index = (2 * index == n) ? 2 * index : (arr[2 * index - 1] < arr[2 * index]) ? (2 * index) : (2 * index + 1);
    // Swap the index with min_index if the min_index vaule in bigger than the index
    if (arr[index - 1] > arr[min_index - 1])
    {
        int temp = arr[index - 1];
        arr[index - 1] = arr[min_index - 1];
        arr[min_index - 1] = temp;
    }

    // Calling the max_Heapify function for min_index
    min_Heapify(arr, n, min_index);
    return;
}

void build_Min_Heap(int arr[], int n)
{
    // Try see all the index is satisfy the heap property so run max_Heapify for all element
    for (int i = n; i > 0; i--)
        min_Heapify(arr, n, i);

    return;
}



void solve()
{
    // Take input size of the array and elements
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Conversion of Max Heap
    build_Max_Heap(arr, n); // Max Heap
    // print the Max heap
    printf("Max Heap ::\n\t");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Conversion of Min Heap
    build_Min_Heap(arr , n);
    // Print the Min Heap
    printf("\nMin Heap ::\n\t");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);

    return;
}
