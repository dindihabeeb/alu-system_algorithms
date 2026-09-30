#include "graphs.h"

/**
 * breadth_first_traverse - goes through a graph using the
 * breadth-first algorithm.
 * @graph: a pointer to the graph to traverse
 * @action: a pointer to a function to be called for each visited vertex.
 *
 * Return: the biggest vertex depth, or 0 on failure
 */
size_t breadth_first_traverse(const graph_t *graph,
			      void (*action)(const vertex_t *v, size_t depth))
{
	size_t ans = 0;
	int *visited;

	if (!graph || !action || !graph->vertices)
		return (0);

	visited = calloc(graph->nb_vertices, sizeof(int));
	if (!visited)
		return (0);

	ans = bfs_helper(graph, action, visited);

	free(visited);
	return (ans);
}

/**
 * bfs_helper - helper that runs breadth-first algorithm.
 * @graph: a pointer to the graph to traverse
 * @action: a pointer to a function to be called for each visited vertex.
 * @visited: pointer to array of ints that mark visited vertices
 *
 * Return: the biggest vertex depth, or 0 on failure
 */
size_t bfs_helper(const graph_t *graph,
		  void (*action)(const vertex_t *v, size_t depth),
		  int *visited)
{
	vertex_t *curr_v, **queue;
	edge_t *curr_e;
	size_t *depth, max_depth = 0;
	int head = 0, tail = 0;

	queue = calloc(graph->nb_vertices, sizeof(vertex_t *));
	if (!queue)
		return (0);
	depth = calloc(graph->nb_vertices, sizeof(size_t));
	if (!depth)
	{
		free(queue);
		return (0);
	}
	visited[graph->vertices->index] = 1;
	queue[tail] = graph->vertices;
	tail++;
	while (tail != head)
	{
		curr_v = queue[head];
		curr_e = curr_v->edges;
		max_depth = depth[curr_v->index];
		action(curr_v, max_depth);

		while (curr_e)
		{
			if (!visited[curr_e->dest->index])
			{
				visited[curr_e->dest->index]++;
				queue[tail] = curr_e->dest;
				depth[curr_e->dest->index] = max_depth + 1;
				tail++;
			}
			curr_e = curr_e->next;
		}
		head++;
	}
	free(depth);
	free(queue);
	return (max_depth);
}
