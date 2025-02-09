/*
** EPITECH PROJECT, 2024
** secured
** File description:
** search.c
*/

#include <stdlib.h>
#include "../include/hashtable.h"

char *ht_search(hashtable_t *ht, char *key)
{
    int hashed = 0;
    int index = 0;

    if (ht == NULL || key == NULL)
        return NULL;
    if (ht->len == 0)
        return NULL;
    hashed = ht->hash(key, ht->len);
    index = hashed % ht->len;
    if (index > ht->len)
        return NULL;
    while (ht->node[index] != NULL) {
        if (ht->node[index]->hash_key == hashed) {
            return ht->node[index]->data;
        }
        ht->node[index] = ht->node[index]->next;
    }
    return NULL;
}
