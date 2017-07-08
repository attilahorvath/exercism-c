#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "anagram.h"

#define MAX_VEC_SIZE 128

void downcase(char *dst, char *src) {
    int i;
    char c;

    for (i = 0; (c = src[i]) != '\0'; i++) {
        dst[i] = tolower(c);
    }

    dst[i] = '\0';
}

int char_cmp(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}

int is_anagram(char *a, char *b) {
    char aBuf[MAX_STR_LEN];
    char bBuf[MAX_STR_LEN];

    unsigned len;

    downcase(aBuf, a);
    downcase(bBuf, b);

    len = strlen(aBuf);

    if (len != strlen(bBuf) || strncmp(aBuf, bBuf, MAX_STR_LEN) == 0) {
        return 0;
    }

    qsort(aBuf, len, sizeof(char), char_cmp);
    qsort(bBuf, len, sizeof(char), char_cmp);

    return strncmp(aBuf, bBuf, len) == 0;
}

struct Vector anagrams_for(char *word, struct Vector candidates) {
    struct Vector anagrams = { NULL, 0 };

    char matches[MAX_VEC_SIZE] = { 0 };

    int size = 0;
    int i, n = 0;

    for (i = 0; i < candidates.size; i++) {
        if (is_anagram(word, candidates.vec[i])) {
            size++;
            matches[i] = 1;
        }
    }

    if (size > 0) {
        anagrams.vec =
            (char(*)[MAX_STR_LEN])malloc(sizeof(char*) * MAX_STR_LEN * size);
        anagrams.size = size;
    }

    for (i = 0; i < MAX_VEC_SIZE; i++) {
        if (matches[i]) {
            strncpy(anagrams.vec[n], candidates.vec[i], MAX_STR_LEN);
            n++;
        }
    }

    return anagrams;
}
