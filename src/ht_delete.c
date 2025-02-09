/*
** EPITECH PROJECT, 2025
** ht_delete.c
** File description:
** ht delete
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/hashtable.h"

int ht_delete(hashtable_t *ht, char *key)
{
    linked_list_t *tmp = NULL;
    int hashed = 0;
    int index = 0;

    if (ht == NULL || key == NULL || ht->len == 0)
        return ERROR;
    hashed = ht->hash(key, ht->len);
    index = hashed % ht->len;
    tmp = ht->node[index];
    while (tmp != NULL) {
        if (tmp->hash_key == hashed) {
            free(tmp->data);
            tmp->data = NULL;
            tmp->occupied = false;
            tmp->hash_key = 0;
            return SUCCESS;
        }
        tmp = tmp->next;
    }
    return ERROR;
}
