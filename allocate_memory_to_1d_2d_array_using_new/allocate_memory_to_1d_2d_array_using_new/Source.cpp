#include <iostream>

void Malloc() {
	/*
	Malloc wouldn't initialise the the pointer to 0.
	But calloc will do that.
	*/
	//int *p = (int*)calloc(5, sizeof(int));
	int* p = (int*)malloc(5 * sizeof(int));
	if (p == NULL) {
		printf("Failed to allocate memory\n");
		return;
	}
	*p = 5;
	printf("%d\n", *p);
	free(p);
	p = NULL;
	//free(p);
}
void New() {
	int* p = new int(5);
	*p = 6;
	std::cout << *p << std::endl;
	delete p;
	p = nullptr;
}

void OneD_Array() {
	//scope is limited to this block so no need to assign nullptr to pointer.
	int* ptr = new int[5];
	for (int i = 0; i < 5;i++) {
		ptr[i] = i;
	}
	std::cout << ptr[0] << std::endl;
	delete[]ptr;
}

void TwoD_Array() {
	int* p1 = new int[3];
	for (int i = 0; i < 3; i++) {
		p1[i] = i;
	}
	int* p2 = new int[3];
	for (int i = 0; i < 3; i++) {
		p2[i] = i;
	}
	int** data = new int* [2];
	data[0] = p1;
	data[1] = p2;
	std::cout << data[0][1] << std::endl;
	delete[]p1;
	delete[]p2;
	delete[]data;
}
void init_2d() {
	int data[2][3] = {
		1,2,3,
		4,5,6
	}; //1,2,3,4,5,6
	   //data[0][1]
}

int main() {
	Malloc();
	New();
	init_2d();
	OneD_Array();
	TwoD_Array();
	return 0;
}