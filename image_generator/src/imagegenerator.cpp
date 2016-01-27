/*
 * imagegenerator.cpp - This program generates a set of training images for
 * the neural network to train on as well as a set of images to test the
 * neural network on.
 *
 * Bryant Pong
 * 1/1/16
 */

// STL Includes:
#include <iostream>
#include <string>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

// OpenCV Headers:
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

// Constants:
const std::string TOPLEVELIMAGES = "images"; 
const std::string TRAININGIMAGES = "training_images";
const std::string TESTIMAGES = "test_images";    

// Image Size:
const int IMGWIDTH = 128;
const int IMGHEIGHT = 128;

// Enumerations:
enum COLORS
{
	RED=0,
	GREEN,
	BLUE	
};

// Function prototypes:
int GenerateFolderStructure(); 
cv::Mat GenerateImage( const int blue, const int green, const int red ); 
void GenerateImageRange( const COLORS color );
void CreateImageSet( const COLORS color );     
void DisplayImage( const std::string& imageName, const cv::Mat& image );   

// Function to create folders to hold training and test images:
int GenerateFolderStructure()
{
	if( mkdir( TOPLEVELIMAGES.c_str(), 0777 ) == -1 && errno != EEXIST )
	{
		std::cerr << "Error: Could not create " << TOPLEVELIMAGES << " directory." << std::endl;
		return -1;
	}

	if( mkdir( (TOPLEVELIMAGES+"/"+TRAININGIMAGES).c_str(), 0777 ) == -1 && errno != EEXIST )
	{
		 std::cerr << "Error: Could not create " << TRAININGIMAGES << " directory." << std::endl;
		 return -1;
	}


	if( mkdir( (TOPLEVELIMAGES+"/"+TESTIMAGES).c_str(), 0777 ) == -1 && errno != EEXIST )
	{
		 std::cerr << "Error: Could not create " << TESTIMAGES << " directory." << std::endl;
		 return -1;
	}

	return 0;
}

// Function to generate an RGB image:
cv::Mat GenerateImage( const int blue, const int green, const int red )
{
	// Create a 128x128 3-channel image initialized to the rgb values
	// Remember that OpenCV stores colors as BGR rather than RGB. 
	return cv::Mat( IMGWIDTH, IMGHEIGHT, CV_8UC3, 
	       cv::Scalar( blue, green, red ) );
}

// Function to generate a certain range of images (i.e. all blue, all red, etc.)
void GenerateImageRange( const COLORS color )
{
	cv::Mat mat( IMGWIDTH, IMGHEIGHT, CV_8UC3, cv::Scalar( 0, 0, 0 ) );  

	const int MINIMUMCOLORVALUE = 80;

	for( int i = MINIMUMCOLORVALUE; i < 255; i += 2 )
	{
		switch( color )
		{
			case RED:
				mat = cv::Mat( IMGWIDTH, IMGHEIGHT, CV_8UC3, cv::Scalar( 0, 0, i ) );   
#ifdef DEBUG
				DisplayImage( "Red Image", mat );
#endif
				break;

			case GREEN:
				mat = cv::Mat( IMGWIDTH, IMGHEIGHT, CV_8UC3, cv::Scalar( 0, i, 0 ) );
#ifdef DEBUG
				DisplayImage( "Green Image", mat );
#endif
				break;

			case BLUE:
				mat = cv::Mat( IMGWIDTH, IMGHEIGHT, CV_8UC3, cv::Scalar( i, 0, 0 ) );
#ifdef DEBUG
				DisplayImage( "Blue Image", mat );
#endif
				break;
			default:
				std::cerr << "Error: Color is not supported!" << std::endl;
				break;
		}
	}
}

// Function to generate an image set.  For now, only Red, Green, and Blue images can be generated   
void CreateImageSet( const COLORS color )
{
	switch ( color )
	{

		case RED:
			std::cerr << "Generating RED images." << std::endl;
			GenerateImageRange( RED );
			break; 

		case GREEN:
			std::cerr << "Generating GREEN images." << std::endl;
			GenerateImageRange( GREEN );
			break;
			
		case BLUE:
			std::cerr << "Generating BLUE images." << std::endl; 
			GenerateImageRange( BLUE );
			break;

		default:
			std::cerr << "Non existent color!" << std::endl;
			break;
	}
}

// Function to display an image:
void DisplayImage( const std::string& imageName, const cv::Mat& image )
{
	cv::imshow( imageName, image ); 
	cv::waitKey( 0 );
}

// Main function:
int main( int argc, char **argv )
{
	// Generate the folders to store test images:
	if( GenerateFolderStructure() != 0 )
	{
		std::cerr << "ERROR: Could not generate image folders!" << std::endl;
		return -1;
	}

	// Generate a color (BGR format)
	//cv::Mat image = GenerateImage(100, 0, 0);
	//DisplayImage( "Blue Image", image );

	CreateImageSet( RED );

	return 0;
}
