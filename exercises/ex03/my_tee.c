/*
Description: An implementation of 'tee' that takes the same command-line arguments
Author: Jeremy Garcia
*/
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	char ch;
	char line[100];
	int count = 0;
	int append = 0;

	while ((ch=getopt(argc,argv,"a")) != EOF ){
		switch (ch){
			case 'a':
				append = 1;
				break;
			default:
				fprintf(stderr, "Unknown option: '%s'\n", optarg);
				return 1;
		}
	}
	argc -= optind;
	argv += optind;

	FILE *f[argc];

	//opens files to append to. if no -a parameter, makes new file
	for (count = 0; count< argc; count++){
		if (append){
			f[count] = fopen(argv[count],"a");
		} else {
			f[count] = fopen(argv[count],"w");
		}
	}

	//writes to file
	while (scanf ("%99[^\n]\n", line) != EOF) {
		for (count = 0; count < argc; count++) {
			fprintf(f[count], "%s\n", line);
		}
	}

	//closes files
	for (count=0; count<argc; count++){
		fclose(f[count]);
	}

	return 0;
}

/*
3. What slowed me down most was trying to write to a file. Previously 
	I was trying to use fprintf with scanf and was getting strange 
	characters in my output file. 

4. There is a lot more of error checking in the professional code.
*/