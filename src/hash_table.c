#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

static ht_item *ht_new_item(const char *key, const char *value)
{
    ht_item *item = malloc(sizeof(ht_item));

    if (item == NULL)
    {
        return NULL;
    }

    item->key = strdup(key);
    item->value = strdup(value);

    if (item->key == NULL || item->value == NULL)
    {
        free(item->key);
        free(item->value);
        free(item);
        return NULL;
    }

    return item;
}

ht_hash_table *ht_new(void)
{
    ht_hash_table *ht = malloc(sizeof(ht_hash_table));

    if (ht == NULL)
    {
        return NULL;
    }

    ht->size = 53;
    ht->count = 0;
    ht->items = calloc((size_t)ht->size, sizeof(ht_item *));

    if (ht->items == NULL)
    {
        free(ht);
        return NULL;
    }

    return ht;
}

static void ht_del_item(ht_item *item)
{
    if (item == NULL)
    {
        return;
    }

    free(item->key);
    free(item->value);
    free(item);
}

void ht_del_hash_table(ht_hash_table *ht)
{
    if (ht == NULL)
    {
        return;
    }

    for (int i = 0; i < ht->size; i++)
    {
        ht_del_item(ht->items[i]);
    }

    free(ht->items);
    free(ht);
}

static int ht_hash(const char *s, const int a, const int m)
{
    long hash = 0;
    int len_s = (int)strlen(s);

    for (int i = 0; i < len_s; i++)
    {
        hash += (long)pow(a, len_s - (i + 1)) * s[i];
        hash %= m;
    }

    return (int)hash;
}

void ht_insert(ht_hash_table *ht, const char *key, const char *value)
{
    int index = ht_hash(key, 151, ht->size);

    if (ht->items[index] == NULL)
    {
        ht_item *item = ht_new_item(key, value);

        if (item == NULL)
        {
            return;
        }

        ht->items[index] = item;
        ht->count++;
    }
}