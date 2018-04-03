#include "trax.hpp"

#define TRI_N_WORDS 11 // 11 words for each triangle

// Utility function to store a color at a pixel offset in the frame buffer
inline void StorePixel(const int &fb, const int &pixel, const float &r, const float &g, const float &b) {
  storef(r, fb + pixel*3, 0);
  storef(g, fb + pixel*3, 1);
  storef(b, fb + pixel*3, 2);
}


class Vector {

public:
    float x, y, z;
    Vector(const float &x, const float &y, const float &z) :
        x(x), y(y), z(z) {}

    inline float norm() const {
        return sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
    }

    inline void normalize() {
        const float n =  this->norm();
        this->x /= n;
        this->y /= n;
        this->z /= n;
    }

    inline float dot(const Vector &v) const {
        return (this->x*v.x + this->y*v.y + this->z*v.z);
    }

    inline Vector* operator*(const float &s) const {
        return new Vector(this->x*s, this->y*s, this->z*s);
    }

    inline Vector* operator+(const Vector &v) const {
        return new Vector(this->x + v.x, this->y + v.y, this->z + v.z);
    }

    inline Vector* operator-(const Vector &v) const {
        return new Vector(this->x - v.x, this->y - v.y, this->z - v.z);
    }

    inline Vector* cross(const Vector &v) const {
        return new Vector(this->y * v.z - this->z * v.y,
                            -this->x * v.z + this->z * v.x,
                            this->x*v.y - this->y*v.x);
    }


};

void trax_main() {

}
