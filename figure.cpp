#include "figure.h"
Figure::Figure()
{
    this->start = {0,0,0};
    this->r = 0;
}

Figure::Figure(Point p, float r)
{
    this->start.x  = p.x;
    this->start.y  = p.y;
    this->start.z  = p.z;
    this->r = r;
}

float Figure::GetR() const{
    return r;
}
