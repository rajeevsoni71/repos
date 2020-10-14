#include <iostream>
/*
* suppose you want a make a printer interface
* that can
* print
* scan
* fax
*/
struct Document;

//struct IMachine {
//	virtual void print(Document& doc) = 0;
//	virtual void scan(Document& doc) = 0;
//	virtual void fax(Document& doc) = 0;
//};
////MFP-> Multi Funtion Printer
//struct MFP : IMachine {
//	// Inherited via IMachine
//	virtual void print(Document& doc) override
//	{
//		std::cout << "Document printed.." << std::endl;
//	}
//	virtual void scan(Document& doc) override
//	{
//		std::cout << "Document scanned.." << std::endl;
//	}
//	virtual void fax(Document& doc) override
//	{
//		std::cout << "Document faxed.." << std::endl;
//	}
//};
//
//
///*
//* So Now what if you just have to make a machine that
//* does only print job.
//* or does only scan job.
//* or does only fax job.
//* example suppose we are making a scanner
//*/
//struct Scanner :IMachine {
//	// Inherited via IMachine
//	virtual void print(Document& doc) override
//	{
//		//but here what we will do scanner can;t do print?
//	}
//	virtual void scan(Document& doc) override
//	{
//		//only this fucntion is actually implemented 
//		//other function just didnlt do anything 
//	}
//	virtual void fax(Document& doc) override
//	{
//		//same for fax as well.
//	}
//};

/*
* So intead of this approach
* you can segregate the one interface into multiple interfaces
*/
struct IPrinter {
	virtual void print(Document& doc) = 0;
};
struct IScanner {
	virtual void scan(Document& doc) = 0;
};
struct IFax {
	virtual void fax(Document& doc) = 0;
};
int main() {

}