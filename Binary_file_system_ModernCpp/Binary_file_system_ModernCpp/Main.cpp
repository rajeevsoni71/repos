#include "data.h"

int main() {
	std::string str{ "data.dat" };
	DATA data;
	data.Age = 27;
	std::string n = "Rajeev Soni";
	std::string c = "Complete Modern C++11/14/17";
	strcpy_s(data.Name,sizeof(n)+1,n.c_str());
	strcpy_s(data.Course_Enrolled,sizeof(c)+1,c.c_str());
	/*data.Name = { "Rajeev Soni" };
	data.Course_Enrolled = { "Complete Modern C++11/14/17" };*/

	std::cout << "Create a image file" << std::endl;
	RETURN_STATUS create_ret = createImage(str);
	std::cout << "Create ret:" << print(create_ret) << std::endl;

	std::cout << "wrting the data into the image file" << std::endl;
	RETURN_STATUS write_ret = write_data(&data,str);
	std::cout << "write_ret:" << print(write_ret) << std::endl;
	DATA data2;
	std::cout << "Read the data from the image file" << std::endl;
	RETURN_STATUS read_ret = read_data(data2, str);
	std::cout << "read_ret:" << print(read_ret) << std::endl;
	Display(data2); ///-----------Here it doesn't have any value.
	return 0;
}