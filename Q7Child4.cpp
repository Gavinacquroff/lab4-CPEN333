//	A Win32 C program to demonstrate the creation and use of name pipe. Error checking has 
//	been ommitted to aid clarity

#include	<stdio.h>
#include	"..\..\rt.h"			// change the pathlist to rt.h to suit location on your disk

struct		example {		// structure template for some data that we intend to read from pipeline
	int 	x ;
	float 	y ;
} ;

// Some variables to hold the read from the pipeline.

int 	i = 4;				// a simple int
int 	array1[ 10 ]  ; 		// array of 10 integers

char	name[15 ] = "child 4 string" ;			// a string of 15 characters
struct	 example mystruct ;	// a structure with an int and a float in it

int	main()
{
	printf("Child Process Opening Pipeline.....\n");
	CPipe	pipe4("MyPipe4", 1024);		// Create a pipe 'p1' with the name "MyPipe"

	pipe4.Write(&i, sizeof(i));				// Read the int 'i' from the pipe
	printf("Child Process 4 wrote integer = %d into Pipeline 4.....\n", i);

	pipe4.Write(&name[0], sizeof(name));
	printf("Message from child 4 is: %s.....\n", name);

	//int 	x ;					// a temporary variable for use with the 'for' loop below

	//printf("Child Process Opening Pipeline.....\n") ;
	//CPipe	pipe2("MyPipe2", 1024) ;		// Create a pipe 'p1' with the name "MyPipe"
	//

	//pipe2.Read(&i, sizeof(i)) ;				// Read the int 'i' from the pipe
	//printf("Child Process read integer = %d from Pipeline.....\n", i) ;

	//pipe2.Read(&array1[0], sizeof(array1)) ;		// Read the array of integers' from the pipe

	//printf("Child Process read array = ") ;
	//for(x = 0; x < sizeof(array1)/sizeof(array1[0]) ; x ++)
	//	printf(" %d", array1[x]) ;

	//putchar('\n') ;

	//pipe2.Read(&name[0], sizeof(name)) ;	// Read the string from the pipe
	//printf("Child Process read string = %s, from Pipeline.....\n", name) ;	

	//pipe2.Read(&mystruct, sizeof(mystruct)) ;	// Read the structure from the pipeline
	//printf("Child Process read mystruct.x = %d, mystruct.y = %f from Pipeline.....\n", mystruct.x, mystruct.y) ;
	//	
	//


	//Sleep(4000) ;
	//
	return 0 ;

}	// pipe destructor called here to destroy p. Note however if pipeline still has unread data in it,
	// that data will be preserved
