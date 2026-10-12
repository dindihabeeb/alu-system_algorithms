#include "heap.h"

/**
 * heap_insert - inserts a value in a Min Binary Heap
 * @heap: a pointer to the heap in which the node has to be inserted
 * @data: a pointer containing the data to store in the new node
 *
 * Return: a pointer to the created node containing data, or NULL if it fails
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *new_node = NULL, *curr;
	size_t n = 0, tmp = 0;
	int bits = 0;

	if (!heap || !data)
		return (NULL);

	empty_root_check(heap, data, &new_node);
	if (new_node != NULL)
		return (new_node);
	if (!heap->root)
		return (NULL);

	n = tmp = heap->size + 1;
	while (tmp != 0)
	{
		tmp >>= 1;
		bits++;
	}

	curr = heap->root;
	for (int i = bits - 2; i >= 1; i--)
	{
		if ((n >> i) & 1)
			curr = curr->right;
		else
			curr = curr->left;
	}

	new_node = binary_tree_node(curr, data);
	if (!new_node)
		return (NULL);

	if ((n >> 0) & 1)
		curr->right = new_node;
	else
		curr->left = new_node;
	heap->size++;
	return (sift_up(new_node, heap->data_cmp));
}

/**
 * sift_up - sifts a node up to maintain heap property
 * @node: the node in question
 * @data_cmp: pointer to a comparison func, takes 2 void ptrs and returns int
 *
 * Return: pointer to @node;
 */
binary_tree_node_t *sift_up(binary_tree_node_t *node,
			    int (*data_cmp)(void *, void *))
{
	void *tmp;

	if (!node)
		return (NULL);

	while (node->parent
	       && data_cmp(node->data, node->parent->data) < 0)
	{
		tmp = node->parent->data;
		node->parent->data = node->data;
		node->data = tmp;

		node = node->parent;
	}
	return (node);
}

/**
 * empty_root_check - checks if a heap's root is empty
 * @heap: pointer to heap to check
 * @data: ptr to data of new node in case heap's root is empty
 * @new_node: ptr to addr of a new node created by the caller
 *
 * Return: nada
 */

void empty_root_check(heap_t *heap, void *data,
				     binary_tree_node_t **new_node)
{
	if (!heap->root)
	{
		*(new_node) = binary_tree_node(heap->root, data);
		if (!(*new_node))
			return;
		heap->root = *new_node;
		heap->size++;
	}
}
