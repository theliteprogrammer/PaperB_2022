# CSC01B1 ST2 - 7 October 2022

## Stochasticity

- The University of Johannesburg needs you to create a data structure called UJImage containing a dynamic two-dimensional array of structures representing pixels (picture elements). A single pixel for a colour image is defined as follows:

## Field and Details
- red : An integer in the range [0, 255] representing the red colour component of the pixel.

- green : An integer in the range [0, 255] representing the green colour component of the pixel.

- blue  : An integer in the range [0, 255] representing the blue colour    component of the pixel.

- seeds : A fixed-length integer array of length 5, where each integer in the array represents a random number generator seed value.

- When the image is created, every pixel’s colour components (RGB) must be set to 0, and the seed values for each pixel must be read from a text file. When the image is drawn, the pixels must be updated as follows:

- The value of each pixel’s colour component (red, green and blue)must be set to r - c, where r is the pixel’s row coordinate and c the column coordinate.

- In cases where r - c < 0, the colour component being modified must be set to 0.

## You have also been provided with the following in order to assist you in developing the system to the UJ standards.

- main.cpp file [(](https://www.dropbox.com/sh/4jt63exvdp1unaj/AADPRFUjuUjBsOTdCwR7ntzwa?dl=0)[download](https://www.dropbox.com/sh/4jt63exvdp1unaj/AADPRFUjuUjBsOTdCwR7ntzwa?dl=0)[)](https://www.dropbox.com/sh/4jt63exvdp1unaj/AADPRFUjuUjBsOTdCwR7ntzwa?dl=0), which shows how the class is expected to be used. You are allowed to create your own main.cpp (or modify the provided one) if you want to do so. The main.cpp will not be automatically created by the VPL system.

- An init.txt file [(](https://www.dropbox.com/sh/4jt63exvdp1unaj/AADPRFUjuUjBsOTdCwR7ntzwa?dl=0)[download](https://www.dropbox.com/sh/4jt63exvdp1unaj/AADPRFUjuUjBsOTdCwR7ntzwa?dl=0)[)](https://www.dropbox.com/sh/4jt63exvdp1unaj/AADPRFUjuUjBsOTdCwR7ntzwa?dl=0)[ ](https://www.dropbox.com/sh/4jt63exvdp1unaj/AADPRFUjuUjBsOTdCwR7ntzwa?dl=0)containing the information necessary to initialise an image. The init.txtfile will be automatically created by the VPL system every time you click run.

- If you want to test your output to look exactly like the one shown on the question paper, you can [download](https://www.dropbox.com/sh/4jt63exvdp1unaj/AADPRFUjuUjBsOTdCwR7ntzwa?dl=0)[ ](https://www.dropbox.com/sh/4jt63exvdp1unaj/AADPRFUjuUjBsOTdCwR7ntzwa?dl=0)a larger init\_large.txt file. However, you may only use the larger file on CodeBlocks, not on the VPL.

- A bonus.exe file [(](https://www.dropbox.com/sh/4jt63exvdp1unaj/AADPRFUjuUjBsOTdCwR7ntzwa?dl=0)[download](https://www.dropbox.com/sh/4jt63exvdp1unaj/AADPRFUjuUjBsOTdCwR7ntzwa?dl=0)[)](https://www.dropbox.com/sh/4jt63exvdp1unaj/AADPRFUjuUjBsOTdCwR7ntzwa?dl=0)[ ](https://www.dropbox.com/sh/4jt63exvdp1unaj/AADPRFUjuUjBsOTdCwR7ntzwa?dl=0)which expects to load and execute a function from a file called bonus.dllwhich contains the following C function with name mangling disabled: void bonus();

- On the first line, init.txt contains ROWS COLS STOCHASTIC indicating the rows   and columns of the image, and a ‘Y’ or ‘N’ indicating if the image is stochastic (‘Y’ means yes, and ‘N’ means no). The rest of the file contains the seed values for each pixel and is structured as follows:

## Note: Although there are 120 marks available the maximum mark which can be achieved is 100

# CSC01B1 ST2 - 7 October 2022

- ROW COL SEED\_VAL0 SEED\_VAL1 … SEED\_VALN where ROWis an integer representing the row coordinate of the pixel, COL is an integer representing the column coordinate of the pixel, and SEED\_VALN is the n-th seed value of the pixel. Not all the pixels have the same number of seed values. Therefore, when reading the file, be mindful of the fact that not all the lines will have the same number of values. If a specific pixel has less than 5 seed values, the rest of the integer array must be filled with zeroes (0).

# In order to meet the requirements of this task, the project manager has broken the overall problem into several sub-tasks (see accompanying mark sheet for more details):

## T0 – Design: 

- You must create a UML 2.0 Class Diagram according to the requirements of the other tasks. It must be saved in a PDF file.

### T1 – Class Basics: 

- You must create a class to represent the UJImage. The class must make use of the principles of good design known to you. It must additionally make use of a dynamic two-dimensional array of structures in which to store the pixel data. The UJImage class must use its default constructor to read the file in order to obtain the rows, columns, stochasticity and the seed values of all the pixels. The colour components (red, green and blue) of the pixels must be initialised to 0.

### T2 – 

- The UJImage class has a Renderer,which implements the draw non-value returning (void)member function that will set the pixel attributes of the UJImage according to the instructions given above. The UJImage delegates its own drawmethod to the contained Renderer. The UJImage class must manage the life cycle of the Rendererobject.

### T3 – 

- Modify the previously created classes to use an inheritance hierarchy with polymorphism as follows:

- A Rendereris an abstract base class containing the following: 
   
- A position represented as row and column coordinates, which must both be initialised using a constructor during creation.

- A non-value returning pure virtual function called draw.

- A StochasticRendereris a kind of Renderer, and it contains the following:

- A chance, which is an integer in the range [0, 100] set during creation via a constructor.

- Overrides the drawfunction to perform the drawing method described previously. For every pixel, it must generate a random number between 0 and 100. If the number is less than or equal to the chance, the pixel must be drawn onto the image. Otherwise, a black pixel must be drawn. The seed value of the random number generator is the sum of the seed values of the pixel.

# Note: Although there are 120 marks available the maximum mark which can be achieved is 100

# CSC01B1 ST2 - 7 October 2022

- A ContinuousRenderer is a kind of Renderer,and it contains the following:

- A maximum intensity, which is an integer set during creation via a constructor.

- Overrides the drawfunction to perform the drawing method described previously. For each pixel, it must check if all its colour components (red, green and blue) are less than the maximum intensity before the pixel can be drawn onto the image.

### T4 – Add the following to your UJImage class:

- An overloaded assignment operator (=) which performs a deep copy of the underlying array.

- Support for using the stream insertion operator (<<) for output to display the grid:
   
- Creates a P3 PPM string and inserts it into the stream.

- Support for the pre-increment operator (++), which loops through the array of pixels and adds 1 to the colour components (red, green and blue) of each pixel.

### T5

- Define a UJPixel structure as per the given table with alignment padding disabled.

- Add a member function to the UJImage class which will load the information from the provided text file. This function must be called by the UJImage default constructor in order to initialise the 2D array using the information from the file.

# Note: Although there are 120 marks available the maximum mark which can be achieved is 100

# CSC01B1 ST2 - 7 October 2022

- Add a member function to UJImage,which will save all the pixels to a binary file of records.

- In all cases the functions will take the name of the file as a parameter and close the file when finished.

- Additionally, you have been provided with a main.cppfile, which demonstrates the functionality of the class.

# Image Output

![](bin/Debug/image.ppm)