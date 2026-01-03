#include "Circle.h"
#include <cmath>

Circle::Circle() : Shape(), center(Point2D(0, 0)), radius(1) {}

Circle::Circle(std::string color, Point2D center, double radius) : Shape(color), center(center), radius(radius) {}

Point2D Circle::get_center() const {
	return center;
}

void Circle::set_center(Point2D p) {
	center = p;
}

double Circle::get_radius() const {
	return radius;
}

void Circle::set_radius(double r) {
	radius = r;
}

double Circle::area() const {
	return M_PI * std::pow(radius, 2);
}

double Circle::perimeter() const {
	return 2 * M_PI * radius;
}

void Circle::translate(double incX, double incY) {
	center.x += incX;
	center.y += incY;
}

void Circle::print(std::ostream &out) const {
	out << "[Circle: Color = " << get_color() << "; Center = (" << center.x << ", " 
				    << center.y << "); Radius = " << radius<<"]";
}

std::ostream& operator<<(std::ostream &out, const Circle &c) {
	c.print(out);
	return out;
}
