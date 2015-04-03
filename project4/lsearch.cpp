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

Census search( char* str1, int size );

int main( int argc, char* argv[])
{	

	int lines = atoi( argv[1] );
	char* searchname = argv[2];

	printf( "%s\n", searchname );

	Census* c = new Census[lines];
	
	for( int i = 0; i < lines; i++ ) //scan in data
		{ 
			c[i].name = new char[30];
			fscanf( stdin, "%d %s %d %f %f %f %f %f %f", &c[i].linenum, c[i].name, &c[i].total, &c[i].type1, &c[i].type2, &c[i].type3, &c[i].type4,
      &c[i].type5, &c[i].type6 );
		}

	for( int i = 0; i < lines; i++ )
		{ 
			if( strcmp(c[i].name, searchname) == 0 );
				{
					printf( "%d %s %d %.2f %.2f %.2f %.2f %.2f %.2f\n", c[i].linenum, c[i].name, c[i].total, c[i].type1, c[i].type2, c[i].type3, c
					[i].type4, c[i].type5, c[i].type6 );
				}
		}

	//search( searchname, lines );


return 0;
}

/*Census search( char* str1, int size )
{
	for(int i = 0; i < size; i++)
		{
			strcmp( str1, c.name[i] );
			if( strcmp = 0)
				{
					printf("%d %s %d %f %f %f %f %f %f", c[i].linenum, c[i].name, c[i].total, c[i].type1, c[i].type2, c[i].type3, c[i].type4,
      		c[i].type5, c[i].type6 );
				}
		}
}*/
