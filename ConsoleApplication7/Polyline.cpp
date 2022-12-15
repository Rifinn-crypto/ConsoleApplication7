#include "Polyline.h"
#include <Windows.h>
#include "math.h"
#include <complex>


template<typename T>
Point<T>::Point(T key1, T key2)
{
	x = key1;
	y = key2;
}


template class PolyLine<int>;
template class PolyLine<float>;
template class PolyLine<double>;
template class PolyLine<std::complex<float>>;
template class PolyLine<std::complex<double>>;


template<typename T> inline
PolyLine<T>::PolyLine(const PolyLine<T>& p)
{
	arr = new Point<T>[p.vertex];
	vertex = p.vertex;
	for (size_t i = 0; i < vertex; i++)
	{
		arr[i] = p.arr[i];
	}
}


template<typename T>
PolyLine<T>::~PolyLine()
{
	delete[] arr;
	vertex = 0;
}


template<typename T>
Point<T>* PolyLine<T>::GetArr()
{
	return arr;
}

template<typename T> double PolyLine<T>::GetLenght() const
{
	if (arr == nullptr) throw  std::logic_error("Line is empty");
	double len = 0;
	for (size_t i = 0; i < vertex - 1; i++)
	{
		len += sqrt((pow(arr[i + 1].x - arr[i].x, 2) + (pow(arr[i + 1].y - arr[i].y, 2))));
	}
	return len;
}


template PolyLine<int> operator+= (PolyLine<int>& v1, const Point<int>& point);
template PolyLine<float> operator+= (PolyLine<float>& v1, const Point<float>& point);
template PolyLine<double> operator+= (PolyLine<double>& v1, const Point<double>& point);
template<typename T> PolyLine<T> operator+=(PolyLine<T>& polyline, const Point<T>& point)
{
	Point<T>* tmp = new Point<T>[++polyline.vertex];
	tmp[0] = point;
	for (size_t i = 1; i < polyline.vertex; i++)
	{
		tmp[i] = polyline.arr[i - 1];
	}
	if (polyline.arr != nullptr) delete[] polyline.arr;
	polyline.arr = tmp;
	return polyline;
}


template<typename T> inline
PolyLine<T> PolyLine<T>::operator+(const Point<T>& point)
{
	vertex += 1;
	Point<T>* tmp = new Point<T>[vertex];
	for (size_t i = 0; i < vertex - 1; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[vertex - 1] = point;
	if (arr != nullptr) delete[] arr;
	arr = tmp;
	return *this;
}


template<typename T> inline Point<T>& PolyLine<T>::operator [] (const size_t index)
{
	if (arr == nullptr)
		throw "Line is empty";
	if ((index >= vertex) || (index < 0)) throw "Invalid index";
	return arr[index];
}


template<typename T> inline Point<T> PolyLine<T>::operator [] (const size_t index) const
{
	if (arr == nullptr) throw "Line is empty";
	if ((index >= vertex) || (index < 0)) throw "Invalid index";
	return arr[index];
}


template<typename T>  PolyLine<T> PolyLine<T>::operator + (const PolyLine<T>& polyline)
{
	if (!vertex)
		return polyline;
	if (!polyline.vertex)
		return *this;
	PolyLine<T> res(int(vertex + polyline.vertex));
	for (size_t i = 0; i < vertex; i++)
	{
		res.arr[i] = arr[i];
	}
	for (size_t i = 0; i < polyline.vertex; i++)
	{
		res.arr[vertex + i] = polyline.arr[i];
	}
	return res;
}

template<typename T> bool PolyLine<T>::operator == (const PolyLine<T>& polyline)
{
	if (vertex != polyline.vertex)
		return false;
	double eps = 0.001;
	for (size_t i = 0; i < vertex; i++)
	{
		if ((fabs(arr[i].x - polyline.arr[i].x) > eps) || (fabs(arr[i].y - polyline.arr[i].y) > eps))
			return false;
	}
	return true;
}


template<typename T> bool PolyLine<T>::operator != (const PolyLine<T>& polyline)
{
	if (vertex != polyline.vertex) return true;
	for (size_t i = 0; i < vertex; i++)
	{
		if ((arr[i].x != polyline.arr[i].x) || (arr[i].y != polyline.arr[i].y))
			return true;
	}
	return false;
}


template<typename T> PolyLine<T>& PolyLine<T>::operator = (const PolyLine<T>& polyline)
{
	if (this == (&polyline))
		return *this;
	if (arr)
		delete[] arr;
	if (polyline.arr)
	{
		arr = new Point<T>[polyline.vertex];
		vertex = polyline.vertex;
		for (size_t i = 0; i < polyline.vertex; i++)
		{
			arr[i] = polyline.arr[i];
		}
	}
	else
	{
		arr = NULL;
		vertex = 0;
	}
	return *this;
}

void MyDrawLine(int x1, int y1, int x2, int y2)
{
	POINT op;
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	SelectObject(hDC, GetStockObject(WHITE_PEN));

	MoveToEx(hDC, x1, y1, &op);
	LineTo(hDC, x2, y2);

	ReleaseDC(hWnd, hDC);

}




template std::ostream& operator<< (std::ostream& out, const PolyLine<int>& v1);
template std::ostream& operator<< (std::ostream& out, const PolyLine<float>& v1);
template std::ostream& operator<< (std::ostream& out, const PolyLine<double>& v1);
template<typename T> std::ostream& operator << (std::ostream& out, const PolyLine<T>& polyline)
{
	out << "Polyline <";
	if (!polyline.vertex)
	{
		out << " >";
		return out;
	}
	for (size_t i = 0; i < polyline.vertex; i++)
	{
		out << "vertex[" << i << "]: " << "(" << polyline.arr[i].x << "," << polyline.arr[i].y;
		if (i != polyline.vertex - 1) out << "); ";
		else out << ")";
	}
	out << ">";

	for (size_t i = 0; i < polyline.vertex - 1; i++)
	{
		MyDrawLine((int)polyline.arr[i].x, (int)polyline.arr[i].y,
			(int)polyline.arr[i + 1].x, (int)polyline.arr[i + 1].y);
	}
	return out;

}

template<typename V> 
PolyLine<std::complex<V>>::PolyLine(const PolyLine<std::complex<V>>& p)
{
	arr = new Point<std::complex<V>>[p.vertex];
	vertex = p.vertex;
	for (size_t i = 0; i < vertex; i++)
	{
		arr[i] = p.arr[i];
	}
}


template<typename V>
PolyLine<std::complex<V>>::PolyLine(int count)
{
	vertex = count;
	arr = new Point<std::complex<V>>[count];
	/*V a = 0, b = 0;
	for (size_t i = 0; i < vertex; i++)
	{
		std::cout << "Real part x: ";
		std::cin >> a;
		std::cout << "Image part x";
		std::cin >> b;
		Point<std::complex<V>> pp;
		pp.x = std::complex<V>(a, b);
		std::cout << "Real part y: ";
		std::cin >> a;
		std::cout << "Image part y";
		std::cin >> b;
		pp.y = std::complex<V>(a, b);
		arr[i] = pp;
	}*/
}


template<typename V>
PolyLine<std::complex<V>>::~PolyLine()
{
	delete[] arr;
	vertex = 0;
}


template<typename V>
PolyLine<std::complex<V>> PolyLine<std::complex<V>>::operator+(const Point<std::complex<V>>& point) {
	vertex += 1;
	Point<std::complex<V>>* tmp = new Point<std::complex<V>>[vertex];
	for (size_t i = 0; i < vertex - 1; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[vertex - 1] = point;
	if (arr != nullptr) delete[] arr;
	arr = tmp;
	return *this;
}



template std::ostream& operator<< (std::ostream& out, const PolyLine<std::complex<float>>& v1);
template std::ostream& operator<< (std::ostream& out, const PolyLine<std::complex<double>>& v1);
template<typename V> std::ostream& operator << (std::ostream& out, const PolyLine<std::complex<V>>& polyline)
{
	out << "Polyline <";
	for (size_t i = 0; i < polyline.vertex; i++)
	{
		out << "vertex[" << i << "]: " << "(" << polyline.arr[i].x << "," << polyline.arr[i].y;
		if (i != polyline.vertex - 1) out << "); ";
		else out << ")";
	}
	out << ">";
	return out;
}


template<typename V> Point<std::complex<V>>& PolyLine<std::complex<V>>::operator [] (const size_t index)
{
	if (arr == nullptr)
		throw "Line is empty";
	if ((index >= vertex) || (index < 0)) throw "Invalid index";
	return arr[index];
}


template<typename V> Point<std::complex<V>> PolyLine<std::complex<V>>::operator [] (const size_t index) const
{
	if (arr == nullptr) throw "Line is empty";
	if ((index >= vertex) || (index < 0)) throw "Invalid index";
	return arr[index];
}


template<typename V> PolyLine<std::complex<V>> PolyLine<std::complex<V>>::operator+ (const PolyLine<std::complex<V>>& polyline)
{
	if (!vertex)
		return polyline;
	if (!polyline.vertex)
		return *this;
	PolyLine<std::complex<V>> res(int(vertex + polyline.vertex));
	for (size_t i = 0; i < vertex; i++)
	{
		res.arr[i] = arr[i];
	}
	for (size_t i = 0; i < polyline.vertex; i++)
	{
		res.arr[vertex + i] = polyline.arr[i];
	}
	return res;
}


template<typename V> bool PolyLine<std::complex<V>>::operator == (const PolyLine<std::complex<V>>& polyline)
{
	if (vertex != polyline.vertex)
		return false;
	//double eps = 0.001;
	for (size_t i = 0; i < vertex; i++)
	{
		if ((arr[i].x != polyline.arr[i].x) || (arr[i].y != polyline.arr[i].y))
			return false;
	}
	return true;
}


template<typename V> bool PolyLine<std::complex<V>>::operator != (const PolyLine<std::complex<V>>& polyline)
{
	if (vertex != polyline.vertex) return true;
	for (size_t i = 0; i < vertex; i++)
	{
		if ((arr[i].x != polyline.arr[i].x) || (arr[i].y != polyline.arr[i].y))
			return true;
	}
	return false;
}



template<typename V> PolyLine<std::complex<V>>& PolyLine<std::complex<V>>::operator = (const PolyLine<std::complex<V>>& polyline)
{
	if (this == (&polyline))
		return *this;
	if (arr)
		delete[] arr;
	if (polyline.arr)
	{
		arr = new Point<std::complex<V>>[polyline.vertex];
		vertex = polyline.vertex;
		for (size_t i = 0; i < polyline.vertex; i++)
		{
			arr[i] = polyline.arr[i];
		}
	}
	else
	{
		arr = NULL;
		vertex = 0;
	}
	return *this;
}


template PolyLine<std::complex<float>> operator+= (PolyLine<std::complex<float>>& polyline, const Point<std::complex<float>>& point);
template PolyLine<std::complex<double>> operator+= (PolyLine<std::complex<double>>& polyline, const Point<std::complex<double>>& point);
template<typename V> PolyLine<std::complex<V>> operator+=(PolyLine<std::complex<V>>& polyline, const Point<std::complex<V>>& point)
{
	Point<std::complex<V>>* tmp = new Point<std::complex<V>>[++polyline.vertex];
	tmp[0] = point;
	for (size_t i = 1; i < polyline.vertex; i++)
	{
		tmp[i] = polyline.arr[i - 1];
	}
	if (polyline.arr != nullptr)
		delete[] polyline.arr;
	polyline.arr = tmp;
	return polyline;
}


template<typename V>
Point<std::complex<V>>* PolyLine<std::complex<V>>::GetArr()
{
	return arr;
}

template<typename V> double PolyLine<std::complex<V>>::GetLenght() const
{
	if (arr == nullptr) throw  std::logic_error("Line is empty");
	double len = 0;
	for (size_t i = 0; i < vertex - 1; i++)
	{
		//auto aa = (pow(arr[i + 1].x - arr[i].x, 2));
		auto result = sqrt((pow(arr[i + 1].x - arr[i].x, 2) + (pow(arr[i + 1].y - arr[i].y, 2))));
		len += sqrt(pow(result.real(), 2) + pow(result.imag(), 2));

	}
	return len;
}

