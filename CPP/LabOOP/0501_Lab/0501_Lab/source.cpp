// Name: ±i®Ñ»Ê B10615025
// Date: Mar. 29, 2018
// Last Update: Mar. 29, 2018
// Problem statement: Where is point
#include <iostream>
#include <vector>
#include <cmath>
//#define DEBUG

using namespace std;

enum type
{
	CIRCULAR,
	RECTANGLE
};

// Coordinate
struct point
{
	double x;
	double y;
};

class circular
{
public:
	// Constructor
	circular();
	circular(point p, double d);
	
	bool isInside(point &p);

private:
	point center;
	double radius;
};

circular::circular()
{}

circular::circular(point p, double d)
{
	center = p;
	radius = d;
}

bool circular::isInside(point &p)
{
#ifdef DEBUG
	cout << "isInside" << endl;
	cout << "radius : " << radius << endl;
	cout << "center : (" << center.x << ", " << center.y << ")" << endl;
	cout << "point  : (" << p.x << ", " << p.y << ")" << endl;
#endif

	double distance = sqrt((center.x - p.x) * (center.x - p.x) + (center.y - p.y) * (center.y - p.y));
	return radius >= distance;
}

class rectangle
{
public:
	// Constructor
	rectangle();
	rectangle(point q1, point q2);

	bool isInside(point &p);

private:
	point p1;	// Top left corner coordinate
	point p2;	// Lower right corner coordinate
};

rectangle::rectangle()
{}

rectangle::rectangle(point q1, point q2)
{
	p1 = q1;
	p2 = q2;
}

bool rectangle::isInside(point &p)
{
	if (p1.x <= p.x && p.x <= p2.x && p1.y >= p.y && p.y >= p2.y)
	{
		return true;
	}
	return false;
}

union figureUnion
{
	circular cir;
	rectangle rec;

	figureUnion()
	{
		cir = circular();
		rec = rectangle();
	}
};

struct figureStruct
{
	int type;
	figureUnion figure;
};

int main()
{
	int n;	// Amount of figure
	int m;	// Amount of point
	vector<figureStruct> figures;
	vector<point> points;

	while (cin >> n)
	{
		// Ignore '\n'
		cin.ignore();

		// Input information of n figure
		for (int i = 0; i < n; ++i)
		{
			char c;					// r or c

			cin >> c;

			if (c == 'c')
			{
				// the figure type is circular
				figureStruct f;
				point p;
				double r;
				
				cin >> p.x >> p.y >> r;

				f.type = CIRCULAR;
				f.figure.cir = circular(p, r);

				figures.push_back(f);
			}
			else
			{
				// the figure type is rectangle
				figureStruct f;
				point p1, p2;

				cin >> p1.x >> p1.y >> p2.x >> p2.y;

				f.type = RECTANGLE;
				f.figure.rec = rectangle(p1, p2);

				figures.push_back(f);
			}
		}

		// Input information of m point
		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			point p;
			cin >> p.x >> p.y;

			points.push_back(p);
		}

		// Output
		for (int i = 0; i < m; ++i)
		{
			bool foundFlag = false;	// Is the point contained in any figure?
			for (int j = 0; j < n; ++j)
			{
				if (figures[j].type == CIRCULAR)
				{
					if (figures[j].figure.cir.isInside(points[i]))
					{
						cout << "Point (" << points[i].x << ", " << points[i].y << ") is contained in figure " << j + 1 << endl;
						foundFlag = true;
					}
				}
				else
				{
					if (figures[j].figure.rec.isInside(points[i]))
					{
						cout << "Point (" << points[i].x << ", " << points[i].y << ") is contained in figure " << j + 1 << endl;
						foundFlag = true;
					}
				}
			}

			if (!foundFlag)
			{
				cout << "Point(" << points[i].x << ", " << points[i].y << ") is not contained in any figure" << endl;
			}
		}

		// Clear Vector
		figures.clear();
		points.clear();
	}

	return 0;
}