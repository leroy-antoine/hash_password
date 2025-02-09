/*
** EPITECH PROJECT, 2025
** hash_table.c
** File description:
** hash_table
*/

#include <stdlib.h>
#include "../include/hashtable.h"

int handle_error(int (*hash)(char *, int), int len, hashtable_t **table)
{
    if (*table == NULL || hash == NULL)
        return ERROR;
    if (len < 0) {
        free(*table);
        return ERROR;
    }
    return SUCCESS;
}

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *table = malloc(sizeof(hashtable_t));

    if (handle_error(hash, len, &table) == ERROR)
        return NULL;
    if (len == 0) {
        table->len = 0;
        table->node = NULL;
        table->hash = hash;
        return table;
    }
    table->node = malloc(sizeof(linked_list_t) * len);
    if (table->node == NULL)
        return NULL;
    table->len = len;
    table->hash = hash;
    for (int i = 0; i < len; i++)
        table->node[i] = NULL;
    return table;
}
