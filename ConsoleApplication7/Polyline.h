#pragma once
#include <iostream>
#include <complex>
#include<vector>

template <typename T>
struct Point
{
	T x = 0;
	T y = 0;
	double eps = 0.001;
	Point(T key1, T key2);
	Point() : x(0), y(0) {};
};


template<typename T>
class PolyLine {
	std::vector<Point<T>> data;
	size_t vertex;
public:
	PolyLine() : data(nullptr), vertex(0) {}
	PolyLine(int count) :  data(new std::vector<Point<T>>[count]), vertex(count) {}
	PolyLine(const PolyLine<T>& p) = default;
	~PolyLine() = default;
	std::vector<Point<T>> GetArr();
	double GetLenght() const;
	template <typename T> friend PolyLine<T> operator+=(PolyLine<T>& polyline, const Point<T>& point);
	PolyLine<T> operator+(const Point<T>& point);
	Point<T>& operator [] (const size_t index);
	Point<T> operator [] (const size_t index) const;
	PolyLine<T> operator + (const PolyLine<T>& polyline);
	bool operator == (const PolyLine<T>& polyline);
	bool operator != (const PolyLine<T>& polyline);
	PolyLine<T>& operator = (const PolyLine<T>& polyline) = default;
	template <typename T> friend std::ostream& operator<< (std::ostream& out, const PolyLine<T>& polyline);
	//auto begin();
	//auto end();
	//int get_n() const;
};

//template<typename V>
//class PolyLine<std::complex<V>> {
//	Point<std::complex<V>>* arr;
//	size_t vertex;
//
//public:
//	PolyLine(int count);
//	PolyLine(const PolyLine<std::complex<V>>& p);
//	PolyLine() : arr(nullptr), vertex(0) {}
//	~PolyLine();
//	Point<std::complex<V>>* GetArr();
//	double GetLenght() const;
//	PolyLine<std::complex<V>> operator+(const Point<std::complex<V>>& point);
//	Point<std::complex<V>> operator [] (const size_t index) const;
//	Point<std::complex<V>>& operator [] (const size_t index);
//	PolyLine<std::complex<V>> operator + (const PolyLine<std::complex<V>>& polyline);
//	bool operator == (const PolyLine<std::complex<V>>& polyline);
//	bool operator != (const PolyLine<std::complex<V>>& polyline);
//	PolyLine<std::complex<V>>& operator = (const PolyLine<std::complex<V>>& polyline);
//	template <typename V> friend PolyLine<std::complex<V>> operator+=(PolyLine<std::complex<V>>& polyline, const Point<std::complex<V>>& point);
//	template <typename V> friend std::ostream& operator<< (std::ostream& out, const PolyLine<std::complex<V>>& polyline);


//};