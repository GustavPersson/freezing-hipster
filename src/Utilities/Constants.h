#ifndef __UTILITIES__CONSTANTS_H__
#define __UTILITIES__CONSTANTS_H__

namespace utilities {
  namespace math {
    const float PI = 3.14159265f;
    const float PI_HALF = 1.57079633f;
    const float PI_QUARTER = 0.785398163f;
    const float PI_TWO = 6.28318531f;

    /**
    * Function that converts degrees to radians
    * @param degrees the number of degrees
    * @return the number of degrees in radians
    */
    inline float degToRad(float degrees) { return degrees / 360.0f * PI_TWO; }

    /**
    * Function that converts radians to degrees
    * @param radians the number of radians
    * @return the number of radians in degrees
    */
    inline float radToDeg(float radian) { return radian / PI_TWO * 360.0f; }
  }
}

#endif