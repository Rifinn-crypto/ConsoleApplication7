#include <math.h>
#include <conio.h>
#include "Polyline.h"
#include <typeinfo>
#include <string>


int GetKey()
{
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}

int Menu_0()
{

	std::cout << "1.complex<float>" << std::endl;
	std::cout << "2.complex<double" << std::endl;
	std::cout << "3.int" << std::endl;
	std::cout << "4.double" << std::endl;
	std::cout << "5.float" << std::endl;
	while (true)
	{
		int key = GetKey();
		if ((key == 27) || (key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53)) return key;
	}
}

int Menu()
{
	system("cls");
	std::cout << "\n1 - Add a vertex to the beginning of the polyline\n2 - Add a vertex to the end of the polyline\n3 - Calculate the length of the polyline\n4 - View the line\n5 - Overwrite vertex value\n6 - View the value of the vertex\n7 - The sum of two polylines\n8 - Check polylines for equality\n9 - Get N - PolyLine\n\nExit - Esc" << std::endl;
	while (true)
	{
		int key = GetKey();
		if ((key == 27) || (key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55) || (key == 56) || (key == 57)) return key;
	}
}


int Menu_1()
{
	system("cls");
	std::cout << "Choose your line:\n\n1 - First line\n2 - Second line\n\nEsc - Return back" << std::endl;
	while (true)
	{
		int key = GetKey();
		if ((key == 27) || (key == 49) || (key == 50)) return key;
	}
}




using tt = std::complex<float>;
using collection2 = std::complex<double>;
using collection3 = int;
using collection4 = float;
using collection5 = double;



int main()
{
	Menu_0();
	int key = GetKey();
	switch (key)
	{
	case 49:
	{



		using type = float;
		PolyLine<tt> line_1, line_2, line_3;
		while (true)
		{
			system("cls");
			int m = Menu();
			if (m == 27)
			{
				break;
			}
			if (m == 49)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");

						type a = 0, b = 0;
						std::cout << "Real part x: ";
						std::cin >> a;
						std::cout << "Image part x: ";
						std::cin >> b;
						std::complex<type> X(a, b);
						std::cout << "Real part y: ";
						std::cin >> a;
						std::cout << "Image part y: ";
						std::cin >> b;
						std::complex<type> Y(a, b);
						//Point<tt> p(X, Y);
						Point<tt> p;
						p.x = X;
						p.y = Y;
						try
						{

							line_1 += p;

						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
						}

					}
					if (m1 == 50)
					{
						system("cls");
						type a = 0, b = 0;
						std::cout << "Real part x: ";
						std::cin >> a;
						std::cout << "Image part x: ";
						std::cin >> b;
						std::complex<type> X(a, b);
						std::cout << "Real part y: ";
						std::cin >> a;
						std::cout << "Image part y: ";
						std::cin >> b;
						std::complex<type> Y(a, b);
						//Point<tt> p(X, Y);
						Point<tt> p;
						p.x = X;
						p.y = Y;
						try
						{

							line_1 += p;

						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
						}

					}
				}
			}
			if (m == 50)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");

						type a = 0, b = 0;
						std::cout << "Real part x: ";
						std::cin >> a;
						std::cout << "Image part x: ";
						std::cin >> b;
						std::complex<type> X(a, b);
						std::cout << "Real part y: ";
						std::cin >> a;
						std::cout << "Image part y: ";
						std::cin >> b;
						std::complex<type> Y(a, b);
						//Point<tt> p(X, Y);
						Point<tt> p;
						p.x = X;
						p.y = Y;
						try
						{
							line_1 + p;
							//std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
						}
						//std::cin.get();
					}
					if (m1 == 50)
					{
						system("cls");
						Point<tt> p;
						/*std::cout << "Enter the coordinates of the point" << std::endl;
						std::cout << "Enter x: " << std::endl;
						std::cin >> p.x;
						std::cout << "Enter y: " << std::endl;
						std::cin >> p.y;*/
						try
						{
							//line_2 + p;
							//std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
						}
						//std::cin.get();
					}
				}
			}
			if (m == 51)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						try
						{
							std::cout << line_1 << std::endl;
							std::cout << "Line_1 lenght : " << line_1.GetLenght() << std::endl;
							std::cin.get();
						}
						catch (std::exception& ex)
						{
							std::cout << ex.what() << std::endl;
						}
						std::cin.get();
					}
					if (m1 == 50)
					{
						system("cls");
						try
						{
							std::cout << line_2 << std::endl;
							std::cout << "Line_2 lenght : " << line_2.GetLenght() << std::endl;
							std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
						}
						std::cin.get();
					}
				}
			}
			if (m == 52)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						std::cout << line_1 << std::endl;
						std::cin.get();
					}
					if (m1 == 50)
					{
						system("cls");
						std::cout << line_2 << std::endl;
						std::cin.get();
					}
				}
			}
			if (m == 53)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						std::cout << "Enter index of element: " << std::endl;
						int index;
						std::cin >> index;
						try
						{
							std::cout << "Your element: " << "[" << line_1[index].x << ";" << line_1[index].y << "]" << std::endl;
							std::cout << "Enter new value: " << std::endl;
							std::cin >> line_1[index].x;
							std::cin >> line_1[index].y;
							std::cin.get();

						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							std::cin.get();
							std::cin.get();
						}
					}
					if (m1 == 50)
					{
						system("cls");
						std::cout << "Enter index of element: " << std::endl;
						int index;
						std::cin >> index;
						try
						{
							std::cout << "Your element: " << "[" << line_2[index].x << ";" << line_2[index].y << "]" << std::endl;
							std::cout << "Enter new value: " << std::endl;
							std::cin >> line_2[index].x;
							std::cin >> line_2[index].y;
							std::cin.get();

						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							std::cin.get();
							std::cin.get();
						}
					}
				}
			}
			if (m == 54)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						std::cout << "Enter index of element: " << std::endl;
						int index;
						std::cin >> index;
						try
						{
							std::cout << "Your element: " << "[" << line_1[index].x << ";" << line_1[index].y << "]" << std::endl;
							std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							std::cin.get();
							std::cin.get();
						}
						std::cin.get();
					}
					if (m1 == 50)
					{
						system("cls");
						std::cout << "Enter index of element: " << std::endl;
						int index;
						std::cin >> index;
						try
						{
							std::cout << "Your element: " << "[" << line_2[index].x << ";" << line_2[index].y << "]" << std::endl;
							std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							std::cin.get();
							std::cin.get();
						}
						std::cin.get();
					}
				}
			}
			if (m == 55)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						line_1 = line_1 + line_2;
						std::cout << "Successfully" << std::endl;
						std::cin.get();
					}
					if (m1 == 50)
					{
						system("cls");
						line_2 = line_2 + line_1;
						std::cout << "Successfully" << std::endl;
						std::cin.get();
					}
				}
			}
			if (m == 56)
			{
				system("cls");
				if (line_1 == line_2) std::cout << "Polylines are equal" << std::endl;
				else std::cout << "Polylines aren't equal" << std::endl;
				std::cin.get();
			}
			if (m == 57)
			{
				system("cls");
				std::cout << "Input the N > 2" << std::endl;
				int N = 0;
				do
				{
					std::cin >> N;
					if (N < 2)
						std::cout << "Need N > 2 " << std::endl;
				} while (N < 2);
				PolyLine<tt> line_3(N + 1);
				unsigned radius = 100;
				double angle = 0;

				for (int i = 0; i < N + 1; i++) {
					line_3[i].x = radius * cos(angle * 3.14 / 180) + 300;
					line_3[i].y = radius * sin(angle * 3.14 / 180) + 300;
					angle = angle + 360.0 / N;
				}

				std::cout << line_3 << std::endl;
				std::cin.get();
				std::cin.get();

			}

		}
	}
	case 50:
	{
		using type = double;
		PolyLine<collection2> line_1, line_2, line_3;
		while (true)
		{
			system("cls");
			int m = Menu();
			if (m == 27)
			{
				break;
			}
			if (m == 49)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");

						type a = 0, b = 0;
						std::cout << "Real part x: ";
						std::cin >> a;
						std::cout << "Image part x: ";
						std::cin >> b;
						std::complex<type> X(a, b);
						std::cout << "Real part y: ";
						std::cin >> a;
						std::cout << "Image part y: ";
						std::cin >> b;
						std::complex<type> Y(a, b);
						//Point<tt> p(X, Y);
						Point<collection2> p;
						p.x = X;
						p.y = Y;
						try
						{

							line_1 += p;

						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
						}

					}
					if (m1 == 50)
					{
						system("cls");
						type a = 0, b = 0;
						std::cout << "Real part x: ";
						std::cin >> a;
						std::cout << "Image part x: ";
						std::cin >> b;
						std::complex<type> X(a, b);
						std::cout << "Real part y: ";
						std::cin >> a;
						std::cout << "Image part y: ";
						std::cin >> b;
						std::complex<type> Y(a, b);
						//Point<tt> p(X, Y);
						Point<collection2> p;
						p.x = X;
						p.y = Y;
						try
						{

							line_1 += p;

						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
						}

					}
				}
			}

			if (m == 51)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						try
						{
							std::cout << line_1 << std::endl;
							std::cout << "Line_1 lenght : " << line_1.GetLenght() << std::endl;
							std::cin.get();
						}
						catch (std::exception& ex)
						{
							std::cout << ex.what() << std::endl;
						}
						std::cin.get();
					}
					if (m1 == 50)
					{
						system("cls");
						try
						{
							std::cout << line_2 << std::endl;
							std::cout << "Line_2 lenght : " << line_2.GetLenght() << std::endl;
							std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
						}
						std::cin.get();
					}
				}
			}
			if (m == 52)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						std::cout << line_1 << std::endl;
						std::cin.get();
					}
					if (m1 == 50)
					{
						system("cls");
						std::cout << line_2 << std::endl;
						std::cin.get();
					}
				}
			}
			if (m == 53)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						std::cout << "Enter index of element: " << std::endl;
						int index;
						std::cin >> index;
						try
						{
							std::cout << "Your element: " << "[" << line_1[index].x << ";" << line_1[index].y << "]" << std::endl;
							std::cout << "Enter new value: " << std::endl;
							std::cin >> line_1[index].x;
							std::cin >> line_1[index].y;
							std::cin.get();

						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							std::cin.get();
							std::cin.get();
						}
					}
					if (m1 == 50)
					{
						system("cls");
						std::cout << "Enter index of element: " << std::endl;
						int index;
						std::cin >> index;
						try
						{
							std::cout << "Your element: " << "[" << line_2[index].x << ";" << line_2[index].y << "]" << std::endl;
							std::cout << "Enter new value: " << std::endl;
							std::cin >> line_2[index].x;
							std::cin >> line_2[index].y;
							std::cin.get();

						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							std::cin.get();
							std::cin.get();
						}
					}
				}
			}
			if (m == 54)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						std::cout << "Enter index of element: " << std::endl;
						int index;
						std::cin >> index;
						try
						{
							std::cout << "Your element: " << "[" << line_1[index].x << ";" << line_1[index].y << "]" << std::endl;
							std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							std::cin.get();
							std::cin.get();
						}
						std::cin.get();
					}
					if (m1 == 50)
					{
						system("cls");
						std::cout << "Enter index of element: " << std::endl;
						int index;
						std::cin >> index;
						try
						{
							std::cout << "Your element: " << "[" << line_2[index].x << ";" << line_2[index].y << "]" << std::endl;
							std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							std::cin.get();
							std::cin.get();
						}
						std::cin.get();
					}
				}
			}
			if (m == 55)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						line_1 = line_1 + line_2;
						std::cout << "Successfully" << std::endl;
						std::cin.get();
					}
					if (m1 == 50)
					{
						system("cls");
						line_2 = line_2 + line_1;
						std::cout << "Successfully" << std::endl;
						std::cin.get();
					}
				}
			}
			if (m == 56)
			{
				system("cls");
				if (line_1 == line_2) std::cout << "Polylines are equal" << std::endl;
				else std::cout << "Polylines aren't equal" << std::endl;
				std::cin.get();
			}
			if (m == 57)
			{
				system("cls");
				std::cout << "Input the N > 2" << std::endl;
				int N = 0;
				do
				{
					std::cin >> N;
					if (N < 2)
						std::cout << "Need N > 2 " << std::endl;
				} while (N < 2);
				PolyLine<collection2> line_3(N + 1);
				unsigned radius = 100;
				double angle = 0;

				for (int i = 0; i < N + 1; i++) {
					line_3[i].x = radius * cos(angle * 3.14 / 180) + 300;
					line_3[i].y = radius * sin(angle * 3.14 / 180) + 300;
					angle = angle + 360.0 / N;
				}

				std::cout << line_3 << std::endl;
				std::cin.get();
				std::cin.get();

			}

		}
	}
	case 51:
	{

		PolyLine<collection3> line_1, line_2, line_3;
		while (true)
		{
			system("cls");
			int m = Menu();
			if (m == 27)
			{
				break;
			}
			if (m == 49)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						Point<collection3> p;
						std::cout << "Enter the coordinates of the point" << std::endl;
						std::cout << "Enter x: " << std::endl;
						std::cin >> p.x;
						std::cout << "Enter y: " << std::endl;
						std::cin >> p.y;
						try
						{
							//line_2.AddToHead(p);
							line_1 += p;
							//std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
						}
					}
					if (m1 == 50)
					{
						system("cls");
						Point<collection3> p;
						std::cout << "Enter the coordinates of the point" << std::endl;
						std::cout << "Enter x: " << std::endl;
						std::cin >> p.x;
						std::cout << "Enter y: " << std::endl;
						std::cin >> p.y;
						try
						{
							//line_2.AddToHead(p);
							line_2 += p;
							//std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
						}

					}
				}
			}
			if (m == 51)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						try
						{
							std::cout << line_1 << std::endl;
							std::cout << "Line_1 lenght : " << line_1.GetLenght() << std::endl;
							std::cin.get();
						}
						catch (std::exception& ex)
						{
							std::cout << ex.what() << std::endl;
						}
						std::cin.get();
					}
					if (m1 == 50)
					{
						system("cls");
						try
						{
							std::cout << line_2 << std::endl;
							std::cout << "Line_2 lenght : " << line_2.GetLenght() << std::endl;
							std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
						}
						std::cin.get();
					}
				}
			}
			if (m == 52)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						std::cout << line_1 << std::endl;
						std::cin.get();
					}
					if (m1 == 50)
					{
						system("cls");
						std::cout << line_2 << std::endl;
						std::cin.get();
					}
				}
			}
			if (m == 53)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						std::cout << "Enter index of element: " << std::endl;
						int index;
						std::cin >> index;
						try
						{
							std::cout << "Your element: " << "[" << line_1[index].x << ";" << line_1[index].y << "]" << std::endl;
							std::cout << "Enter new value: " << std::endl;
							std::cin >> line_1[index].x;
							std::cin >> line_1[index].y;
							std::cin.get();

						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							std::cin.get();
							std::cin.get();
						}
					}
					if (m1 == 50)
					{
						system("cls");
						std::cout << "Enter index of element: " << std::endl;
						int index;
						std::cin >> index;
						try
						{
							std::cout << "Your element: " << "[" << line_2[index].x << ";" << line_2[index].y << "]" << std::endl;
							std::cout << "Enter new value: " << std::endl;
							std::cin >> line_2[index].x;
							std::cin >> line_2[index].y;
							std::cin.get();

						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							std::cin.get();
							std::cin.get();
						}
					}
				}
			}
			if (m == 54)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						std::cout << "Enter index of element: " << std::endl;
						int index;
						std::cin >> index;
						try
						{
							std::cout << "Your element: " << "[" << line_1[index].x << ";" << line_1[index].y << "]" << std::endl;
							std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							std::cin.get();
							std::cin.get();
						}
						std::cin.get();
					}
					if (m1 == 50)
					{
						system("cls");
						std::cout << "Enter index of element: " << std::endl;
						int index;
						std::cin >> index;
						try
						{
							std::cout << "Your element: " << "[" << line_2[index].x << ";" << line_2[index].y << "]" << std::endl;
							std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							std::cin.get();
							std::cin.get();
						}
						std::cin.get();
					}
				}
			}
			if (m == 55)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						line_1 = line_1 + line_2;
						std::cout << "Successfully" << std::endl;
						std::cin.get();
					}
					if (m1 == 50)
					{
						system("cls");
						line_2 = line_2 + line_1;
						std::cout << "Successfully" << std::endl;
						std::cin.get();
					}
				}
			}
			if (m == 56)
			{
				system("cls");
				if (line_1 == line_2) std::cout << "Polylines are equal" << std::endl;
				else std::cout << "Polylines aren't equal" << std::endl;
				std::cin.get();
			}
			if (m == 57)
			{
				system("cls");
				std::cout << "Input the N > 2" << std::endl;
				int N = 0;
				do
				{
					std::cin >> N;
					if (N < 2)
						std::cout << "Need N > 2 " << std::endl;
				} while (N < 2);
				PolyLine<collection3> line_3(N + 1);
				unsigned radius = 100;
				double angle = 0;

				for (int i = 0; i < N + 1; i++) {
					line_3[i].x = radius * cos(angle * 3.14 / 180) + 300;
					line_3[i].y = radius * sin(angle * 3.14 / 180) + 300;
					angle = angle + 360.0 / N;
				}

				std::cout << line_3 << std::endl;
				std::cin.get();
				std::cin.get();

			}


		}





	}
	case 52:
	{

		PolyLine<collection4> line_1, line_2, line_3;
		while (true)
		{
			system("cls");
			int m = Menu();
			if (m == 27)
			{
				break;
			}
			if (m == 49)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						Point<collection4> p;
						std::cout << "Enter the coordinates of the point" << std::endl;
						std::cout << "Enter x: " << std::endl;
						std::cin >> p.x;
						std::cout << "Enter y: " << std::endl;
						std::cin >> p.y;
						try
						{
							//line_2.AddToHead(p);
							line_1 += p;
							//std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
						}
					}
					if (m1 == 50)
					{
						system("cls");
						Point<collection4> p;
						std::cout << "Enter the coordinates of the point" << std::endl;
						std::cout << "Enter x: " << std::endl;
						std::cin >> p.x;
						std::cout << "Enter y: " << std::endl;
						std::cin >> p.y;
						try
						{
							//line_2.AddToHead(p);
							line_2 += p;
							//std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
						}

					}
				}
			}
			if (m == 51)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						try
						{
							std::cout << line_1 << std::endl;
							std::cout << "Line_1 lenght : " << line_1.GetLenght() << std::endl;
							std::cin.get();
						}
						catch (std::exception& ex)
						{
							std::cout << ex.what() << std::endl;
						}
						std::cin.get();
					}
					if (m1 == 50)
					{
						system("cls");
						try
						{
							std::cout << line_2 << std::endl;
							std::cout << "Line_2 lenght : " << line_2.GetLenght() << std::endl;
							std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
						}
						std::cin.get();
					}
				}
			}
			if (m == 52)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						std::cout << line_1 << std::endl;
						std::cin.get();
					}
					if (m1 == 50)
					{
						system("cls");
						std::cout << line_2 << std::endl;
						std::cin.get();
					}
				}
			}
			if (m == 53)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						std::cout << "Enter index of element: " << std::endl;
						int index;
						std::cin >> index;
						try
						{
							std::cout << "Your element: " << "[" << line_1[index].x << ";" << line_1[index].y << "]" << std::endl;
							std::cout << "Enter new value: " << std::endl;
							std::cin >> line_1[index].x;
							std::cin >> line_1[index].y;
							std::cin.get();

						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							std::cin.get();
							std::cin.get();
						}
					}
					if (m1 == 50)
					{
						system("cls");
						std::cout << "Enter index of element: " << std::endl;
						int index;
						std::cin >> index;
						try
						{
							std::cout << "Your element: " << "[" << line_2[index].x << ";" << line_2[index].y << "]" << std::endl;
							std::cout << "Enter new value: " << std::endl;
							std::cin >> line_2[index].x;
							std::cin >> line_2[index].y;
							std::cin.get();

						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							std::cin.get();
							std::cin.get();
						}
					}
				}
			}
			if (m == 54)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						std::cout << "Enter index of element: " << std::endl;
						int index;
						std::cin >> index;
						try
						{
							std::cout << "Your element: " << "[" << line_1[index].x << ";" << line_1[index].y << "]" << std::endl;
							std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							std::cin.get();
							std::cin.get();
						}
						std::cin.get();
					}
					if (m1 == 50)
					{
						system("cls");
						std::cout << "Enter index of element: " << std::endl;
						int index;
						std::cin >> index;
						try
						{
							std::cout << "Your element: " << "[" << line_2[index].x << ";" << line_2[index].y << "]" << std::endl;
							std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							std::cin.get();
							std::cin.get();
						}
						std::cin.get();
					}
				}
			}
			if (m == 55)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						line_1 = line_1 + line_2;
						std::cout << "Successfully" << std::endl;
						std::cin.get();
					}
					if (m1 == 50)
					{
						system("cls");
						line_2 = line_2 + line_1;
						std::cout << "Successfully" << std::endl;
						std::cin.get();
					}
				}
			}
			if (m == 56)
			{
				system("cls");
				if (line_1 == line_2) std::cout << "Polylines are equal" << std::endl;
				else std::cout << "Polylines aren't equal" << std::endl;
				std::cin.get();
			}
			if (m == 57)
			{
				system("cls");
				std::cout << "Input the N > 2" << std::endl;
				int N = 0;
				do
				{
					std::cin >> N;
					if (N < 2)
						std::cout << "Need N > 2 " << std::endl;
				} while (N < 2);
				PolyLine<collection4> line_3(N + 1);
				unsigned radius = 100;
				double angle = 0;

				for (int i = 0; i < N + 1; i++) {
					line_3[i].x = radius * cos(angle * 3.14 / 180) + 300;
					line_3[i].y = radius * sin(angle * 3.14 / 180) + 300;
					angle = angle + 360.0 / N;
				}

				std::cout << line_3 << std::endl;
				std::cin.get();
				std::cin.get();

			}


		}





	}
	case 53:
	{

		PolyLine<collection5> line_1, line_2, line_3;
		while (true)
		{
			system("cls");
			int m = Menu();
			if (m == 27)
			{
				break;
			}
			if (m == 49)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						Point<collection5> p;
						std::cout << "Enter the coordinates of the point" << std::endl;
						std::cout << "Enter x: " << std::endl;
						std::cin >> p.x;
						std::cout << "Enter y: " << std::endl;
						std::cin >> p.y;
						try
						{
							//line_2.AddToHead(p);
							line_1 += p;
							//std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
						}
					}
					if (m1 == 50)
					{
						system("cls");
						Point<collection5> p;
						std::cout << "Enter the coordinates of the point" << std::endl;
						std::cout << "Enter x: " << std::endl;
						std::cin >> p.x;
						std::cout << "Enter y: " << std::endl;
						std::cin >> p.y;
						try
						{
							//line_2.AddToHead(p);
							line_2 += p;
							//std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
						}

					}
				}
			}
			if (m == 51)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						try
						{
							std::cout << line_1 << std::endl;
							std::cout << "Line_1 lenght : " << line_1.GetLenght() << std::endl;
							std::cin.get();
						}
						catch (std::exception& ex)
						{
							std::cout << ex.what() << std::endl;
						}
						std::cin.get();
					}
					if (m1 == 50)
					{
						system("cls");
						try
						{
							std::cout << line_2 << std::endl;
							std::cout << "Line_2 lenght : " << line_2.GetLenght() << std::endl;
							std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
						}
						std::cin.get();
					}
				}
			}
			if (m == 52)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						std::cout << line_1 << std::endl;
						std::cin.get();
					}
					if (m1 == 50)
					{
						system("cls");
						std::cout << line_2 << std::endl;
						std::cin.get();
					}
				}
			}
			if (m == 53)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						std::cout << "Enter index of element: " << std::endl;
						int index;
						std::cin >> index;
						try
						{
							std::cout << "Your element: " << "[" << line_1[index].x << ";" << line_1[index].y << "]" << std::endl;
							std::cout << "Enter new value: " << std::endl;
							std::cin >> line_1[index].x;
							std::cin >> line_1[index].y;
							std::cin.get();

						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							std::cin.get();
							std::cin.get();
						}
					}
					if (m1 == 50)
					{
						system("cls");
						std::cout << "Enter index of element: " << std::endl;
						int index;
						std::cin >> index;
						try
						{
							std::cout << "Your element: " << "[" << line_2[index].x << ";" << line_2[index].y << "]" << std::endl;
							std::cout << "Enter new value: " << std::endl;
							std::cin >> line_2[index].x;
							std::cin >> line_2[index].y;
							std::cin.get();

						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							std::cin.get();
							std::cin.get();
						}
					}
				}
			}
			if (m == 54)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						std::cout << "Enter index of element: " << std::endl;
						int index;
						std::cin >> index;
						try
						{
							std::cout << "Your element: " << "[" << line_1[index].x << ";" << line_1[index].y << "]" << std::endl;
							std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							std::cin.get();
							std::cin.get();
						}
						std::cin.get();
					}
					if (m1 == 50)
					{
						system("cls");
						std::cout << "Enter index of element: " << std::endl;
						int index;
						std::cin >> index;
						try
						{
							std::cout << "Your element: " << "[" << line_2[index].x << ";" << line_2[index].y << "]" << std::endl;
							std::cin.get();
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							std::cin.get();
							std::cin.get();
						}
						std::cin.get();
					}
				}
			}
			if (m == 55)
			{
				while (true)
				{
					system("cls");
					int m1 = Menu_1();
					if (m1 == 27) break;
					if (m1 == 49)
					{
						system("cls");
						line_1 = line_1 + line_2;
						std::cout << "Successfully" << std::endl;
						std::cin.get();
					}
					if (m1 == 50)
					{
						system("cls");
						line_2 = line_2 + line_1;
						std::cout << "Successfully" << std::endl;
						std::cin.get();
					}
				}
			}
			if (m == 56)
			{
				system("cls");
				if (line_1 == line_2) std::cout << "Polylines are equal" << std::endl;
				else std::cout << "Polylines aren't equal" << std::endl;
				std::cin.get();
			}
			if (m == 57)
			{
				system("cls");
				std::cout << "Input the N > 2" << std::endl;
				int N = 0;
				do
				{
					std::cin >> N;
					if (N < 2)
						std::cout << "Need N > 2 " << std::endl;
				} while (N < 2);
				PolyLine<collection5> line_3(N + 1);
				unsigned radius = 100;
				double angle = 0;

				for (int i = 0; i < N + 1; i++) {
					line_3[i].x = radius * cos(angle * 3.14 / 180) + 300;
					line_3[i].y = radius * sin(angle * 3.14 / 180) + 300;
					angle = angle + 360.0 / N;
				}

				std::cout << line_3 << std::endl;
				std::cin.get();
				std::cin.get();

			}


		}





	}
	}
	return 0;


}
