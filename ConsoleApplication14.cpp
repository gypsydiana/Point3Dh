#include <iostream>
#include <vector>
using namespace std;
class base {
public:
	virtual void show() {};
};
template <class T> class Point2D {
protected:
	T x,y;
public:
	Point2D(T x,T y) {
		this->x = x;
		this->y = y;
	};
};
template <class T> class Z {
protected:
	T z;
public:
	Z(T z) {
		this->z = z;
	};
};
template <class T> class H {
protected:
	T h;
public:
	H(T h) {
		this->h = h;
	};
};
template <class T> class Point3Dh :public Point2D<T>, public Z<T>, public H<T>,base {
private:
	int number;
public:
	Point3Dh(T x, T y, T z,T h) : Point2D <T>(x, y), Z <T>(z), H <T>(h){
		number = 0;
		if (h == 0) {
			number = 1;
		}
	};
	void show() {
		setlocale(LC_ALL, "Russian");
		if (number == 0) {
			cout << "(" << this->x / this->h << ", " << this->y / this->h << ", " << this->z / this->h << ")" << endl;
			
		}
		else {
			cout << "4 координата не должна равняться 0!" << endl;
		}
	};
};
int main() {
	setlocale(LC_ALL, "Russian");
	cout << "_______________________" << endl;
	cout << "                       |" << endl;
	cout << "                       |" << endl;
	cout << " Однородные координаты |" << endl;
	cout << "                       |" << endl;
	cout << "_______________________|" << endl;
	cout << "Точка 1: (x=6, y=6, z=6, h=6)" << endl;
	cout << "Точка 2: (x=1.5, y=2.2, z=3.1, h=4.6)" << endl;
	cout << "Точка 3: (x=10.2, y=3.4, z=5.5, h=0)" << endl;
	system("pause");
	system("cls");
	cout << "_______________________" << endl;
	cout << "                       |" << endl;
	cout << "                       |" << endl;
	cout << " Реальные координаты   |" << endl;
	cout << "                       |" << endl;
	cout << "_______________________|" << endl;
	Point3Dh <int> p1(6,6,6,6);
	p1.show();
	Point3Dh <double> p2(1.5, 2.2, 3.1,4.6); 
	p2.show();
	Point3Dh <float> p3(10.2, 3.4, 5.5, 0);
	p3.show();
	system("pause");
	system("cls");
	cout << "Работа с вектором" << endl;
	vector<base*> v;
	v.push_back((base*)&p1);
	v.push_back((base*)&p2);
	v.push_back((base*)&p3);
	for (int i = 0; i < v.size(); i++) {
		cout << i + 1 << " - ";
		v[i]->show();
	}
	system("pause");
	system("cls");
}