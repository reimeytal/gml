#ifndef GML_RADIANS_HPP
#define GML_RADIANS_HPP

// 1 radian = 57.2958 degrees

#ifdef __cplusplus
namespace gml {

  static float to_radians(float degrees){
    return degrees/57.2958f;
  }

  static float to_degrees(float radians){
    return radians*57.2958f;
  }
} //namespace gml
#endif

static float gmlToRadians(float degrees){
  return degrees/57.2958f;
}

static float gmlToDegrees(float radians){
  return radians*57.2958f;
}

#endif //GML_RADIANS_HPP
