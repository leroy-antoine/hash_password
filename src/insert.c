/*
** EPITECH PROJECT, 2025
** insert.c
** File description:
** insert into hashtable
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/hashtable.h"
#include "../include/my.h"

static int replace_if_duplicate(hashtable_t *ht,
    int hashed, int index, char *value)
{
    linked_list_t *tmp = ht->node[index];
    bool error = false;

    if (ht->node[index] == NULL)
        return ERROR;
    while (tmp != NULL) {
        if (tmp->data != NULL && tmp->hash_key == hashed) {
            free(tmp->data);
            tmp->data = my_strdup(value);
            error = true;
        }
        if (error && tmp->data == NULL)
            return ERROR;
        if (error) {
            ht->node[index] = tmp;
            return SUCCESS;
        }
        tmp = tmp->next;
    }
    return NO_DUPLICATE;
}

static linked_list_t *init_values(linked_list_t *node)
{
    node = malloc(sizeof(linked_list_t));
    if (!node)
        return NULL;
    node->data = NULL;
    node->hash_key = 0;
    node->next = NULL;
    node->occupied = false;
    return node;
}

static linked_list_t *handle_error(hashtable_t *ht, int len)
{
    linked_list_t *tmp = {0};

    for (int i = 0; i < len; i++) {
        while (ht->node[i]->next != NULL) {
            tmp = ht->node[i];
            ht->node[i] = ht->node[i]->next;
            free(tmp->data);
            free(tmp);
        }
        free(ht->node[i]);
    }
    free(ht);
    return NULL;
}

static linked_list_t *populate_linked_list(linked_list_t *tmp, hashtable_t *ht,
    int hashed, char *value)
{
    tmp = malloc(sizeof(linked_list_t));
    if (tmp == NULL)
        return handle_error(ht, ht->len);
    tmp->next = NULL;
    tmp->occupied = true;
    tmp->data = my_strdup(value);
    if (tmp->data == NULL) {
        handle_error(ht, ht->len);
        free(tmp);
        return NULL;
    }
    tmp->hash_key = hashed;
    return tmp;
}

static linked_list_t *fill_unoccupied(hashtable_t *ht,
    int index, int hashed, char *value)
{
    ht->node[index]->occupied = true;
    ht->node[index]->data = my_strdup(value);
    if (ht->node[index]->data == NULL)
        return NULL;
    ht->node[index]->hash_key = hashed;
    return ht->node[index];
}

int manage_linked_list(hashtable_t *ht, int hashed, char *value, int index)
{
    linked_list_t *tmp = NULL;

    tmp = populate_linked_list(tmp, ht, hashed, value);
    if (tmp == NULL)
        return ERROR;
    tmp->next = ht->node[index]->next;
    ht->node[index]->next = tmp;
    return SUCCESS;
}

int init_int(int *hashed, int *index, hashtable_t *ht, char *key)
{
    if (key == NULL || index == NULL)
        return ERROR;
    *hashed = ht->hash(key, ht->len);
    if (*hashed <= 0)
        return ERROR;
    *index = *hashed % ht->len;
    return SUCCESS;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int hashed = 0;
    int index = 0;
    int error = 0;

    if (value == NULL || ht == NULL || ht->len <= 0)
        return ERROR;
    if (init_int(&hashed, &index, ht, key) == ERROR)
        return ERROR;
    if (ht->node[index] == NULL)
        ht->node[index] = init_values(ht->node[index]);
    error = replace_if_duplicate(ht, hashed, index, value);
    if (error == NO_DUPLICATE && !ht->node[index]->occupied) {
        if (fill_unoccupied(ht, index, hashed, value) == NULL)
            return ERROR;
        return SUCCESS;
    }
    if (error == ERROR || (error == NO_DUPLICATE &&
        manage_linked_list(ht, hashed, value, index) == ERROR))
        return ERROR;
    return SUCCESS;
}
