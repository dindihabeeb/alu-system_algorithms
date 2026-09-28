#include "graphs.h"
#include <string.h>
#include <stdlib.h>

/**
 * graph_add_vertex - adds a vertex to an existing graph.
 * @graph: pointer to the graph to add the vertex to
 * @str: string to store in the new vertex
 *
 * Return: a pointer to the created vertex or NULL on failure.
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *new_vertex, *curr;

	if (!graph || !str)
		return (NULL);
	new_vertex = malloc(sizeof(*new_vertex));

	if (!new_vertex)
		return (NULL);
	curr = graph->vertices;

	while (curr)
	{
		if (strcmp(curr->content, str) == 0)
		{
			free(new_vertex);
			return (NULL);
		}
		if (curr->next == NULL)
			break;
		curr = curr->next;
	}

	new_vertex = populate_vertex(new_vertex, str, graph);

	if (!new_vertex)
		return (NULL);

	if (graph->vertices)
		curr->next = new_vertex;
	else
		graph->vertices = new_vertex;

	graph->nb_vertices++;
	return (new_vertex);
}


vertex_t *populate_vertex(vertex_t *new_vertex, const char *str,
			  graph_t *graph)
{
	new_vertex->content = malloc(strlen(str) + 1);

	if (!new_vertex->content)
	{
		free(new_vertex);
		return (NULL);
	}
	strcpy(new_vertex->content, str);
	new_vertex->index = graph->nb_vertices;
	new_vertex->next = NULL;
	new_vertex->nb_edges = 0;
	new_vertex->edges = NULL;

	return (new_vertex);
}
