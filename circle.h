#ifndef CIRCLE_H
#define CIRCLE_H
#include "figure.h"
class Circle:public Figure
{
    public:
        Circle();
        ~Circle() override;
        Circle(Point, float);
        Point C(float) override;
        std::vector<float> DerivedAtPI4() override;
        std::string WhoAmI() override;
};
#endif
