#include "circle.h"
Circle::Circle():Figure()
{
    this->r = 0;
}
Circle::Circle(Point p, float r):Figure(p, r)
{

}

Circle::~Circle(){

}

Point Circle::C(float t)
{
    float rad = t*PI/180;
    return Point(start.x + r*cos(rad), start.y + r*sin(rad), 0);
}

std::vector<float> Circle::DerivedAtPI4(){
    std::vector<float> result;
    float dxdt, dydt;
    dxdt = -r*sin(PI/4);
    dydt = r*cos(PI/4);
    result.push_back(dydt/dxdt);
    result.push_back(-dydt/dxdt);
    return result;
}

std::string Circle::WhoAmI()
{
    std::string type("Circle, ");
    std::string start_point = "center: (" + std::to_string(start.x) + ", " + std::to_string(start.y) + ", " + std::to_string(start.z) + "), ";
    std::string params  =  "r = " + std::to_string(r) + ".";
    return type + start_point + params;
}
