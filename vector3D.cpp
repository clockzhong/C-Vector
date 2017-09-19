#include <cmath>
#include <iostream>
#include "vector3D.h"

//because of the precisions problem, the float values couldn't be compared directly, so add this function: floatEqual()
//We could change the constant fEpsilon value to define the higher precision we need
bool floatEqual(float v1, float v2)
{
    const float fEpsilon = 0.0000000001;
    float fDelta;
    fDelta = fabs( v1 - v2 );
    if (fDelta<fEpsilon)
        return true;
    else
        return false;
}


Vector3D::Vector3D() 
{
    value[0] = 0;
    value[1] = 0;
    value[2] = 0; 
} 

Vector3D::Vector3D(float x, float y, float z) 
{
    value[0] = x;
    value[1] = y;
    value[2] = z;
} 

float* Vector3D::getValue()
{
    return value;
}

void Vector3D::setValue(float v0, float v1, float v2)
{
    value[0] = v0;
    value[1] = v1;
    value[2] = v2; 
}

float &Vector3D::operator[](int index) 
{
    if (index < 3 and index>=0 )
        return value[index];
    else
    {
        cout << "your index should be between 0 and 2, now we just return the 1st value\n";
        return value[0];
    }
}

float Vector3D::operator[](int index) const
{
    if (index < 3 and index>=0 )
        return value[index];
    else
    {
        cout << "your index should be between 0 and 2, now we just return the 1st value\n";
        return value[0];
    }
}

bool Vector3D::operator==(const Vector3D anotherVector)
{
    if (floatEqual(value[0], anotherVector[0]) && floatEqual(value[1], anotherVector[1]) && floatEqual(value[2], anotherVector[2]) )
        return true;
    else
        return false; 
}

Vector3D Vector3D::operator+(Vector3D anotherVector)
{
    Vector3D newVector(value[0]+anotherVector[0], value[1]+anotherVector[1], value[2]+anotherVector[2]);
    return newVector;
}

Vector3D Vector3D::operator-(Vector3D anotherVector)
{
    Vector3D newVector(value[0]-anotherVector[0], value[1]-anotherVector[1], value[2]-anotherVector[2]);
    return newVector;
}

Vector3D Vector3D::operator*(float scalar)
{
    Vector3D newVector(value[0]*scalar, value[1]*scalar, value[2]*scalar);
    return newVector;
}
Vector3D Vector3D::operator/(float scalar)
{
    Vector3D newVector(value[0]/scalar, value[1]/scalar, value[2]/scalar);
    return newVector;
}

float Vector3D::getMagnitude()
{
    return sqrt(value[0]*value[0]+value[1]*value[1]+value[2]*value[2]);
}

float Vector3D::getDistanceWith(Vector3D anotherVector)
{
    return ((*this)-anotherVector).getMagnitude();
}

float Vector3D::getDotProductWith(Vector3D anotherVector)
{
    return (value[0]*anotherVector[0]+value[1]*anotherVector[1]+value[2]*anotherVector[2]);
}

