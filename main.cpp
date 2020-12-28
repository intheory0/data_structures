#include "btree.h"
#include "avltree.h"

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Shape
{
public:
    virtual double perimetr() = 0;
    virtual string name() = 0;
	virtual ~Shape();
};

class Square: public Shape
{
private:
    double a;
public:
    Square(double _a) { a = _a; }
    double perimetr() { return a * 4; }
    string name() { return "Square"; }
};

class Triangle: public Shape
{
private:
    double a, b, c;
public:
    Triangle(double _a, double _b, double _c)
    {
        a = _a;
        b = _b;
        c = _c;
    }
    double perimetr() { return a + b + c; }
	string name() { return "Triangle"; }
};

class Circle: public Shape
{
private:
	double r;
public:
	Circle(double _r) { r = _r; }
	double perimetr() { return 2 * M_PI * r; }
	string name() { return "Circle"; }
};

// инкапсуляция
// наследование
// полиморфизм

int main(int argc, char **argv)
{
    int n = 0;
	int maxl = 0;
    int maxr = 0;
    int minl = 0;
    int minr = 0;
    int hl = 0;
	int hr = 0;
	int x = 0;
	int y = 0;
	double s = 0;
    
	cin >> n;
	while (n--)
	{
        cin >> x >> y;
		
		if (y == 0)
		{
			if (x < 0)
			{
                if (x > maxl || maxl == 0)
                    maxl = x;
                if (x < minl)
                    minl = x;
            }
			else if (x > 0)
			{
                if (x > maxr)
                    maxr = x;
                if (x < minr || minr == 0)
                    minr = x;
            }
		}
		else
        {
            if (x < 0 && abs(y) > hl)
				hl = abs(y);
			else if (x > 0 && abs(y) > hr)
				hr = abs(y);
        }
	}

    s = (maxl - minl) * hl;
	if ((maxr - minr) * hr > s)
		s = (maxr - minr) * hr;
    if (s == 0)
        cout << "0.0";
	else
		cout << s / 2;

	/*BTree t;

	t.insert(10, t.root);
	t.insert(4, t.root);
	t.insert(16, t.root);
	t.insert(2, t.root);
	t.insert(7, t.root);
	t.insert(13, t.root);
	t.insert(9, t.root);

	t.walk_infix(t.root); // 2 4 7 9 10 13 16
	*/

	// string s = string::format("%ld %d %s\n", 1, 2, "hello");

	return 0;
}