#include "heap.h"

void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (!heap)
		return;

	delete_tree(heap->root, free_data);
	free(heap);
}

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
