#include <stdio.h> 

// Alignment requirements 
// (typical 32 bit machine) 

// char         1 byte 
// short int    2 bytes 
// int          4 bytes 
// double       8 bytes 

namespace st {
	// structure A 
	typedef struct structa_tag
	{
		char        c;
		short int   s;
	} structa_t;

	// structure B 
	typedef struct structb_tag
	{
		short int   s;
		char        c;
		int         i;
	} structb_t;

	// structure C 
	typedef struct structc_tag
	{
		char        c;
		double      d;
		int         s;
	} structc_t;

	// structure D 
	typedef struct structd_tag
	{
		double      d;
		int         s;
		char        c;
	} structd_t;

	// structure E 
	typedef struct structe_tag
	{
		int         s;
		char        c;
		double      d;
	} structe_t;
};

namespace cl {
	// class A 
	class classa
	{
		char        c;
		short int   s;
	};

	// class B 
	class classb
	{
		short int   s;
		char        c;
		int         i;
	};

	// class C 
	class classc
	{
		char        c;
		double      d;
		int         s;
	};

	// class D 
	class classd
	{
		double      d;
		int         s;
		char        c;
	};
};

int main()
{
	printf("sizeof(structa_t) = %d\n", sizeof(st::structa_t));//4
	printf("sizeof(structb_t) = %d\n", sizeof(st::structb_t));//8
	printf("sizeof(structc_t) = %d\n", sizeof(st::structc_t));//24
	printf("sizeof(structd_t) = %d\n", sizeof(st::structd_t));//16
	printf("sizeof(structe_t) = %d\n", sizeof(st::structe_t));//16
	printf("\n");
	printf("sizeof(classa) = %d\n", sizeof(cl::classa));//4
	printf("sizeof(classb) = %d\n", sizeof(cl::classb));//8
	printf("sizeof(classc) = %d\n", sizeof(cl::classc));//24
	printf("sizeof(classd) = %d\n", sizeof(cl::classd));//16

	//one d array
	int* arr = new int[5]; // right

	delete[] arr;

	//two d array
#define N 5
	int** arr1 = new int*[N]; // right
	for (int i = 0; i < N; i++) {
		arr1[i] = new int[N];
	}
	//deleting
	for (int i = 0; i < N; i++) {
		delete[] arr1[i];
	}

	delete[] arr1;
	return 0;
}
