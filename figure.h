#ifndef FIGURE_H
#define FIGURE_H
#include <cmath>
#include <string>
#include <vector>
#include "point.h"
#define PI 3.14159265358979323846
class Figure
{
    public:
        Figure();
        virtual ~Figure(){}
        Figure(Point, float);
        float GetR() const;
        virtual Point C(float) = 0;
        virtual std::vector<float> DerivedAtPI4() = 0;
        virtual std::string WhoAmI() = 0;
    protected:
        Point start;
        float r;

};


#endif
