#include <iostream>

class Figure {
	int a, b, c, d; // размер сторон треугольника
	int A, B, C, D; // градус углов
	std::string name;
protected:
	Figure(int aa, int bb, int cc, int dd, int AA, int BB, int CC, int DD) : a(aa), b(bb), c(cc), d(dd), A(AA), B(BB), C(CC), D(DD) {}
public:

	Figure() :Figure(0, 0, 0, 0, 0, 0, 0, 0) {}
	std::string get_name() { return name; }
	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return c; }
	int get_d() { return d; }
	int get_A() { return A; }
	int get_B() { return B; }
	int get_C() { return C; }
	int get_D() { return D; }

};
class Triangle : public Figure {
public:
	Triangle(int aa, int bb, int cc, int AA, int BB, int CC) : Figure(aa, bb, cc, 0, AA, BB, CC, 0) {}
	Triangle() : Triangle(10, 20, 30, 50, 60, 70) {}

};
class Pryamoug_Triangle : public Figure {

public:
	Pryamoug_Triangle(int aa, int bb, int cc, int AA, int BB, int CC) :Figure(aa, bb, cc, 0, AA, BB, CC, 0) {}
	Pryamoug_Triangle() : Pryamoug_Triangle(10, 20, 30, 50, 60, 70) {}
};
class Ravnobed_Triangle : public Figure {

public:
	Ravnobed_Triangle(int aa, int bb, int cc, int AA, int BB, int CC) :Figure(aa, bb, cc, 0, AA, BB, CC, 0) {}
	Ravnobed_Triangle() : Ravnobed_Triangle(10, 20, 10, 50, 60, 50) {}
};


class Paralelog : public Figure {
private:
	int a, b, c, d; //размер сторон
	int A, B, C, D; //градус углов		
protected:
	Paralelog(int aa, int bb, int cc, int dd, int AA, int BB, int CC, int DD) : a(aa), b(bb), c(cc), d(dd), A(AA), B(BB), C(CC), D(DD) {}

public:
	Paralelog() : Figure(20, 30, 20, 30, 30, 40, 30, 40) {}


};
class Quadrangle : public Figure {
public:
	Quadrangle() : Figure(10, 20, 30, 40, 50, 60, 70, 80) {}
};

class Romb : public Figure {

public:

	Romb() : Figure(30, 30, 30, 30, 30, 40, 30, 40) {}



};
class Quadro :public Figure {

public:
	Quadro() : Figure(20, 20, 20, 20, 90, 90, 90, 90) {}

};

void print_info(Figure* f) {
	std::cout << f->get_name();
	std::cout << "Стороны: a=" << f->get_a() << " b=" << f->get_b()
		<< " c=" << f->get_c() << " d=" << f->get_d() << "\n";
	std::cout << "Углы: A=" << f->get_A() << " B=" << f->get_B()
		<< " C=" << f->get_C() << " D=" << f->get_D() << "\n\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Triangle triangle;
	Paralelog paralelog;
	Quadrangle quadrangle;
	Romb romb;
	Pryamoug_Triangle pryamoug_triangle;
	Ravnobed_Triangle ravnobed_triangle;
	Quadro quadro;
	Figure figure;
	std::cout << "Треугольник: " << "\n";
	print_info(&triangle);
	std::cout << "\n";
	std::cout << "Паралелограмм: " << "\n";
	print_info(&paralelog);

	std::cout << "\n";
	std::cout << "Четырехугольник: " << "\n";

	print_info(&quadrangle);
	std::cout << "\n";
	std::cout << "Прямоугольный треугольник: " << "\n";
	print_info(&pryamoug_triangle);

	std::cout << "\n";
	std::cout << "Равнобедренный треугольник: " << "\n";

	print_info(&ravnobed_triangle);
	std::cout << "\n";
	std::cout << "Квадрат: " << "\n";
	print_info(&quadro);

}