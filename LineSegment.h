#pragma once

class LineSegment {
private:
    std::pair<Point> endpoints;
public:
    LineSegment(Point end1, Point end2) : endpoints(std::pair(end1, end2)) {}
    std::pair<Point> get_endpoints() const {return endpoints};
};
