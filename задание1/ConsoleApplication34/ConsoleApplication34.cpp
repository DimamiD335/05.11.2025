#include <iostream>
#include <string>

class Figure {
	int size;
	std::string name;

protected:
	Figure (int s, std::string n) : size(s), name(n){}
public:
	Figure() : Figure(0, "фигура") {}
	std::string get_name()
	{
		return name;
	}
	int get_size()
	{
		return size;
	}

};

class Triangle : public Figure
{
public:
	Triangle() : Figure (3, "треугольник") {}

};

class Quadrangle : public Figure {

public:
	Quadrangle() : Figure(4, "четырехугольник") {}


};


int main()
{
	setlocale(LC_ALL, "Russian");
	Figure figure;
	Triangle triangle;
	Quadrangle quadrengle;
	std::cout << "Имя фигуры :" << figure.get_name() << "     Кол-во углов: " << figure.get_size() << std::endl;
	std::cout << "Имя фигуры :" << triangle.get_name() << "     Кол-во углов: " << triangle.get_size() << std::endl;
	std::cout << "Имя фигуры :" << quadrengle.get_name() << "     Кол-во углов: " << quadrengle.get_size() << std::endl;


}