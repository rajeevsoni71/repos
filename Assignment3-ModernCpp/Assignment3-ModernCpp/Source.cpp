#include <iostream>

int main() {
	//Try to modify x1 & x2 and see the compilation output
	const int MAX = 12;
	int x = 5;
	int& ref_x1 = x;
	const int& ref_x2 = x;

	//Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
	const int* ptr1 = &x; //pointer to integer constant,value cannot be changed
	int* const ptr2 = &x; // constant pointer to integer, Address cannot be changed
	const int* const ptr3 = &x; // constant pointer to integer constant, Both Value and Addresss can't be chnaged.

	//Find which declarations are valid. If invalid, correct the declaration
	const int* ptr3 = &MAX;
	const int* ptr4 = &MAX;// you cannot point the const value using without const pointer, Added cosnt before DATATYPE

	const int& r1 = ref_x1;
	const int& r2 = ref_x2;// you cannot reference a constant reference, so added const before DATATYPE

	const int*& p_ref1 = ptr1; // you cannot reference a pointer to constant until the reference is constant, so Added const before DATATYPE
	int* const& p_ref2 = ptr2; // you cannot create a reference of constant pointer until the reference itself is constant reference(not reference to constant)
	// remove the const from the beginning and added in B/W * and & to make the reference as a constant reference.
	return 0;
}