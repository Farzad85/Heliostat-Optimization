#pragma once

#include <vector>

/* Code by Farzad Karami
    farzad.karami@gmail.com
*/

class Vector3
{

public:
    double X;
    double Y;
    double Z;
    Vector3(double* inputs);
    Vector3();
    double Dot(Vector3 other);
    Vector3 Add(Vector3 other);
    Vector3 Subtract(Vector3 other);
    Vector3 Normalize();
    double Norm2();
    Vector3 ScalerDivide(double other);
};
class ActuatedHeliostat
{
public:
    Vector3 location;
    Vector3 normal;
    ActuatedHeliostat(Vector3 Location, Vector3 Normal);
};

class HeliostatField
{
public:
    std::vector<ActuatedHeliostat> Heliostats;
public:
    void AddObj(ActuatedHeliostat obj);  
    void Track(Vector3 directionToSun, Vector3 targetLocation);
    double CosEfficiency(Vector3 directionToSun);
    
};

class OptimizableSpiralFieldGenerator
{
private:
    int ParameterCount;
    int get_ParameterCount()
    {
        return ParameterCount;
    };
public:
    HeliostatField Generate(int N, double a, double b);
};


