#include "Polyline.h"
#include <Windows.h>
#include "math.h"
#include <complex>
#include<vector>



template<typename T>
Point<T>::Point(T key1, T key2)
{
	x = key1;
	y = key2;
}


template class PolyLine<int>;
template class PolyLine<float>;
template class PolyLine<double>;
//template class PolyLine<std::complex<float>>;
//template class PolyLine<std::complex<double>>;


//template<typename T> inline
//PolyLine<T>::PolyLine(const PolyLine<T>& p)
//{
//	data = new std::vector<Point<T>>[p.vertex];
//	vertex = p.vertex;
//	for (size_t i = 0; i < vertex; i++)
//	{
//		data[i] = p.data[i];
//	}
//}


//template<typename T>
//PolyLine<T>::~PolyLine()
//{
//	delete[] data;
//	vertex = 0;
//}


template<typename T>
std::vector<Point<T>> PolyLine<T>::GetArr()
{
	return data;
}

template<typename T> double PolyLine<T>::GetLenght() const
{
	if (data == nullptr) throw  std::logic_error("Line is empty");
	double len = 0;
	for (size_t i = 0; i < vertex - 1; i++)
	{
		len += sqrt((pow(data[i + 1].x - data[i].x, 2) + (pow(data[i + 1].y - data[i].y, 2))));
	}
	return len;
}


template PolyLine<int> operator+= (PolyLine<int>& v1, const Point<int>& point);
template PolyLine<float> operator+= (PolyLine<float>& v1, const Point<float>& point);
template PolyLine<double> operator+= (PolyLine<double>& v1, const Point<double>& point);
template<typename T> PolyLine<T> operator+=(PolyLine<T>& polyline, const Point<T>& point)
{
	polyline.data.insert(polyline.begin(), point);
	return polyline;
}


template<typename T> inline
PolyLine<T> PolyLine<T>::operator+(const Point<T>& point)
{
	vertex += 1;
	data.push_back(point);
	return *this;
}


template<typename T> inline Point<T>& PolyLine<T>::operator [] (const size_t index)
{
	if (data == nullptr)
		throw "Line is empty";
	if ((index >= vertex) || (index < 0)) throw "Invalid index";
	return data[index];
}


template<typename T> inline Point<T> PolyLine<T>::operator [] (const size_t index) const
{
	if (data == nullptr) throw "Line is empty";
	if ((index >= vertex) || (index < 0)) throw "Invalid index";
	return data[index];
}


template<typename T>  PolyLine<T> PolyLine<T>::operator + (const PolyLine<T>& polyline)
{
	if (!vertex)
		return polyline;
	if (!polyline.vertex)
		return *this;
	std::vector<Point<T>> res(int(vertex + polyline.vertex));
	for (size_t i = 0; i < vertex; i++)
	{
		/*res.data[i] = data[i];*/
		res.data.push_back(data[i]);
	}
	for (size_t i = 0; i < polyline.vertex; i++)
	{
		/*res.data[vertex + i] = polyline.data[i];*/
		res.data.push_back(data[i]);
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
		if ((fabs(data[i].x - polyline.data[i].x) > eps) || (fabs(data[i].y - polyline.data[i].y) > eps))
			return false;
	}
	return true;
}


template<typename T> bool PolyLine<T>::operator != (const PolyLine<T>& polyline)
{
	if (vertex != polyline.vertex) return true;
	for (size_t i = 0; i < vertex; i++)
	{
		if ((data[i].x != polyline.data[i].x) || (data[i].y != polyline.data[i].y))
			return true;
	}
	return false;
}


//template<typename T> PolyLine<T>& PolyLine<T>::operator = (const PolyLine<T>& polyline)
//{
//	if (this == (&polyline))
//		return *this;
//	if (data)
//		delete[] data;
//	if (polyline.data)
//	{
//		arr = new Point<T>[polyline.vertex];
//		vertex = polyline.vertex;
//		for (size_t i = 0; i < polyline.vertex; i++)
//		{
//			arr[i] = polyline.data[i];
//		}
//	}
//	else
//	{
//		data = NULL;
//		vertex = 0;
//	}
//	return *this;
//}

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
		out << "vertex[" << i << "]: " << "(" << polyline.arr[i].x << "," << polyline.data[i].y;
		if (i != polyline.vertex - 1) out << "); ";
		else out << ")";
	}
	out << ">";

	for (size_t i = 0; i < polyline.vertex - 1; i++)
	{
		MyDrawLine((int)polyline.data[i].x, (int)polyline.data[i].y,
			(int)polyline.data[i + 1].x, (int)polyline.data[i + 1].y);
	}
	return out;

}
