#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gen.h"
#include "search.h"

PDICT init_dictionary(int size, char order){

    if(size <= 0 || (order != NOT_SORTED && order != SORTED)){
        return NULL;
    }

    PDICT dic = NULL;

    if(!(dic = (PDICT)malloc(sizeof(DICT)))){
        return NULL;
    }

    dic->size = size;
    dic->n_data = 0;
    dic->order = order;

    if(!(dic->table = (int*)malloc(size * sizeof(int)))){
        free(dic);
        return NULL;
    }

    return dic;
}

void free_dictionary(PDICT pdict){

    if(!pdict){
        return;
    }else{
        free(pdict->table);
        free(pdict);
    }

    return;
}

int insert_dictionary(PDICT dict, int key){

    if(!dict|| dict->n_data >= dict->size){
        return ERR;
    }

    int j = dict->n_data - 1;

    if(dict->order == NOT_SORTED){
        dict->table[dict->n_data] = key;
        dict->n_data++;
    }else{

        while (j >= 0 && dict->table[j] > key){
            dict->table[j + 1] = dict->table[j];
            j--;
        }  
        dict->table[j + 1] = key;
        dict->n_data++;
        }

    return OK;
}


int massive_insertion_dictionary(PDICT pdict, int* keys, int n_keys){


    if(!pdict || !keys || n_keys <= 0 || (pdict->n_data + n_keys) > pdict->size){
        return ERR;
    }

    int i;

    for(i=0; i< n_keys; i++){

        if(insert_dictionary(pdict,keys[i]) == ERR){
            return ERR;
        }

    }

    return OK;

}

int search_dictionary(PDICT pdict, int key, int* ppos, pfunc_search method);

int bin_search(int* table, int F, int L, int key, int* ppos);

int lin_search(int* table, int F, int L, int key, int* ppos);

int lin_auto_search(int* table, int F, int L, int key, int* ppos);
