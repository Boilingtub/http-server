#ifndef Dictionary_h
#define Dictionary_h

#include "../Trees/BinarySearchTree.h"

struct Dictionary {
    struct BinarySearchTree binary_search_tree;
    void (*insert)(struct Dictionary *dictionary, 
                   void *key , unsigned long key_size,
                   void *value, unsigned long value_size);
    void* (*search)(struct Dictionary *dictionary, void *key,
                    unsigned long key_size);
};

struct Dictionary dictionary_constructor(int (*compare)
                                         (void *key_one,
                                          void *key_two));

void dictionary_destructor(struct Dictionary *dictionary);

int compare_string_keys(void* entry_one, void* entry_two);
#endif
