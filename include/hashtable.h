/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H
    #include <stdbool.h>
    #define ERROR 84
    #define SUCCESS 0
    #define LEN_INT_MAX 10
    #define NO_DUPLICATE 92046
    #define ERROR_SIZE -1

typedef struct linked_list_s {
    int hash_key;
    char *data;
    bool occupied;
    struct linked_list_s *next;
} linked_list_t;

typedef struct hashtable_s {
    int len;
    int (*hash)(char *, int);
    linked_list_t **node;
} hashtable_t;

// Hash function
int hash(char *key, int len);

// Create & destroy table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);

#endif /* HASHTABLE_H */
