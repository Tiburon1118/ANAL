#include <stdio.h>
#include <stdlib.h>

#include "search2.h"

/**
 * Searches for a key in the dictionary using a caller-provided search method.
 *
 * @param pdict Dictionary to search.
 * @param key Key to locate.
 * @param ppos Output pointer receiving the index of the found key or NOT_FOUND.
 * @param method Function implementing the search strategy.
 * @return Number of operations performed by the search or ERR on invalid input.
 */
int search_dictionary(PDICT pdict, int key, int *ppos, pfunc_search method) {
    if (!pdict || !pdict->table || !ppos || !method) {
        return ERR;
    }

    if (pdict->n_data == 0) {
        *ppos = NOT_FOUND;
        return 0;
    }

    return method(pdict->table, 0, pdict->n_data - 1, key, ppos);
}

/**
 * Performs a binary search in a sorted table.
 *
 * @param table Array to search.
 * @param F Lower-bound index of the search interval.
 * @param L Upper-bound index of the search interval.
 * @param key Key being searched.
 * @param ppos Output pointer receiving the key position or NOT_FOUND.
 * @return Number of comparisons performed.
 */
int bin_search(int *table, int F, int L, int key, int *ppos) {
    int m, cdc = 0;

    if (!table || !ppos || F < 0 || F > L) {
        return ERR;
    }

    while (F <= L) {
        m = F + (L - F) / 2;
        cdc++;

        if (table[m] == key) {
            *ppos = m;
            return cdc;
        } else if (key < table[m]) {
            L = m - 1;
        } else {
            F = m + 1;
        }
    }

    *ppos = NOT_FOUND;
    return cdc;
}

/**
 * Performs a linear search in a table interval.
 *
 * @param table Array to search.
 * @param F Lower-bound index of the search interval.
 * @param L Upper-bound index of the search interval.
 * @param key Key being searched.
 * @param ppos Output pointer receiving the key position or NOT_FOUND.
 * @return Number of comparisons performed.
 */
int lin_search(int *table, int F, int L, int key, int *ppos) {
    int i, cdc = 0;

    if (!table || !ppos || F < 0 || F > L) {
        return ERR;
    }

    for (i = F; i <= L; i++) {
        cdc++;
        if (table[i] == key) {
            *ppos = i;
            return cdc;
        }
    }

    *ppos = NOT_FOUND;
    return cdc;
}

/**
 * Performs a linear search that moves a found key one position closer to the front.
 *
 * @param table Array to search.
 * @param F Lower-bound index of the search interval.
 * @param L Upper-bound index of the search interval.
 * @param key Key being searched.
 * @param ppos Output pointer receiving the final key position or NOT_FOUND.
 * @return Number of comparisons performed.
 */
int lin_auto_search(int *table, int F, int L, int key, int *ppos) {
    int i, aux, cdc = 0;

    if (!table || !ppos || F < 0 || F > L) {
        return ERR;
    }

    for (i = F; i <= L; i++) {
        cdc++;
        if (table[i] == key) {
            if (i > F) {
                aux = table[i];
                table[i] = table[i - 1];
                table[i - 1] = aux;
                *ppos = i - 1;
            } else {
                *ppos = F;
            }
            return cdc;
        }
    }

    *ppos = NOT_FOUND;
    return cdc;
}
