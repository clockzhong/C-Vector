#include <iostream>
using std::ostream;
using std::cout;
using std::cin;
#include "vector3D.h"


int assertTrue(bool b)
{
    if (b)
    {
        cout << "success\n";
    }
    else
    {
        cout << "failure\n";
    }
}


int main()
{

    //Check the checking function()
    assertTrue(true);

    //Check the constructor 0
    {
        Vector3D v;
        assertTrue(floatEqual(v.getValue()[0],0));
        assertTrue(v.getValue()[1]== 0);
        assertTrue(v.getValue()[2]== 0);
    }

    //Check the constructor 1
    {
        Vector3D v(2,3,-1);
        assertTrue(v.getValue()[0]== 2);
        assertTrue(v.getValue()[1]== 3);
        assertTrue(v.getValue()[2]==-1);
    }


    //Check the setValue()
    {
        Vector3D v;
        v.setValue(1.1, 2.2, 3.3);
        assertTrue(floatEqual(v.getValue()[0],1.1));
        assertTrue(floatEqual(v.getValue()[1],2.2));
        assertTrue(floatEqual(v.getValue()[2],3.3));

    }

    //Check the operator[]
    {
        Vector3D v(1.1, 2.2, 3.3);
        assertTrue(floatEqual(v[0],1.1));
        assertTrue(floatEqual(v[1],2.2));
        assertTrue(floatEqual(v[2],3.3));
        v[2] = 8.8 ;
        assertTrue(floatEqual(v[2],8.8));
        
        //Check the error case
        assertTrue(floatEqual(v[3],1.1));
    }

    //Check the operator==
    {
        Vector3D v(1.1, 2.2, 3.3);
        Vector3D v1(1.1, 2.2, 3.3);
        Vector3D v12(1.11, 2.22, 3.33);

        assertTrue(v==v1);
        assertTrue(v1==v);
    }

    //Check the operator+
    {
        Vector3D v(1.1, 2.2, 3.3);
        Vector3D v1(1.1, 2.2, 3.3);
        Vector3D v3 = (v1+v);
        Vector3D sumValue(2.2, 4.4, 6.6);
        assertTrue(sumValue==(v1+v));
        assertTrue(sumValue==v3);
    }

    //Check the operator+
    {
        Vector3D v(2.2, 4.4, 6.6);
        Vector3D v1(1.1, 2.2, 3.3);
        Vector3D v2 = (v-v1);
        Vector3D subtractValue(1.1, 2.2, 3.3);
        assertTrue(subtractValue==(v-v1));
        assertTrue(subtractValue==v2);
    }

    //Check the operator * and /
    {
        Vector3D v(2.2, 4.4, 6.6);
        Vector3D v1(1.1, 2.2, 3.3);
        Vector3D v2 = v1*2;
        Vector3D v3 = v/2;
        assertTrue(v2==v);
        assertTrue(v3==v1);
    }

    //Check the getMagnitude(), getDistanceWith() and getDotProductWith()
    {
        Vector3D v(1.1, 2.2, 3.3);
        Vector3D v0(0, 0, 0);
        cout << v.getMagnitude() << "\n";
        assertTrue(floatEqual(v.getDistanceWith(v0),v.getMagnitude()));
        assertTrue(floatEqual(v0.getDistanceWith(v),v.getMagnitude()));
        assertTrue(floatEqual(v0.getDotProductWith(v),v0.getMagnitude()));
    }
   
    return 0;
}


