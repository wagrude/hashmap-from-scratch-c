#include <stdio.h>

#include "src/hash_table.h"

int main(void)
{
    ht_hash_table *ht = ht_new();

    if (ht == NULL)
    {
        printf("Error: Failed to create hash table\n");
        return 1;
    }

    printf("HashMap created successfully\n");

    ht_del_hash_table(ht);

    return 0;
}