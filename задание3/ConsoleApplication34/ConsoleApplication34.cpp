#include <iostream>

class Figure {
protected:
    int sides_count;
    std::string name;

public:
    Figure() : sides_count(0), name("Фигура") {}

    virtual bool check() {
        return sides_count == 0;
    }

    virtual void print_info() {
        std::cout << name << ":\n";
        std::cout << (check() ? "Правильная" : "Неправильная") << "\n";
        std::cout << "Количество сторон: " << sides_count << "\n\n";
    }
};

class Triangle : public Figure {
protected:
    int a, b, c;
    int A, B, C;

public:
    Triangle(int aa, int bb, int cc, int AA, int BB, int CC)
        : a(aa), b(bb), c(cc), A(AA), B(BB), C(CC) {
        sides_count = 3;
        name = "Треугольник";
    }

    Triangle() : Triangle(10, 20, 30, 50, 60, 70) {}

    bool check() override {
        return (A + B + C == 180);
    }

    void print_info() override {
        std::cout << name << ":\n";
        std::cout << (check() ? "Правильная" : "Неправильная") << "\n";
        std::cout << "Количество сторон: " << sides_count << "\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }
};

class Pryamoug_Triangle : public Triangle {
public:
    Pryamoug_Triangle(int aa, int bb, int cc, int AA, int BB)
        : Triangle(aa, bb, cc, AA, BB, 90) {
        name = "Прямоугольный треугольник";
    }

    Pryamoug_Triangle() : Pryamoug_Triangle(10, 20, 30, 50, 40) {}

    bool check() override {
        return Triangle::check() && (C == 90);
    }
};

class Ravnobed_Triangle : public Triangle {
public:
    Ravnobed_Triangle(int aa, int bb, int AA, int BB)
        : Triangle(aa, bb, aa, AA, BB, AA) {
        name = "Равнобедренный треугольник";
    }

    Ravnobed_Triangle() : Ravnobed_Triangle(10, 20, 50, 80) {}

    bool check() override {
        return Triangle::check() && (a == c) && (A == C);
    }
};

class Ravnostor_Triangle : public Triangle {
public:
    Ravnostor_Triangle(int side)
        : Triangle(side, side, side, 60, 60, 60) {
        name = "Равносторонний треугольник";
    }

    Ravnostor_Triangle() : Ravnostor_Triangle(30) {}

    bool check() override {
        return Triangle::check() && (a == b) && (b == c) &&
            (A == 60) && (B == 60) && (C == 60);
    }
};

class Quadrangle : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    Quadrangle(int aa, int bb, int cc, int dd, int AA, int BB, int CC, int DD)
        : a(aa), b(bb), c(cc), d(dd), A(AA), B(BB), C(CC), D(DD) {
        sides_count = 4;
        name = "Четырёхугольник";
    }

    Quadrangle() : Quadrangle(10, 20, 30, 40, 50, 60, 70, 80) {}

    bool check() override {
        return (A + B + C + D == 360);
    }

    void print_info() override {
        std::cout << name << ":\n";
        std::cout << (check() ? "Правильная" : "Неправильная") << "\n";
        std::cout << "Количество сторон: " << sides_count << "\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};

class Rectangle : public Quadrangle {
public:
    Rectangle(int aa, int bb)
        : Quadrangle(aa, bb, aa, bb, 90, 90, 90, 90) {
        name = "Прямоугольник";
    }

    Rectangle() : Rectangle(10, 20) {}

    bool check() override {
        return Quadrangle::check() && (a == c) && (b == d) &&
            (A == 90) && (B == 90) && (C == 90) && (D == 90);
    }
};

class Square : public Rectangle {
public:
    Square(int side)
        : Rectangle(side, side) {
        name = "Квадрат";
    }

    Square() : Square(20) {}

    bool check() override {
        return Rectangle::check() && (a == b) && (b == c) && (c == d);
    }
};

class Paralelog : public Quadrangle {
public:
    Paralelog(int aa, int bb, int AA, int BB)
        : Quadrangle(aa, bb, aa, bb, AA, BB, AA, BB) {
        name = "Параллелограмм";
    }

    Paralelog() : Paralelog(20, 30, 30, 40) {}

    bool check() override {
        return Quadrangle::check() && (a == c) && (b == d) &&
            (A == C) && (B == D);
    }
};

class Romb : public Paralelog {
public:
    Romb(int side, int AA, int BB)
        : Paralelog(side, side, AA, BB) {
        name = "Ромб";
    }

    Romb() : Romb(30, 30, 40) {}

    bool check() override {
        return Paralelog::check() && (a == b) && (b == c) && (c == d);
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Figure figure;
    Triangle triangle;
    Pryamoug_Triangle pryamoug_triangle;
    Ravnobed_Triangle ravnobed_triangle;
    Ravnostor_Triangle ravnostor_triangle;
    Quadrangle quadrangle;
    Rectangle rectangle;
    Square square;
    Paralelog paralelog;
    Romb romb;

    figure.print_info();
    triangle.print_info();
    pryamoug_triangle.print_info();
    ravnobed_triangle.print_info();
    ravnostor_triangle.print_info();
    quadrangle.print_info();
    rectangle.print_info();
    square.print_info();
    paralelog.print_info();
    romb.print_info();

    return 0;
}