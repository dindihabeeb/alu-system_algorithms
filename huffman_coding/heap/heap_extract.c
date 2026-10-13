#include "heap.h"

/**
 * heap_extract - extracts the root value of a Min Binary Heap
 * @heap: a pointer to the heap from which to extract the value
 *
 * Return: a pointer to the data that was stored in the root node of the heap,
 * or NULL if it fails
 */
void *heap_extract(heap_t *heap)
{
	void *min;
	binary_tree_node_t *curr;
	size_t n, n_tmp;
	int bits = 0, i = 0;

	if (!heap || !heap->root)
		return (NULL);
	min = heap->root->data;
	n = n_tmp = heap->size;
	while (n_tmp != 0)
	{
		n_tmp >>= 1;
		bits++;
	}
	curr = heap->root;
	for (i = bits - 2; i >= 0; i--)
	{
		if ((n >> i) & 1)
			curr = curr->right;
		else
			curr = curr->left;
	}
	heap->size--;
	if (heap->size + 1 == 1)
	{
		free(heap->root);
		heap->root = NULL;
		return (min);
	}

	heap->root->data = curr->data;
	if ((n >> 0) & 1)
		curr->parent->right = NULL;
	else
		curr->parent->left = NULL;
	free(curr);
	sift_down(heap);
	return (min);
}

/**
 * sift_down - fixes tree order
 * @heap: a ptr to the heap
 *
 * Return: nothing
 */
void sift_down(heap_t *heap)
{
	binary_tree_node_t *curr = heap->root, *next;
	void *tmp;
	int cmp_res;

	while (curr->left && curr->right)
	{
		tmp = curr->data;
		cmp_res = heap->data_cmp(curr->left->data, curr->right->data);
		if (cmp_res <= 0)
			next = curr->left;
		else
			next = curr->right;

		if (heap->data_cmp(next->data, tmp) < 0)
		{
			curr->data = next->data;
			next->data = tmp;
			curr = next;
		}
		else
			break;
	}
	if (curr->left)
	{
		if (heap->data_cmp(curr->left->data, curr->data) < 0)
		{
			tmp = curr->data;
			curr->data = curr->left->data;
			curr->left->data = tmp;
		}
	}
}
