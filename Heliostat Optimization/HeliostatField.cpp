#include "HeliostatField.h"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <math.h>


/* Code by Farzad Karami
    farzad.karami@gmail.com
*/

    Vector3::Vector3(double* inputs)
    {
        X = inputs[0];
        Y = inputs[1];
        Z = inputs[2];
    }
    Vector3::Vector3()
    {

    }
    double Vector3::Dot(Vector3 other)
    {
        return X * other.X + Y * other.Y + Z * other.Z;
    }
    Vector3 Vector3::Add(Vector3 other)

    {
        double arr[3] = { 0,0,0 };
        Vector3 result(arr);
        result.X = this->X + other.X;
        result.Y = this->Y + other.Y;
        result.Z = this->Z + other.Z;

        return result;
    }

    Vector3 Vector3::Subtract(Vector3 other)
    {
        double arr[3] = { 0,0,0 };
        Vector3 result(arr);
        result.X = this->X - other.X;
        result.Y = this->Y - other.Y;
        result.Z = this->Z - other.Z;

        return result;
    }

    Vector3 Vector3::Normalize()
    {
        double arr[3] = { 0,0,0 };
        Vector3 result(arr);
        result.X = X / sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2));
        result.Y = Y / sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2));
        result.Z = Z / sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2));
        return result;
    }

    double Vector3::Norm2()
    {
        return sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2));
    }
    Vector3 Vector3::ScalerDivide(double other)
    {
        double arr[3] = { 0,0,0 };
        Vector3 result(arr);
        result.X = X / other;
        result.Y = Y / other;
        result.Z = Z / other;
        return result;
    }






    ActuatedHeliostat::ActuatedHeliostat(Vector3 Location, Vector3 Normal)
    {
        location = Location;
        normal = Normal;
    }



    void HeliostatField::AddObj(ActuatedHeliostat obj)
    {
        this->Heliostats.push_back(obj);
    }
    void HeliostatField::Track(Vector3 directionToSun, Vector3 targetLocation)
    {

        auto iter = Heliostats.begin();
        for (; iter != Heliostats.end(); iter++)
        {
            Vector3 R = (*iter).location.Subtract(targetLocation).Normalize();
            (*iter).normal = R.Add(directionToSun).ScalerDivide(R.Add(directionToSun).Norm2());
        }
    }
    double HeliostatField::CosEfficiency(Vector3 directionToSun)
    {
        auto iter = Heliostats.begin();
        double projection = 0;
        int num = 0;
        for (; iter != Heliostats.end(); iter++)
        {
            projection += (*iter).normal.Dot(directionToSun);
            num += 1;
        }
        return projection / num;

    }



    HeliostatField OptimizableSpiralFieldGenerator::Generate(int N, double a, double b)
    {


        if (N < 1)
        {
            throw std::invalid_argument("N should be a positive integer larger than 1.");
        };

        const int num = N;


        std::vector<ActuatedHeliostat> ActuatedHeliostatList;
        double r;
        double theta;
        HeliostatField field;
        for (int i = 1; i < N + 1; i++)
        {

            r = a * pow(i, b);
            theta = i * 137.508 * 2 * acos(0.0) / 180;
            double arr1[] = { r * cos(theta), r * sin(theta), 0 };
            Vector3 location(arr1);
            double arr2[] = { 0, 0, 1 };
            Vector3 normal(arr2);
            ActuatedHeliostat actuatedHeliostat(location, normal);
            field.AddObj(actuatedHeliostat);

        };
        return field;
    }






