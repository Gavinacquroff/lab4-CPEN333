//	A Win32 C program to demonstrate the creation and use of named Pipes. Error checking has 
//	been ommitted to aid clarity

#include	<stdio.h>
#include	"..\..\rt.h"			// change the pathlist to rt.h to suit location on your disk

struct		example {		// structure template for some data that we intend to write to the pipeline
	int 	x ;
	float 	y ;
} ;

// Some data to be written in to the pipeline. Note how arrays are explicitly sized

int 	i;									// a simple int
uint8_t b;
int 	array1[10];

char	name[15];
struct	 example mystruct;

int	main()
{
	printf("Parent Process Creating the Pipelines.....\n") ;

	CPipe pipe1("MyPipe1", 1024);
	CPipe pipe2("MyPipe2", 1024);
	CPipe pipe3("MyPipe3", 1024);
	CPipe pipe4("MyPipe4", 1024);

	printf("Parent Process Creating Child Process to Read from Pipeline.....\n") ;

	CProcess child1_b("C:\\RTExamples\\Q7 - InterProcessCommnicationsUsingPipelines\\Q7Child1_b\\debug\\Q7Child1_b.exe", // pathlist to child program executable				
			NORMAL_PRIORITY_CLASS,			// priority
			OWN_WINDOW,						// process has its own window					
			ACTIVE							// process is active immediately
	) ;
	CProcess child2_b("C:\\RTExamples\\Q7 - InterProcessCommnicationsUsingPipelines\\Q7Child2_b\\debug\\Q7Child2_b.exe",	// pathlist to child program executable				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);
	CProcess child3("C:\\RTExamples\\Q7 - InterProcessCommnicationsUsingPipelines\\Q7Child3\\debug\\Q7Child3.exe",	// pathlist to child program executable				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);
	CProcess child4("C:\\RTExamples\\Q7 - InterProcessCommnicationsUsingPipelines\\Q7Child4\\debug\\Q7Child4.exe",	// pathlist to child program executable				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);

	pipe1.Read(&i, sizeof(i));
	printf("pipe 1 contained integer = %d\n", i);
	
	pipe1.Read(&name, sizeof(name));
	printf("%s\n", name);

	pipe2.Read(&i, sizeof(i));
	printf("pipe 2 contained integer = %d\n", i);
	
	pipe2.Read(&name, sizeof(name));
	printf("%s\n", name);

	pipe3.Read(&i, sizeof(i));
	printf("pipe 3 contained integer = %d\n", i);

	pipe3.Read(&name, sizeof(name));
	printf("%s\n", name);

	pipe4.Read(&i, sizeof(i));
	printf("pipe 4 contained integer = %d\n", i);

	pipe4.Read(&name, sizeof(name));
	printf("%s\n\n", name);

	printf("press return to exit");
	getchar();

	//need to let children terminate first
	child1_b.WaitForProcess();
	child2_b.WaitForProcess();
	child3.WaitForProcess();
	child4.WaitForProcess();

	return 0 ;
}	
