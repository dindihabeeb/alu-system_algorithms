#include "graphs.h"

/**
 * graph_add_edge - adds an edge between two vertices to an existing graph.
 * @graph: a pointer to the graph to add the edge to
 * @src: the string identifying the vertex to make the connection from
 * @dest: he string identifying the vertex to connect to
 * @type: is the type of edge
 *
 * Return: 1 on success, or 0 on failure.
 */
int graph_add_edge(graph_t *graph, const char *src, const char *dest,
		   edge_type_t type)
{
	vertex_t *curr;
	vertex_t *src_vertex = NULL;
	vertex_t *dest_vertex = NULL;

	if (!graph || !src || !dest)
		return (0);

	if (type != BIDIRECTIONAL && type != UNIDIRECTIONAL)
		return (0);

	curr = graph->vertices;

	while (curr)
	{
		if (strcmp(curr->content, src) == 0)
			src_vertex = curr;
		if (strcmp(curr->content, dest) == 0)
			dest_vertex = curr;
		curr = curr->next;
	}
	if (!src_vertex || !dest_vertex)
		return (0);

	return (handle_edges(type, src_vertex, dest_vertex));
}

/**
 * handle_edges - creates and manage edges.
 * @src_vertex: src vertex
 * @dest_vertex: dest vertex
 * @type: is the type of edge
 *
 * Return: 1 on success, or 0 on failure.
 */
int handle_edges(edge_type_t type, vertex_t *src_vertex, vertex_t *dest_vertex)
{
	edge_t *edge1 = NULL;
	edge_t *edge2 = NULL;

	edge1 = malloc(sizeof(edge_t));
	if (!edge1)
		return (0);

	if (type == BIDIRECTIONAL && src_vertex != dest_vertex)
	{
		edge2 = malloc(sizeof(edge_t));
		if (!edge2)
		{
			free(edge1);
			return (0);
		}
	}
	add_x_to_y(src_vertex, dest_vertex, edge1);

	if (edge2 != NULL)
		add_x_to_y(dest_vertex, src_vertex, edge2);

	return (1);
}

/**
 * add_x_to_y - adds an edge between two vertices x and yh.
 * @edge: a pointer to the edge to use
 * @x:  src vertex
 * @y: dest vertex
 *
 * Return: nothing.
 */
void add_x_to_y(vertex_t *x, vertex_t *y, edge_t *edge)
{
	edge_t *curr_edge;

	curr_edge = x->edges;

	edge->next = NULL;
	edge->dest = y;
	if (!curr_edge)
		x->edges = edge;
	else
	{
		while (curr_edge->next)
		{
			curr_edge = curr_edge->next;
		}
		curr_edge->next = edge;
	}
	x->nb_edges++;
}
