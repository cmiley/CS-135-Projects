#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
int linenum;
char* name;
int total;
float type1;
float type2;
float type3;
float type4;
float type5;
float type6;
} Census;

int main( int argc, char* argv[])
{	

	int lines = atoi( argv[1] );
	
	FILE* fp;
	char outputFilename[] = "nameSortedCensusData";
	fp = fopen(outputFilename, "w");

	if (fp == NULL) {
  	fprintf(stderr, "Can't open output file %s!\n",
  	        outputFilename);
  	exit(1);
	}

	Census* c = new Census[lines];
	
	for( int i = 0; i < lines; i++ )
		{ 
			c[i].name = new char[30];
			fscanf( stdin, "%d %s %d %f %f %f %f %f %f", &c[i].linenum, c[i].name, &c[i].total, &c[i].type1, &c[i].type2, &c[i].type3, &c[i].type4,
      &c[i].type5, &c[i].type6 );

			fprintf( stdout, "%d %s %d %.2f %.2f %.2f %.2f %.2f %.2f\n", c[i].linenum, c[i].name, c[i].total, c[i].type1, c[i].type2, c[i].type3, c[i].type4,
      c[i].type5, c[i].type6 );
		}
return 0;
}
