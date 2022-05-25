#pragma once

#include <utility>

class LineSegment {
private:
    std::pair<Point,Point> endpoints;
public:
    LineSegment(Point end1, Point end2) : endpoints(std::pair<Point,Point>(end1, end2)) {}
    std::pair<Point,Point> get_endpoints() const {return endpoints;};
};
