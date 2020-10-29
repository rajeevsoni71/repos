#include <iostream>

class Rectangle{
protected:
	int width{}, heigth{};
public:
	Rectangle() = default;
	Rectangle(int w,int h) 
		:width{w}, heigth{h}
	{}
	virtual void setWidth(int w) {
		width = w;
	}
	virtual void setHeight(int h) {
		heigth = h;
	}
	int getWidth()const { return width; }
	int getHeight()const { return heigth; }

	int area() const { return width * heigth; }
};

//suppose 1
//Now suppose we have a method which will process the
//Rectabgle class.
void Process(Rectangle& rec) {
	//only applicable for voilation of substitution principle
	int w = rec.getWidth(); // w will be sise of square
	rec.setHeight(20); // now we set the both width and height of square

	//here there is a problem and that is 
	//w still has old value but rectangle class width and height are chnaged to 20
	std::cout << "Expected area of Rectangle: " << (w*20)
		<< " , actually: " << rec.area()
		<< std::endl;
}

//suppose 2
// lets suppose we need to create a square
// using the class Rectangle.

class Square :public Rectangle {
public:
	Square() = default;
	Square(int size) : Rectangle{size,size} {}
	void setWidth(int w) override {
		this->width = this->heigth = w;
	}
	void setHeight(int h) override {
		this->width = this->heigth = h;
	}
};

//Now after implementing the square class
// we have a problem basically we are voilating the
//substitution principle means that
//when ever any function parameter is passing by base class object
//then we can pass derived class object as well there wouldn't be a
// problem but in the Process function that principle is got voilated

int main() {
	Rectangle r(3,4);
	Process(r);
	Square sq(10);
	Process(sq);
	//Finally the out put for square are different as over
	// design is incorrect for substitution principle.
	return 0;
}