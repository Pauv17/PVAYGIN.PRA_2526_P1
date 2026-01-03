#include "Drawing.h"

Drawing::Drawing() {
	shapes = new ListLinked<Shape*>();
}

Drawing::~Drawing() {
	delete shapes;
}

void Drawing::add_front(Shape* shape) {
	shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape) {
	shapes->append(shape);
}

void Drawing::print_all() const {
	std::cout << "Contenido del dibujo: " << std::endl;
	for (int i = 0; i < shapes->size(); i++) {
		shapes->get(i)->print(std::cout);
		std::cout << std::endl;
	}
}

double Drawing::get_area_all_circles() const {
	double area_total = 0.0;

	for (int i = 0; i < shapes->size(); i++) {
		Circle* circle = dynamic_cast<Circle*>(shapes->get(i));
		if (circle != nullptr) {
			area_total += circle->area();
		}
	}
	return area_total;
}

void Drawing::move_squares(double incX, double incY) {
	for (int i = 0; i < shapes->size(); i++) {
		Square* square = dynamic_cast<Square*>(shapes->get(i));
		if (square != nullptr) {
			square->translate(incX, incY);
		}
	}
}
