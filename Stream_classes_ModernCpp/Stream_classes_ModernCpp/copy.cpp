#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std::filesystem;
void read_fstream() {
	std::ifstream input;
	input.open("test.txt");
	if (!input.is_open()) {
		std::cout << "Unable to open file for reading." << std::endl;
		return;
	}
	
	std::cout << "\n*******Read from file character by character*******" << std::endl;
	char ch{};
	while (!input.eof()) {
		input.get(ch);
		std::cout << ch;
	}

	/*
	* Below code doesn't print anything on stdout
	* As file pointer is pointing to eof because we 
	* already read the fine above.
	* 
	* SO what should we do to read from start?
	* ---Lets check
	*/
	std::cout << "\nCurrent file pointer:" << input.tellg() << std::endl;
	/*
	* If we previously get an end of file on the stream, 
	* seekg will not reset it but will return an error 
	* in many implementations. – use the clear() method
	* to clear the end of file bit first. 
	* -------------------------------------------------------------------------------
	* This is a relatively common mistake and if seekg() is not performing as expected.
	*/
	//input.seekg(0, input.beg); // This will not works alone 
	input.clear();
	input.seekg(0,input.beg);
	std::cout << "\nNew file pointer:" << input.tellg() << std::endl;
	std::cout << "\n*******Read from file line by line*******" << std::endl;
	std::string line{};
	while (!std::getline(input,line).eof()) {
		std::cout << line << std::endl;
	}
	input.close();
}

void write_fstream() {
	std::ofstream output;
	output.open("test.txt",std::ios::app);
	if (!output.is_open()) {
		std::cout << "Unable to open a file for writing." << std::endl;
		return;
	}
	std::cout << "\nwrite into file character by character" << std::endl;
	output.seekp(output.end);
	std::string message{"wrting message into the file."};
	for (const char& ch : message) {
		output.put(ch);//output << ch; this will not put the charaters in new line
	}
	output << "\n";
	output.close();
}

int read_write_filesystem() {
	path source{current_path()};
	source /= "source.cpp";

	path dest{current_path()};
	dest /= "copy.cpp";

	std::ifstream input{ source };
	if (!input.is_open()) {
		std::cout << source << " file not found " << std::endl;
		return -1;
	}
	
	std::ofstream output{dest};
	if (!input.is_open()) {
		std::cout << dest << " file not found " << std::endl;
		return -1;
	}

	//read the file line by line
	std::string line{};
	while (!std::getline(input,line).eof())
	{
		output << line << std::endl;
	}
	std::cout << "Successfully copied source file." << std::endl;
	input.close();
	output.close();
	return 0;
}

int main() {
	read_write_filesystem();
	read_fstream();
	write_fstream();
	return 0;
