# Paint Bucket
Most painting tools provide a function called Paint Bucket. Select a pixel in the image, and Paint Bucket will color the area around the pixel based on color similarity.  
Given an image in the format similar to a bitmap file, we want to color the area around a selected pixel with a specified color.

## How To Work
1. Compile paintBucket program.  
$ g++ paintBucket.cpp -o paintBucket -O3
2. Run the program.  
$ ./paintBucket [image.in] [x] [y] [color] [image*.out]  
  
	parameters:  
	1. image.in:   
	The input image file. This file has h+1 lines. The first line of this file contains two integers w and h, which specify the size of the image (w*h). In the following h lines, each line has w characters (from 0 to F), indicates the color of each pixel from the upper left corner to the bottom right corner on the image.
	2. x: &nbsp; An integer to specify the x-coordinate of the selected pixel. x = 0 means the leftmost column.  
	3. y: &nbsp; An integer to specify the y-coordinate of the selected pixel. y = 0 means the first (uppermost) row.  
	4. color: &nbsp; An character to indicate the color to fill. (0\~9 and A\~F).  
	5. image.out:  
	The program generate an output image file named [image.out] after the input image is colored. The output image file format has h+2 lines. The first h+1 lines are same as the input, which describe the information of the image after coloring. The last line report the number of connected components after coloring.
