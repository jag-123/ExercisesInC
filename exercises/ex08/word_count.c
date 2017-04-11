/*
Solution by Jeremy Garcia

Reads a text file, splits lines into words,
and counts the frequency of each word
*/

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

void print_helper(gpointer key,gpointer val,gpointer data) {
  printf(data,(int*) val, (char*) key);
}

void parse_file(char *filename,GHashTable *table){
	gchar *content;
	g_file_get_contents(filename, &content,NULL,NULL);

	//split text into separate words
	gchar **words = g_strsplit(content, " ",-1);

	//iterate through the words
	while (*words){
		gpointer val = g_hash_table_lookup(table, *words);
		if (val){
			g_hash_table_replace(table,*words, (gpointer) val+1);
		} 
		else {
			g_hash_table_insert(table,*words,(gpointer) 1);
		}
		words++;
	}

	g_hash_table_foreach(table,print_helper,"%d:%s\n");
	g_free(content);
	g_free(*words);
}

int main(int argc, char** argv) {
	GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);

	char *filename;

	// open the file
	if (argc > 1){
		filename = argv[1];
	} else {
		filename = "test.txt";
	}

	parse_file(filename, hash);

	return 0;
}