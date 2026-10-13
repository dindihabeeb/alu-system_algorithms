#include "huffman.h"

/**
 * symbol_create - a function that creates a symbol_t data structure
 * @data: is the data to be stored in the structure
 * @freq: its associated frequency
 *
 * Return: a pointer to the created structure, or NULL if it fails
 */
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *new_s = malloc(sizeof(symbol_t));

	if (!new_s)
		return (NULL);

	new_s->data = data;
	new_s->freq = freq;

	return (new_s);
}
