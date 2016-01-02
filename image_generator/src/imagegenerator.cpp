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

// Constants:
const std::string TOPLEVELIMAGES = "images"; 
const std::string TRAININGIMAGES = "training_images";
const std::string TESTIMAGES = "test_images";   

// Function prototypes:
void GenerateFolderStructure(); 

// Function to create folders to hold training and test images:
void GenerateFolderStructure()
{
	mkdir( TOPLEVELIMAGES.c_str(), 0777 );
	mkdir( (TOPLEVELIMAGES+"/"+TRAININGIMAGES).c_str(), 0777 );
	mkdir( (TOPLEVELIMAGES+"/"+TESTIMAGES).c_str(), 0777 );
}

// Main function:
int main( int argc, char **argv )
{
	// Generate the folders to store test images:
	GenerateFolderStructure();

	return 0;
}
