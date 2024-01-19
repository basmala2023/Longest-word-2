# Longest-word-2
Assigned work - Part 2
The aim of this second part is to integrate the search using a dictionary to find the longest word (or all the n-letter words).

To be efficient, we represent the dictionary containing n-letter words by a planar tree, such that:

Each node in this tree has up to n children.

The relationship between a node and its ith child (if it exists) in terms of letters is that they have (i - 1) identical character(s) (same letter, same position). Specifically, the relationship between a node and its children is as follows:

First child: 0 identical (in common) characters.

Second child: 1 identical character.

nth child: n - 1 identical characters.

Illustrative example of a 3-letter dictionary/tree

Steps to follow
Download a free .txt or .csv file/dictionary containing all English words.

You can pick the language of your choice (Arabic, English, French, etc.).
Write the subprograms (functions) that use the provided files to create/load the dictionaries of n-letter words before starting the game (2 ≤ n ≤ 10).

Write the subprograms that search for a word in these dictionaries.

After finishing the game, you have to delete the created dynamic dictionaries.
