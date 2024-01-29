#ifndef HELIX_H
#define HELIX_H
#include "circle.h"
class Helix:public Circle
{
public:
    Helix();
    Helix(Point, float, float);
    ~Helix() override;
    Point C(float) override;
    std::vector<float> DerivedAtPI4() override;
    std::string WhoAmI() override;
protected:
    float step;
};

#endif
