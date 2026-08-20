#include <stdio.h>

#include "src/hash_table.h"

int main(void)
{
    ht_hash_table *ht = ht_new();

    if (ht == NULL)
    {
        printf("Failed to create hash table\n");
        return 1;
    }

    ht_insert(ht, "name", "Shivansh");

    printf("Inserted successfully\n");

    char *value = ht_search(ht, "name");

    if (value != NULL)
    {
        printf("Value: %s\n", value);
    }
    else
    {
        printf("Key not found\n");
    }

    ht_del_hash_table(ht);

    return 0;
}