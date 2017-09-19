#ifndef __VECTOR3D_H__
#define __VECTOR3D_H__

#include <cmath>
#include <iostream>
using std::ostream;
using std::cout;
using std::cin;


//because of the precisions, the float values couldn't be compared directly, so add this function: floatEqual()
bool floatEqual(float v1, float v2);

class Vector3D 
{
    private:
        float value[3];
    public:
        Vector3D(float x, float y, float z); 
        Vector3D();

        float* getValue();
        void setValue(float v0, float v1, float v2);

        float &operator[](int index);
        float operator[](int index) const;

        bool operator==(const Vector3D anotherVector);

        Vector3D operator+(Vector3D anotherVector);
        Vector3D operator-(Vector3D anotherVector);

        Vector3D operator*(float scalar);
        Vector3D operator/(float scalar);

        float getMagnitude();
        float getDistanceWith(Vector3D anotherVector);
        float getDotProductWith(Vector3D anotherVector);
};

#endif
