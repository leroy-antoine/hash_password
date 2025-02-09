/*
** EPITECH PROJECT, 2025
** dump.c
** File description:
** displays the table
*/

#include <stdio.h>
#include "../include/hashtable.h"
#include "../include/my.h"

void print_list(linked_list_t *tmp)
{
    if (tmp->data != NULL) {
        mini_printf("> %d - %s\n",
            tmp->hash_key, tmp->data);
    }
}

void ht_dump(hashtable_t *ht)
{
    int len = 0;
    linked_list_t *tmp = NULL;

    if (ht == NULL)
        return;
    len = ht->len;
    for (int i = 0; i < len; i++) {
        tmp = ht->node[i];
        mini_printf("[%d]:\n", i);
        if (tmp == NULL)
            continue;
        while (tmp != NULL) {
            print_list(tmp);
            tmp = tmp->next;
        }
    }
}
