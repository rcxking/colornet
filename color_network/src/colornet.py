#!/usr/bin/python

'''
colornet.py 

This is a Python Neural Network that learns how to recognize red, green,
and blue images.  Training and validation images are created by the
image_generator C++ program two levels up.

Bryant Pong
1/26/16  
'''

# Libraries:
import numpy as np
import theano
import theano.tensor as T
import lasagne
import cPickle as pickle # Faster version of pickle

# Locations of the training/validation images:      
IMAGEPATH = "../../image_generator/src/images/"
TRAININGIMAGES = IMAGEPATH+"training_images"
VALIDATIONIMAGES = IMAGEPATH+"test_images"

# Convert the training images into a list of flattened image arrays:
 

# Create and train the neural network on red, green, and blue images
def CreateAndTrainNetwork():
	pass

# Display the menu of options to the user:
def DisplayMenu():
	print( "Welcome to the Color Neural Network!" )	 

	userIn = str( raw_input( "Please enter your selection: " ) ) 	

	while userIn != "q":
		pass

	print( "Goodbye!" )

# Main function:
def main():
	DisplayMenu()

if __name__ == "__main__":
	main()
