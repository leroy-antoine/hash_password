/*
** EPITECH PROJECT, 2025
** delete_hashtable.c
** File description:
** delete hashtable
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/hashtable.h"

void delete_hashtable(hashtable_t *ht)
{
    int len = 0;
    linked_list_t *temp = {0};

    if (ht == NULL)
        return;
    len = ht->len;
    for (int i = 0; i < len; i++) {
        while (ht->node[i] != NULL) {
            temp = ht->node[i];
            ht->node[i] = ht->node[i]->next;
            free(temp->data);
            free(temp);
            temp = NULL;
        }
    }
    free(ht->node);
    free(ht);
}
