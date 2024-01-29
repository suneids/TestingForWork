#include "elipse.h"

Elipse::Elipse():Circle()
{
    r2 = 0;
}

Elipse::Elipse(Point p, float r, float r2):Circle(p, r)
{
    this->r2 = r2;
}

Elipse::~Elipse(){

}

Point Elipse::C(float t)
{
    float rad = t*PI/180;
    return Point(start.x + r*cos(rad), start.y + r2*sin(rad), 0);
}

std::vector<float> Elipse::DerivedAtPI4(){
    std::vector<float> result;
    float dxdt, dydt;
    dxdt = -r*sin(PI/4);
    dydt = r2*cos(PI/4);
    result.push_back(dydt/dxdt);
    result.push_back(-dydt/dxdt);
    return result;
}


std::string Elipse::WhoAmI()
{
    std::string type("Ellipse, ");
    std::string start_point = "center: (" + std::to_string(start.x) + ", " + std::to_string(start.y) + ", " + std::to_string(start.z) + "), ";
    std::string params  =  "r1 = " + std::to_string(r) + ", r2 = " + std::to_string(r2) + ".";
    return type + start_point + params;
}
