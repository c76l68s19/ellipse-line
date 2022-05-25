#include <iostream>
#include <sstream>

#include "Point.h"
#include "LineSegment.h"
#include "Ellipse.h"

std::string toString(Point point) {
    std::ostringstream buffer;
    buffer << "(" << point.get_x() << "," << point.get_y() << ")";
    return buffer.str();
}

std::string toString(LineSegment line_segment) {
    std::ostringstream buffer;
    buffer << toString(line_segment.get_endpoints().first) << "-" << toString(line_segment.get_endpoints().second);
    return buffer.str();
}

std::string toString(Ellipse ellipse) {
    std::ostringstream buffer;
    buffer << "center: " << toString(ellipse.get_center()) << " a: " << ellipse.get_a() << " b: " << ellipse.get_b();
    return buffer.str();
}

void print(Ellipse ellipse1, Ellipse ellipse2, LineSegment connection) {
    std::cout << "Ellipses: " << toString(ellipse1) << ", " << toString(ellipse2) << "; connection: " << toString(connection) << "\n";
}

int main(int argc, char * argv[]) {
    Ellipse e1(Point(0,0),1,1);
    Ellipse e2(Point(2,2),1,1);
    LineSegment con{e1.compute_connection(e2)};
    print(e1, e2, con);
}
