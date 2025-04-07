
#include "Canva.h"
#include <stdio.h>

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;

	canvas = new char* [height];
	for (int i = 0; i < height; i++)
	{
		canvas[i] = new char[width];

		for (int j = 0; j < width; j++)
			canvas[i][j] = ' ';
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	x--;
	y = height - y + 1;

	int r = ray / 2;
	for (int i = 0; i <= r; i++) 
	{
		canvas[y + i][x - r + i] = ch;
		canvas[y - i][x - r + i] = ch;

		canvas[y + i][x + r - i] = ch;
		canvas[y - i][x + r - i] = ch;
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	x--;
	y = height - y + 1;

	int r = ray / 2;
	for (int i = 0; i <= r; i++) {
		for (int j = y - i; j <= y + i; j++)
		{
			canvas[j][x - r + i] = ch;
			canvas[j][x + r - i] = ch;
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	top = height - top + 1;
	bottom = height - bottom + 1;
	left--;
	right--;

	for (int i = left; i <= right; i++)
	{
		canvas[top][i] = ch;
		canvas[bottom][i] = ch;
	}

	for (int i = top; i <= bottom; i++)
	{
		canvas[i][left] = ch;
		canvas[i][right] = ch;
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	top = height - top + 1;
	bottom = height - bottom + 1;
	left--;
	right--;

	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++)
			canvas[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
	x--;
	y = height - y + 1;

	canvas[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	
	int dx = x2 - x1 > 0 ? x2 - x1 : x1 - x2;
	int dy = y2 - y1 > 0 ? y2 - y1 : y1 - y2;
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;

	while (true)
	{
		SetPoint(x1, y1, ch);
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void Canvas::Print()
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			printf("%c", canvas[i][j]);
		printf("\n");
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			canvas[i][j] = ' ';
}



