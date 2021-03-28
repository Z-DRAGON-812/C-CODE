#include <stdio.h>
#include <math.h>

#define MAX_POINTS_AMOUNT 500 

struct Point
{
	double x, y;
};

double distance(struct Point p1, struct Point p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double max(double a, double b, double c)
{
	return a >= b && a >= c
		? a
		: b >= a && b >= c
		? b
		: c;
}


int canMakeTriangle(double a, double b, double c)
{
	return a > fabs(b - c) && a<(b + c) ||
		b>fabs(a - c) && b<(a + c) ||
		c>fabs(a - b) && c < (a + b);
}


int canMakeAcuteTriangle(double a, double b, double c)
{
	unsigned int i;
	double cos_a, cos_b, cos_c;
	if (canMakeTriangle(a, b, c))
	{
		cos_a = (b * b + c * c - a * a) / (2 * b * c);
		cos_b = (a * a + c * c - b * b) / (2 * a * c);
		cos_c = (a * a + b * b - c * c) / (2 * a * b);
		return cos_a > 0 && cos_b > 0 && cos_c > 0;
	}
	return 0;
}


double minCircleRadius(unsigned int n, struct Point points[],
	unsigned int start, unsigned int selectPointsAmount, struct Point selectPoints[])
{
	if (n <= 1)
		return 0.0;
	if (n == 2)
		return distance(points[0], points[1]) / 2.0;
	else
	{
		if (selectPointsAmount == 3)
		{// 已经选好了 3 个点，求能覆盖它们的最小圆的半径

			double L1 = distance(selectPoints[0], selectPoints[1]);
			double L2 = distance(selectPoints[0], selectPoints[2]);
			double L3 = distance(selectPoints[1], selectPoints[2]);
			double L = (L1 + L2 + L3) / 2.0;
			double S = sqrt(L * (L - L1) * (L - L2) * (L - L3));
			if (canMakeAcuteTriangle(L1, L2, L3))
			{// 能组成锐角三角形
				return L1 * L2 * L3 / (4.0 * S);
			}
			else
			{// 其他情况：三点共线，组成直角三角形，或锐角三角形
				return max(L1, L2, L3) / 2.0;
			}
		}
		else
		{// 任选 3 个点
			double r, minR = 0.0;
			unsigned int i;

			struct Point temp[3];
			if (selectPoints == NULL)
				selectPoints = temp;

			for (i = start; (n - i) >= (3 - selectPointsAmount); i++)
			{
				selectPoints[selectPointsAmount] = points[i];
				r = minCircleRadius(n, points, i + 1, selectPointsAmount + 1, selectPoints);
				if (minR < r)
					minR = r;
			}
			return minR;
		}
	}
}
int main(int argc, char* argv[])
{
	struct Point points[MAX_POINTS_AMOUNT];
	unsigned int i, n, mx, my;
	FILE* fp;
	fp = fopen("d:\\points2.txt", "a+");
	while (fscanf(fp, "%d\n", &n) != EOF)
	{
		for (i = 0; i < n; i++)
			fscanf(fp, "(%lf,%lf)\n", &points[i].x, &points[i].y);
		printf("最小覆盖圆半径为%.2lf\n", minCircleRadius(n, points, 0, 0, NULL));
	}
	return 0;
}

