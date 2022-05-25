#pragma once

class Point {
private:
    const int x;
    const int y;
public:
    Point(int x, int y) : x(x), y(y) {}
    int get_x() const {return x;}
    int get_y() const {return y;}
    /* Compute this Point's coordinates in a coordinate system with its origin
     * at new_origin in the existing coordinate system. */
    Point transform(Point new_origin) const {
        return Point(x - new_origin.x, y - new_origin.y);
    }
};
