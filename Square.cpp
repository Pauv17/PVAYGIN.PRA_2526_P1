#include "Square.h"

bool Square::check(Point2D* vertices) {
	double d1 = Point2D::distance(vertices[0], vertices[1]);
	double d2 = Point2D::distance(vertices[1], vertices[2]);
	double d3 = Point2D::distance(vertices[2], vertices[3]);
	double d4 = Point2D::distance(vertices[3], vertices[0]);

	return (d1 == d2 && d2 == d3 && d3 == d4);
}

Square::Square() : Rectangle() {
	vs = new Point2D[N_VERTICES];
	vs[0] = Point2D(-1, 1);
	vs[1] = Point2D(1, 1);
	vs[2] = Point2D(1, -1);
	vs[3] = Point2D(-1, -1);
}

Square::Square(std::string color, Point2D* vertices) : Rectangle (color, vertices) {
	if (!check(vertices)) {
		throw std::invalid_argument("Los vértices no forman un cuadrado");
	}

	vs = new Point2D[N_VERTICES];
	for (int i = 0; i < N_VERTICES; i++) {
		vs[i] = vertices[i];
	}
}

void Square::set_vertices(Point2D* vertices) {
	if (!check(vertices)) {
		throw std::invalid_argument("Provided vertices do not build a valid square");
	}
	
	for (int i = 0; i < N_VERTICES; i++) {
		vs[i] = vertices[i];
	}
}

void Square::print(std::ostream &out) const{
	out << *this;
}

std::ostream& operator<<(std::ostream &out, const Square &square) {
	out << "[Square: Color = " << square.color
	    << "; v0 = " << square.vs[0]
	    << "; v1 = " << square.vs[1]
	    << "; v2 = " << square.vs[2]
	    << "; v3 = " << square.vs[3]
	    << "]";

	return out;
}
