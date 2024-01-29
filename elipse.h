#ifndef ELIPSE_H
#define ELIPSE_H
#include "circle.h"
class Elipse:public Circle
{
public:
    Elipse();
    Elipse(Point, float, float);
    ~Elipse() override;
    Point C(float) override;
    std::vector<float> DerivedAtPI4() override;
    std::string WhoAmI() override;
protected:
    float r2;
};

#endif
