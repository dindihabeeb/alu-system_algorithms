#include "graphs.h"

/**
 * graph_delete - deletes a graph
 * @graph: the graph to delete
 *
 * Return: nothing
 */
void graph_delete(graph_t *graph)
{
	vertex_t *curr, *temp_v;
	edge_t *curr_edge, *temp_e;

	if (!graph)
		return;

	curr = graph->vertices;

	while (curr)
	{
		curr_edge = curr->edges;
		while (curr_edge)
		{
			temp_e = curr_edge->next;
			free(curr_edge);
			curr_edge = temp_e;
		}
		temp_v = curr->next;
		free(curr->content);
		free(curr);
		curr = temp_v;
	}
	free(graph);
}
