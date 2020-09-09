#include <iostream>
//Including file system header
#include <filesystem>

using namespace std::filesystem;
int main() {
	path  p1{ R"(D:/books)"}; // Path clause doesn't check the existanc/validity of the path or even validate the path
	if (p1.has_filename()) {
		std::cout << p1.filename() << std::endl;
	}
	//To print individual component of the path  (range base for loop)
	for (const auto& x : p1) {
		std::cout << x << std::endl;
	}
	directory_iterator beg{ p1 };
	directory_iterator end{};

	while (beg != end) {
		if (beg->is_directory()) {
			//Enter the directory
			directory_iterator di{ beg->path() };
			directory_iterator fdi{};
			while (di != fdi) {
				std::cout << di->path() << std::endl;
				++di;
			}
		}
		std::cout << beg->path() << std::endl;
		++beg;
	}

	return 0;
}
