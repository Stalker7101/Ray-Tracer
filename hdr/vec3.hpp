#include <cmath>
#include <iostream>

enum VecMode {Vector3, RGB};

// declaration

template <VecMode M = Vector3>
class vec3 {

public:

    vec3();
    vec3(double e0, double e1, double e2);

    double x() const;
    double y() const;
    double z() const;

    vec3<M> operator -  ()      const;
    double  operator [] (int i) const;
    double& operator [] (int i);

    vec3<M>& operator += (const vec3<M>& v);
    vec3<M>& operator -= (const vec3<M>& v);
    vec3<M>& operator *= (const double t);
    vec3<M>& operator /= (const double t);

    operator vec3<RGB>() const;

    double length()         const;
    double length_squared() const;

    ~vec3() = default;

protected:

    double e[3];
};

// aliases for vec3
using point3 = vec3<>; // 3D point
using color  = vec3<RGB>; // RGB color

// definition

template <VecMode M>
vec3<M>::vec3() : e{0, 0, 0} {}

template <VecMode M>
vec3<M>::vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

template <VecMode M>
double vec3<M>::x() const {

    return e[0];
}

template <VecMode M>
double vec3<M>::y() const {

    return e[1];
}

template <VecMode M>
double vec3<M>::z() const {

    return e[2];
}

template <VecMode M>
vec3<M> vec3<M>::operator - () const {

    return vec3<M>(-e[0], -e[1], -e[2]);
}

template <VecMode M>
double vec3<M>::operator [] (int i) const {

    return e[i];
}

template <VecMode M>
double& vec3<M>::operator [] (int i) {

    return e[i];
}

template <VecMode M>
vec3<M>& vec3<M>::operator += (const vec3<M>& v) {

    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];

    return * this;
}

template <VecMode M>
vec3<M>& vec3<M>::operator -= (const vec3<M>& v) {

    e[0] -= v.e[0];
    e[1] -= v.e[1];
    e[2] -= v.e[2];

    return * this;
}

template <VecMode M>
vec3<M>& vec3<M>::operator *= (const double t) {

    e[0] *= t;
    e[1] *= t;
    e[2] *= t;

    return * this;
}

template <VecMode M>
vec3<M>& vec3<M>::operator /= (const double t) {

    return (* this) *= (1/t);
}

template <VecMode M>
vec3<M>::operator vec3<RGB>() const {

    return vec3<RGB>(e[0], e[1], e[2]);
}

template <VecMode M>
double vec3<M>::length_squared() const {

    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

template <VecMode M>
double vec3<M>::length() const {

    return std::sqrt(length_squared());
}

template <VecMode M>
inline std::ostream& operator << (std::ostream& out, const vec3<M>& v) {

    return out << v[0] << ' ' << v[1] << ' ' << v[2];
}

template <VecMode M>
inline vec3<M> operator + (const vec3<M>& u, const vec3<M>& v) {

    vec3<M> temp(u);
    temp += v;
    return temp;
}

template <VecMode M>
inline vec3<M> operator - (const vec3<M>& u, const vec3<M>& v) {

    vec3<M> temp(u);
    temp -= v;
    return temp;
}

template <VecMode M>
inline vec3<M> operator * (const vec3<M>& u, const vec3<M>& v) {

    return vec3<M>(u[0] * v[0], u[1] * v[1], u[2] * v[2]);
}

template <VecMode M>
inline vec3<M> operator * (const double t, const vec3<M>& v) {

    vec3<M> temp(v);
    temp *= t;
    return temp;
}

template <VecMode M>
inline vec3<M> operator * (const vec3<M>& v, const double t) {

    return t * v;
}

template <VecMode M>
inline vec3<M> operator / (const vec3<M>& v, const double t) {

    return (1/t) * v;
}

template <VecMode M>
inline double dot(const vec3<M>& u, const vec3<M>& v) {

    return u[0] * v[0]
         + u[1] * v[1]
         + u[2] * v[2];
}

template <VecMode M>
inline vec3<M> cross(const vec3<M>& u, const vec3<M>& v) {

    return vec3<M>(u[1] * v[2] - u[2] * v[1],
                   u[2] * v[0] - u[0] * v[2],
                   u[0] * v[1] - u[1] * v[0]);
}

template <VecMode M>
inline vec3<M> unit_vector(const vec3<M>& v) {

    return v / v.length();
}
