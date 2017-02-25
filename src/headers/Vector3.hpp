#ifndef VECTOR3_H_
#define VECTOR3_H_

class Vector3 {

    public:
        double x;
        double y;
        double z;
    public:
        Vector3();
        Vector3(double x, double y, double z);
        Vector3(const Vector3& vec);

        Vector3 operator+(const Vector3& vec);
        const Vector3& operator+=(const Vector3& vec);
        Vector3 operator-(const Vector3& vec);
        const Vector3& operator-=(const Vector3& vec);
        Vector3 operator*(double scalar);
        const Vector3& operator*=(double scalar);
};

#endif