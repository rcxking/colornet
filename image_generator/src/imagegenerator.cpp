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
#include <sys/stat.h>
#include <sys/types.h>

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

// Function prototypes:
void GenerateFolderStructure(); 
cv::Mat GenerateImage( const int blue, const int green, const int red );  
void DisplayImage( const std::string& imageName, const cv::Mat& image );   

// Function to create folders to hold training and test images:
void GenerateFolderStructure()
{
	mkdir( TOPLEVELIMAGES.c_str(), 0777 );
	mkdir( (TOPLEVELIMAGES+"/"+TRAININGIMAGES).c_str(), 0777 );
	mkdir( (TOPLEVELIMAGES+"/"+TESTIMAGES).c_str(), 0777 );
}

// Function to generate an RGB image:
cv::Mat GenerateImage( const int blue, const int green, const int red )
{
	// Create a 128x128 3-channel image initialized to the rgb values
	// Remember that OpenCV stores colors as BGR rather than RGB. 
	return cv::Mat( IMGWIDTH, IMGHEIGHT, CV_8UC3, 
	       cv::Scalar( blue, green, red ) );
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
	//GenerateFolderStructure();

	cv::Mat image = GenerateImage(255, 0, 0);

	DisplayImage( "Blue Image", image );

	return 0;
}
