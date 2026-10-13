#include "heap.h"

/**
 * heap_delete - deletes a heap
 * @heap: ptr to heap to be freed
 * @free_data: func ptr to func thats to be called on data memeber of nodes
 *
 * Return: nothing
 */
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (!heap)
		return;

	delete_tree(heap->root, free_data);
	free(heap);
}

/**
 * delete_tree - deletes a tree
 * @root: ptr to root of tree
 * @free_data: ptr to func to call on the data member of the root
 *
 * Return: nothing
 */
void delete_tree(binary_tree_node_t *root, void (*free_data)(void *))
{
	if (!root)
		return;

	delete_tree(root->left, free_data);
	delete_tree(root->right, free_data);

	if (free_data)
		free_data(root->data);
	free(root);
}
