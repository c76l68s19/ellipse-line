#pragma once

#include "Point.h"
#include "LineSegment.h"

class Ellipse {
private:
    const Point center;
    const unsigned int a; // semi-major axis (on x axis)
    const unsigned int b; // semi-minor axis (on y axis)
    /* Compute intersection of Ellipse with a line, defined by two points
     * 1. one point is the Ellipse's center
     * 2. the other point is specified by point_on_line, which must not be the ellipse's center. */
    Point compute_nearest_intersection(Point point_on_line) const;
public:
    Ellipse(Point center, unsigned int a, unsigned int b) : center(center), a(a), b(b) {}
    Point get_center() const {return center;}
    unsigned int get_a() const;
    unsigned int get_b() const;
    // Compute the LineSegment connecting this Ellipse with another Ellipse
    LineSegment compute_connection(Ellipse other);
};
