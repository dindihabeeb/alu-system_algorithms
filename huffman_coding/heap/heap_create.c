#include "heap.h"
#include "../huffman.h"

/**
 * heap_create - function that creates a Heap data structure
 * @data_cmp: pointer to a comparison function
 *
 * Return: a pointer to the created heap_t structure, or NULL if it fails
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *new_heap = NULL;

	if (!data_cmp)
		return (NULL);

	new_heap = malloc(sizeof(heap_t));
	if (!new_heap)
		return (NULL);

	new_heap->data_cmp = data_cmp;
	new_heap->size = 0;
	new_heap->root = NULL;

	return (new_heap);
}
