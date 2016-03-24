//
// Created by Richard Au on 3/20/2016.
//

#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>
#include "Cluster.h"
using namespace Clustering;
namespace Clustering
{
    unsigned int Point::__idGen = 0;
    Point::Point(int Dim)
    {
        __dim = Dim;
        __values = new double[__dim];
        for (int counter = 0;
             counter < __dim;
             counter++)
            __values[counter] = 0;
        __id=__idGen++;
    }
    Point::Point(int __newDim, double *__newValue)
    {
        __dim = __newDim;
        __values = __newValue;
        __id=__idGen++;
    }
    // Cpy Const:
    Point::Point(const Point &copy)
    {
        __dim = copy.__dim;
        __values = new double[__dim];
        int counter = 0;
        while (counter < __dim)
        {
            __values[counter] = copy.__values[counter];
            __id = copy.__id;
            counter++;
        }
    }
    Point &Clustering::Point::operator=(const Point &rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        else
        {
            if (__dim == rhs.__dim)
                for (int counter = 0;
                     counter < __dim;
                     counter++)
                {
                    __values[counter] = rhs.__values[counter];
                }
        }
        return *this;
    }
    //Destructor:
    Point::~Point()
    { delete[] __values; }
//**************************************************
//                  Getter and Setters
//
// task:    Allow outside functions to access private
//          variable inside Point class
//
//***************************************************
    int Point::getId() const
    { return __id; }
    int Point::getDims() const
    { return __dim; }
    void Point::setValue(int index, double newValue)
    { __values[index] = newValue; }
    double Point::getValue(int index) const
    { return __values[index]; }
//**************************************************
//                  distanceTo
//
// task:    Caculate distance between points
// Postcondition: Takes in an point as an parameter
//
//***************************************************
    double Point::distanceTo(const Point &point) const
    {
        double distance = 0;
        double holder = 0;
        for (int counter = 0;
             counter < point.__dim;
             counter++)
            holder += (pow(point.__values[counter] - __values[counter], 2));
        distance = sqrt(holder);
        return distance;
    }
//**************************************************
//                  *= Operator
//***************************************************
    Point &Point::operator*=(double rhs)
    {
        for (int counter = 0;
             counter < __dim;
             counter++)
            __values[counter] *= rhs;
        return *this;
    }
//**************************************************
//                  /= Operator
//***************************************************
    Point &Point::operator/=(double point)
    {
        for (int counter = 0;
             counter < __dim;
             counter++)
            __values[counter] /= point;
        return *this;
    }
//**************************************************
//                  * Operator
//***************************************************
    const Point Point::operator*(double point) const
    { return Point(*this) *= point; }
//**************************************************
//                  / Operator
//***************************************************
    const Point Point::operator/(double rhs) const
    { return Point(*this) /= rhs; }
//**************************************************
//                  [] Operator
//***************************************************
    double &Point::operator[](int index)
    { return __values[index]; }
//**************************************************
//                  += Operator
//***************************************************
    Point &operator+=(Point &lhs, const Point &rhs)
    {
        if (&lhs == &rhs)
        {
            for (int counter = 0;
                 counter < lhs.__dim;
                 counter++)
                lhs.__values[counter] += rhs.__values[counter];
        }
        else if (lhs.__dim == rhs.__dim)
        {
            for (int counter = 0;
                 counter < lhs.__dim;
                 counter++)
                lhs.__values[counter] += rhs.__values[counter];
        }
        return lhs;
    }
//**************************************************
//                  -= Operator
//***************************************************
    Point &operator-=(Point &lhs, const Point &rhs)
    {
        if (&lhs == &rhs)
        {
            for (int counter = 0;
                 counter < lhs.__dim;
                 counter++)
            {
                lhs.__values[counter] = 0;
            }
        }
        else if (lhs.__dim == rhs.__dim)
        {
            for (int counter = 0;
                 counter < lhs.__dim;
                 counter++)
                lhs.__values[counter] -= rhs.__values[counter];
        }
        return lhs;
    }
//**************************************************
//                  + Operator
//***************************************************
    const Point operator+(const Point &lhs, const Point &rhs)
    {
        Point p(lhs);
        return p += rhs;
    }
//**************************************************
//                  - Operator
//***************************************************
    const Point operator-(const Point &lhs, const Point &rhs)
    {
        Point p(lhs);
        return p -= rhs;
    }
//**************************************************
//                  == Operator
//***************************************************
    bool operator==(const Point &lhs, const Point &rhs)
    {
        bool equal = true;
        if(lhs.__id !=rhs.__id)
            equal=false;
        else
        {
            for(int counter =0;
                counter < lhs.__dim;
                counter++)
                if(lhs.__values[counter] != rhs.__values[counter])
                    equal=false;
        }
        return equal;
    }
//**************************************************
//                  != Operator
//***************************************************
    bool operator!=(const Point &lhs, const Point &rhs)
    { return !operator==(lhs, rhs); }
//**************************************************
//                  < Operator
//***************************************************
    bool operator<(const Point &lhs, const Point &rhs)
    {
        bool less = false;
        for (int counter = 0;
             counter < lhs.__dim;
             counter++)
        {
            if (lhs.__values[counter] < rhs.__values[counter])
                return true;
            if(lhs.__values[counter] > rhs.__values[counter])
                return false;
        }
        return less;
    }
//**************************************************
//                  > Operator
//***************************************************
    bool operator>(const Point &lhs, const Point &rhs)
    { return operator<(rhs, lhs); }
//**************************************************
//                  <= Operator
//***************************************************
    bool operator<=(const Point &lhs, const Point &rhs)
    { return !operator>(lhs, rhs); }
//**************************************************
//                  >= Operator
//***************************************************
    bool operator>=(const Point &lhs, const Point &rhs)
    { return !operator<(lhs, rhs); }
//**************************************************
//                  << Operator
//***************************************************
    std::ostream &operator<<(std::ostream &os, const Point &point)
    {
        unsigned int counter =0;
        for(;
                counter < point.__dim - 1;
                counter++)
            os << point.__values[counter] << ", ";
        os << point.__values[counter];
        return os;
    }
//**************************************************
//                  >> Operator
//***************************************************
    std::istream &operator>>(std::istream &in, Point &point)
    {
        std::string holder;
        double d;
        for(int counter =0;
            counter < point.__dim;
            counter++)
        {
            getline(in, holder, ',');
            std::stringstream inputstring(holder);
            inputstring>>d;
            point.__values[counter] = d;
        }
        return in;
    }
}