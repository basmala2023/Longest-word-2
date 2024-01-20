#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHILDREN 26 
typedef struct TrieNode {
    struct TrieNode *children[MAX_CHILDREN];
    int isEndOfWord;
} TrieNode;
TrieNode* createNode() {
    TrieNode *newNode = (TrieNode*)malloc(sizeof(TrieNode));
    if (newNode) {
        newNode->isEndOfWord = 0;
        for (int i = 0; i < MAX_CHILDREN; i++) {
            newNode->children[i] = NULL;
        }
    }
    return newNode;
}
void insertWord(TrieNode *root, const char *word) {
    TrieNode *current = root;
    int length = strlen(word);

    for (int level = 0; level < length; level++) {
        int index = word[level] - 'A'; 
        if (!current->children[index]) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = 1;
}
int searchWord(TrieNode *root, const char *word) {
    TrieNode *current = root;
    int length = strlen(word);

    for (int level = 0; level < length; level++) {
        int index = word[level] - 'A';  
        if (!current->children[index]) {
            return 0;
        }
        current = current->children[index];
    }
    return (current != NULL && current->isEndOfWord);
}
void deleteTrie(TrieNode *root) {
    if (!root) {
        return;
    }
    for (int i = 0; i < MAX_CHILDREN; i++) {
        if (root->children[i]) {
            deleteTrie(root->children[i]);
        }
    }
    free(root);
}
int main() {
    char * wordtosearch = "computer"  ;
    TrieNode *root = createNode();
    FILE *file = fopen("your_dictionary_file.txt", "r");
    if (file) {
        char word[20];
        while (fscanf(file, "%s", word) != EOF) {
            insertWord(root, word);
        }
        fclose(file);
    }
    if (searchWord(root, wordtosearch)) {
        printf("%s found in the dictionary.\n", wordtosearch);
    } else {
        printf("%s not found in the dictionary.\n", wordtosearch);
    }
    deleteTrie(root);
    return 0;
}
