#include<stdio.h>
#include"image_to_array.h"

int main( int argc, char* argv[])
{

	FILE *ofp; //output file variable name
	char outputFilename[] = "blue-balloons.txt"; // output to "blue-balloons.txt"

	ofp = fopen(outputFilename, "w"); // open the file to output to it

	if (ofp == NULL) 
	{
  		fprintf(stderr, "Can't open output file %s!\n",outputFilename);
 		exit(1);
	}

	char* inputFile = argv[1]; // input file will be the second command line argument
	
	ImageData originalImage = image_to_array(inputFile); // change the input file into an 
																											 //array using the image_to_array function
	ImageData blueImage; // create ImageData struct for the new image, called blueImage
	blueImage.width = originalImage.width; // width of the new image is equal to the width of the input image
	blueImage.height = originalImage.height; // height of the new image is equal to the width of the input image

	int width = originalImage.width;
	int height = originalImage.height;

	printf( "height: %d  width: %d \n", height, width); // verify height and width are transferred correctly

	//Allocate image.data

	blueImage.data = new unsigned char**[height]; //make "height" new 2d arrays

	for(int i = 0; i < height; i++) //for as many "height"
	{
		blueImage.data[i] = new unsigned char*[width]; //make "width" new 1d arrays
	}

	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			blueImage.data[i][j] = new unsigned char[3]; //make 3 channels per pixel location
		}
	}

	printf("originalImage.data[374][499][2] = %d\n", originalImage.data[374][499][2]);
	printf("blueImage.data[374][499][0] = %d\n", blueImage.data[374][499][0]);

	//blueImage.data = originalImage.data;

	
	//Swap red and blue signatures if the red density is high
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{	
			////////// If red channel is high and blue channel is low, switch them ///////////					
			if( originalImage.data[i][j][2] > 110 && originalImage.data[i][j][0] < 200 )
			{
				blueImage.data[i][j][0] = originalImage.data[i][j][2]; //blue channel equals red
				blueImage.data[i][j][2] = originalImage.data[i][j][0]; //red channel equals blue
				blueImage.data[i][j][1] = originalImage.data[i][j][1]; //green channel is copied

				fprintf( ofp, "%d %d\n", i , j);
			}
			else // If not, copy them from the originalImage
			{
				blueImage.data[i][j][0] = originalImage.data[i][j][0];
				blueImage.data[i][j][1] = originalImage.data[i][j][1];
				blueImage.data[i][j][2] = originalImage.data[i][j][2];
			}
			
			//printf("image.data[%d][%d]: %d\n", i, j, blueImage.data[i][j][0]);
			
		}
	}

	printf("Loop completed\n");

	for( int i = 0; i < height; i++ )
	{
		for( int j = 0; j < width; j++ )
		{			
			//fprintf( ofp, "%d %d %d\n", blueImage.data[i][j][0], blueImage.data[i][j][1], blueImage.data[i][j][2] );
		}
	}

	printf("%d %d %d\n", blueImage.data[374][499][0], blueImage.data[374][499][1], blueImage.data[374][499][2] );
	
	array_to_image( blueImage, "Blue Balloons");	

	fclose( ofp );

	cv::waitKey(0);

	return 0;
}
