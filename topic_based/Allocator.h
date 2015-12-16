#ifndef _ALLOCATOR_H
#define _ALLOCATOR_H

#include <stdio.h>
#include <stdlib.h>
#include "messages.h"

/* Configurable program elements. */
typedef struct AllocatorConfiguration {
    char *wordlist_path;
    char *document_info_path;
    char *document_vectors_folder_path;
    /* Total number of documents in the collection. */
    int number_of_documents;
    /* Total number of terms in the collection. */
    int number_of_terms;
} Conf;

typedef struct Document {
#ifdef DEBUG
    int doc_id;
#endif
    /* Raw document id between <DOCNO> and </DOCNO> */
    char *doc_no;
    /* Number of unique terms. */
    int uterm_count;
    /* Number of total terms. */
    int term_count;
    /* Beginning of a document's TermVectors inside the file. */
    int offset;
} Document, *Documents;

typedef struct Term {
#ifdef DEBUG
    /* Starts with 1. */
    int term_id;
    /* Raw term text. */
    char *token;
#endif
    /* Number of occurences of a Term in whole Collection. */
    int total_count;
    /* CFS Weight? */
    double cfc_weight;
} Term, *Terms;

typedef struct TermVector {
    int term_id;
    int term_frequency;
} DocumentVector, *DocumentVectors;

typedef enum {
    SUCCESS,
    EMPTY_CONFIG_DATA,
    COULD_NOT_ALLOCATE_TERMS,
    COULD_NOT_ALLOCATE_DOCUMENTS,
    COULD_NOT_OPEN_WORDLIST
} State;

int initAllocator (Conf*);
int loadTerms ();
void actstate ();

Conf *config;
Terms terms;
Documents documents;
State state;

#endif  /* not defined _ALLOCATOR_H */