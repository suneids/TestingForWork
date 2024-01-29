#include "helix.h"

Helix::Helix():Circle()
{

}

Helix::Helix(Point p, float r, float step):Circle(p, r)
{
    this->step = step*2*PI;
}

Helix::~Helix(){

}

Point Helix::C(float t)
{
    float rad = t*PI/180;
    return Point(start.x + r*cos(rad), start.y +r*sin(rad), start.z + step*rad/(2*PI));
}

std::vector<float> Helix::DerivedAtPI4(){
    std::vector<float> result;
    float dxdr, dydr, dzdr;
    dxdr = -r*sin(PI/4);
    dydr = r*cos(PI/4);
    dzdr = step/(2*PI);
    result.push_back(dxdr);
    result.push_back(dydr);
    result.push_back(dzdr);
    return result;
}


std::string Helix::WhoAmI()
{
    std::string type("Helix, ");
    std::string start_point = "center: (" + std::to_string(start.x) + ", " + std::to_string(start.y) + ", " + std::to_string(start.z) + "), ";
    std::string params  =  "r = " + std::to_string(r) + ", step = PI*" + std::to_string(step/PI) + ".";
    return type + start_point + params;
}
