#include "data.h"

RETURN_STATUS createImage(const std::string& image) {
	RETURN_STATUS ret = STATUS::SUCCESS;
	DATA data;
	memset(&data, 0x00, sizeof(DATA));
	std::ofstream image_file(image, std::ios::out | std::ios::binary);
	if (!image_file) {
		ret = STATUS::FAILED_FILE_NOT_FOUND;
	}
	else {
		image_file.write(/*reinterpret_cast<const char*>*/(char*)(&data), sizeof(DATA));
		if (image_file.is_open()) {
			image_file.close();
		}
		if (!image_file.good()) {
			ret = STATUS::FAILED_TO_WRITE;
		}
	}
	return ret;
}

RETURN_STATUS write_data(const DATA* data, const std::string& image)
{
	RETURN_STATUS ret = STATUS::SUCCESS;
	std::ofstream image_file(image, std::ios::out | std::ios::binary);
	if (!image_file) {
		ret = STATUS::FAILED_FILE_NOT_FOUND;
	}
	else {
		image_file.write(/*reinterpret_cast<const char*>*/(char*)(data), sizeof(DATA));
		if (image_file.is_open()) {
			image_file.close();
		}
		if (!image_file.good()) {
			ret = STATUS::FAILED_TO_WRITE;
		}
	}
	return ret;
}

RETURN_STATUS read_data(DATA& data, const std::string& image) {
	RETURN_STATUS ret = STATUS::SUCCESS;
	std::ifstream image_file(image, std::ios::in | std::ios::binary);
	if (!image_file) {
		ret = STATUS::FAILED_FILE_NOT_FOUND;
	}
	else {
		image_file.read(/*reinterpret_cast<char*>*/(char*)(&data), sizeof(DATA));
		if (image_file.is_open()) {
			image_file.close();
		}
		if (!image_file.good()) {
			ret = STATUS::FAILED_TO_READ;
		}
	}
	//if (ret == STATUS::SUCCESS)
	//	Display(data);
	return ret;
}
void Display(const DATA& data) {
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "Name: " << data.Name << std::endl;
	std::cout << "Age: " << data.Age << std::endl;
	std::cout << "Course Enrolled: " << data.Course_Enrolled << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
}
