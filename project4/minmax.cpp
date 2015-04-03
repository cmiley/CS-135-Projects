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

	float min=10000000000;
	float max=0;
	int lmax=0;
	int lmin=0;

	int lines = atoi( argv[1] );

	Census* c = new Census[lines];
	
	for( int i = 0; i < lines; i++ )
		{ 
			c[i].name = new char[30];
			fscanf( stdin, "%d %s %d %f %f %f %f %f %f", &c[i].linenum, c[i].name, &c[i].total, &c[i].type1, &c[i].type2, &c[i].type3, &c[i].type4,
      &c[i].type5, &c[i].type6 );
			if(c[i].total < min )
				{
					min = c[i].total;
					lmin = i;
				}

			if(c[i].total > max)
				{
					max= c[i].total;
					lmax = i;
				}

			//printf( "%d %s %d %.2f %.2f %.2f %.2f %.2f %.2f\n", c[i].linenum, c[i].name, c[i].total, c[i].type1, c[i].type2, c[i].type3,
			//c[i].type4, c[i].type5, c[i].type6 );
		}

	printf("Max:\n");
	printf( "%d %s %d %.2f %.2f %.2f %.2f %.2f %.2f\n", c[lmax].linenum, c[lmax].name, c[lmax].total, c[lmax].type1, c[lmax].type2, c[lmax].type3,
			c[lmax].type4, c[lmax].type5, c[lmax].type6 );

printf("Min:\n");
	printf( "%d %s %d %.2f %.2f %.2f %.2f %.2f %.2f\n", c[lmin].linenum, c[lmin].name, c[lmin].total, c[lmin].type1, c[lmin].type2, c[lmin].type3,
			c[lmin].type4, c[lmin].type5, c[lmin].type6 );

return 0;
}
