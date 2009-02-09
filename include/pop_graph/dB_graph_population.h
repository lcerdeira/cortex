/*
  dB_graph_population.h

  wrapper for hash_table for people who want to think of the hash table as 
  many de bruijn graphs drawn on top of each other.

*/

#ifndef DB_GRAPH__POPULATION_H_
#define DB_GRAPH_POPULATION_H_

#include <element.h>
#include <hash_table.h>
#include <seq.h>
#include <dB_graph_supernode.h>

//***********************
//functions applied to node, with respect to an individual or population
//***********************


dBNode *  db_graph_find_node_restricted_to_specific_person_or_population(Key key, dBGraph * hash_table, EdgeArrayType type, int index);

char * get_seq_from_elem_to_end_of_supernode_for_specific_person_or_pop(dBNode * node, Orientation orientation, dBGraph * db_graph, boolean * is_cycle, EdgeArrayType type, int index);

void print_supernode_for_specific_person_or_pop(HashTable* db_graph, dBNode * node,EdgeArrayType type, int index, boolean is_for_testing, char** for_test, int* index_for_test);


// functions applied to a person/population's graph
void db_graph_traverse_specific_person_or_pop(void (*f)(HashTable*, Element *, EdgeArrayType, int, boolean, char**, int*),HashTable * hash_table, EdgeArrayType type, int index, boolean is_for_testing, char** for_test, int* index_for_test);

void hash_table_traverse_2(void (*f)(HashTable*, Element *, int**, int),HashTable *, int**, int);

void db_graph_print_supernode_for_specific_person_or_pop(FILE * file, dBNode * node, dBGraph * db_graph, EdgeArrayType type, int index, boolean is_for_testing, char** for_test, int* index_for_test );

void db_graph_set_all_visited_nodes_to_status_none_for_specific_person_or_population(dBGraph* hash_table, EdgeArrayType type, int index);



dBNode * db_node_get_next_node_for_specific_person_or_pop(dBNode * current_node, Orientation current_orientation,
							   Orientation * next_orientation,
							   Nucleotide edge, Nucleotide * reverse_edge, HashTable * db_graph, EdgeArrayType type, int index);

//returns true if the node side defined by the orientation is a conflict 
//or doesn't have any outgoing edge
boolean db_node_is_supernode_end(dBNode* node, Orientation orientation, EdgeArrayType edge_type, int edge_index, dBGraph* db_graph);


// given a node, find the start of the supernode that contains it. Then return the sequence for the subsection of that supernode starting at index start, and ending at end
// in the pre-malloc-ed char* which was passed in as the frst argument
int db_graph_get_subsection_of_supernode_containing_given_node_as_sequence(char* subsection, dBNode* node, int start, int end, EdgeArrayType type, int index, dBGraph* db_graph);
void db_graph_get_subsection_of_supernode_containing_given_node_as_supernode_object(dBSupernode* subsection, dBNode* node, int start, int end, EdgeArrayType type, int index, dBGraph* db_graph);

void apply_function_to_every_node_in_supernode_object(dBSupernode*, void (*f)(dBNode*));
void apply_function_to_every_node_in_supernode_containing_given_node(void (*f)(dBNode*, EdgeArrayType, int, dBGraph*), dBNode* node);


dBNode* db_graph_get_first_node_in_supernode_containing_given_node_for_specific_person_or_pop(dBNode* node, EdgeArrayType type, int index, dBGraph* db_graph);
dBNode* db_graph_get_next_node_in_supernode_for_specific_person_or_pop(dBNode* node, Orientation o, Orientation* next_orientation, EdgeArrayType type, int index, dBGraph* db_graph);


//returns for this function are in the two int*'s.
void  db_graph_get_best_sub_supernode_given_min_covg_and_length_for_specific_person_or_pop(dBNode* first_node_in_supernode,  int* index_for_start_of_sub_supernode,
											   int* length_of_best_sub_supernode, int min_people_coverage, 
											   int min_length_of_sub_supernode, EdgeArrayType type, int index, dBGraph* db_graph);

void  db_graph_find_population_consensus_supernode_based_on_given_node(Sequence* pop_consensus_supernode, dBNode* node, int min_covg_for_pop_supernode, int min_length_for_pop_supernode, dBGraph* db_graph);



void print_node_to_file_according_to_how_many_people_share_it(HashTable* db_graph, dBNode * node, FILE** list_of_file_ptrs);
void find_out_how_many_individuals_share_this_node_and_add_to_statistics(HashTable* db_graph, dBNode * node, int** array_of_counts, int number_of_people);

#endif
