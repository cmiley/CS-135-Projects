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

void bubblesort( char*str1, char* str2, int size );
void swap( char* str1, char* str2 );

int main( int argc, char* argv[])
{	

	int lines = atoi( argv[1] );
	char* searchname = argv[2];

	Census* c = new Census[lines];
	
	for( int i = 0; i < lines; i++ )
		{ 
			c[i].name = new char[30];
			fscanf( stdin, "%d %s %d %f %f %f %f %f %f", &c[i].linenum, c[i].name, &c[i].total, &c[i].type1, &c[i].type2, &c[i].type3, &c[i].type4,
      &c[i].type5, &c[i].type6 );

			printf( "%d %s %d %.2f %.2f %.2f %.2f %.2f %.2f\n", c[i].linenum, c[i].name, c[i].total, c[i].type1, c[i].type2, c[i].type3, c[i].type4,
      c[i].type5, c[i].type6 );
		}

	for( int i = 0; i < lines; i++ )
		{
			bubblesort( c[i].name, c[i+1].name, lines );
		}

for( int i = 0; i < lines; i++ )
		{
			printf( "%d %s %d %.2f %.2f %.2f %.2f %.2f %.2f\n", c[i].linenum, c[i].name, c[i].total, c[i].type1, c[i].type2, c[i].type3, c[i].type4,
      c[i].type5, c[i].type6 );
		}

return 0;
}

void swap( char* str1, char* str2)
{
	char* temp = new char[30];
	temp = str1;
	str1 = str2;
	str2 = temp;
}

void bubblesort( char*str1, char* str2, int size )
{
	for( int i=0; i < size-1; i++)
		{
			for( int j=0; j < size-i-1; j++)
				{
					if( str1 > str2)
						{
							swap(str1, str2);
						}
				}
		}
}
