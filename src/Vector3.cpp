#include "headers/Vector3.hpp"

Vector3::Vector3() {
    x = 0;
    y = 0;
    z = 0;
}
Vector3::Vector3(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}
Vector3::Vector3(const Vector3& vec) {
    x = vec.x;
    y = vec.y;
    z = vec.z;
}
Vector3 Vector3::operator+(const Vector3& vec) {
    return Vector3(x+vec.x, y+vec.y, z+vec.z);
}
const Vector3& Vector3::operator+=(const Vector3& vec) {
    x += vec.x;
    y += vec.y;
    z += vec.z;
    return *this;
}
Vector3 Vector3::operator-(const Vector3& vec) {
    return Vector3(x-vec.x, y-vec.y, z-vec.z);
}
const Vector3& Vector3::operator-=(const Vector3& vec) {
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
    return *this;
}
Vector3 Vector3::operator*(double scalar) {
    return Vector3(x*scalar, y*scalar, z*scalar);
}
const Vector3& Vector3::operator*=(double scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}