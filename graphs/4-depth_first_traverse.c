#include "graphs.h"
/**
 * depth_first_traverse - goes through a graph using the depth-first algorithm.
 * @graph: pointer to the graph to traverse.
 * @action: a pointer to a function to be called for each visited vertex
 *
 * Return: the biggest vertex depth, or 0 on failure
 */
size_t depth_first_traverse(const graph_t *graph,
			    void (*action)(const vertex_t *v, size_t depth))
{
	size_t ans = 0;

	if (!graph || !action)
		return (0);

	int *visited = calloc(graph->nb_vertices, sizeof(int));

	if (!visited)
		return (0);

	ans = dfs_help_recurse(graph->vertices, action, 0, visited);
	free(visited);
	return (ans);
}

/**
 * dfs_help_recurse - dfs recursive helper.
 * @v: pointer to the starting vertex.
 * @action: a pointer to a function to be called for each next visited vertex
 * @passed_depth: depth of the current vertex since the head vertex
 * @visited: pointer to int array
 *
 * Return: the biggest vertex depth, or 0 on failure
 */
size_t dfs_help_recurse(vertex_t *v,
			void (*action)(const vertex_t *v, size_t depth),
			size_t passed_depth, int *visited)
{
	edge_t *curr_edge = NULL;
	vertex_t *next_v = NULL;
	size_t deepest = passed_depth;
	size_t dfs_ret = 0;

	if (!v)
		return (0);

	visited[v->index] = 1;
	action(v, passed_depth);

	curr_edge = v->edges;
	while (curr_edge)
	{
		next_v = curr_edge->dest;
		if (!visited[next_v->index])
		{
			dfs_ret = dfs_help_recurse(next_v, action,
						   passed_depth + 1, visited);
			deepest = deepest > dfs_ret
				? deepest : dfs_ret;
		}
		curr_edge = curr_edge->next;
	}
	return (deepest);
}
