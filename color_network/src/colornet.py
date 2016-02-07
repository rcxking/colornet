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
import os
import numpy as np
import theano
import theano.tensor as T
import lasagne
import cPickle as pickle # Faster version of pickle
import cv2

# Locations of the training/validation images:      
IMAGEPATH = "../../image_generator/src/images/"
TRAININGIMAGES = "training_images"
VALIDATIONIMAGES = "test_images"

IMAGEPATHS = [ TRAININGIMAGES, VALIDATIONIMAGES ]

# Colors recognized by the neural network.  These are the labels assocated 
# with each supported color.
UNKNOWN = -1
RED = 0
GREEN = 1
BLUE = 2

UNKNOWNSTRING = "unknown"
REDSTRING = "red"
GREENSTRING = "green"
BLUESTRING = "blue"

COLORVALUES = [ UNKNOWN, RED, GREEN, BLUE ]
COLORSTRINGS = [ UNKNOWNSTRING, REDSTRING, GREENSTRING, BLUESTRING ]

# Helper function to display an image:
def DisplayImage( imageName, imagePath ):
	img = cv2.imread( imagePath, cv2.IMREAD_COLOR )
	cv2.imshow( imageName, img )
	cv2.waitKey( 0 ) # Continue to display an image until a key is pressed
	cv2.destroyAllWindows()

# Helper function to determine the color of an image:
def DetermineImageColor( imagename ):
	
	# Iterate through the list of colors and determine if there is  
	# A color that matches:
	for colorstr in COLORSTRINGS:
		if imagename.find( colorstr ) != -1:
			return colorstr
			
	# If we get to this point, we haven't found a color.  Return unknown:
	return UNKNOWNSTRING    

# Convert the training images into a list of flattened image arrays:
def ConvertImagesToPickle():
	print( "Converting Image Files to Pickle Files" )

	for imagepath in IMAGEPATHS:
		print( "Now converting " + imagepath )  

		# Open this directory:
		for nextimage in os.listdir( IMAGEPATH+imagepath ):
			print( nextimage )	        

			# Open this image:
			fullimagepath = IMAGEPATH+imagepath+"/"+nextimage
			img = cv2.imread( fullimagepath, cv2.IMREAD_COLOR )

			# Determine the color of this image:
			imagecolor = DetermineImageColor( nextimage ) 

			if imagecolor != UNKNOWNSTRING:
				# We have a valid color:
				print( "Image " + nextimage + " is of color: " + str( imagecolor ) )					
			else:
				print( "ERROR: " + nextimage + " has an unknown color!" )
				continue
					

	print( "Conversions Complete" )

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
	ConvertImagesToPickle()
	#main()
