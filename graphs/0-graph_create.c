#include "graphs.h"

/**
 * graph_create - allocates memory to store a graph_t structure, and
 * initializes its content
 *
 * Return: a pointer to the allocated graph or NULL on failure to allocate
 */
graph_t *graph_create(void)
{
	graph_t *graph = calloc(1, sizeof(*graph));

	if (!graph)
		return (NULL);
	return (graph);
}
