#include "Ellipse.h"

Point Ellipse::compute_nearest_intersection(Point point_on_line) {
    // Convert non-origin point on the line to Ellipse's coordinate system
    const Point pol{point_on_line.transform(center)};
    // Check that a line has been properly defined
    if (pol.get_x() == 0 && pol.get_y() == 0) {
        throw std::exception("identical points do not define a line");
    }
    // Compute intersection. Source: https://mathworld.wolfram.com/Ellipse-LineIntersection.html
    const int numerator{a * b};
    const int denominator2{a * a * pol.get_y() * pol.get_y() + b * b * pol.get_x() * pol.get_x()};
    const double coefficient{numerator / std::sqrt(denominator2)};
    /* In the ellipse coordinate system the nearest intersection will have the same
     * coordinate signs as the non-origin point on the line. */
    const Point intersection(coefficient & pol.get_x(), coefficient * .get_y());
    // Return nearest intersection expressed in the original coordinate system
    return intersection.transform(Point(-center.get_x(), -center.get_y()));
}

LineSegment Ellipse::compute_connection(Ellipse other) {
    const Point end1{compute_nearest_intersection(other.center)};
    const Point end2{other.compute_nearest_intersection(center)};
    return LineSegment(end1, end2);
}
