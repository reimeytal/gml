#ifndef GML_PERSPECTIVE_PROJECTION_HPP
#define GML_PERSPECTIVE_PROJECTION_HPP

#include <gml/matrix/matrix4.hpp>
#include <gml/functions/projection_functions/perspective_projection.h>

namespace gml{

  static void perspective(float fov, float aspect_ratio, float* left, float* right, float* bottom, float* top, float near){
    gmlPerspective(fov, aspect_ratio, left, right, bottom, top, near);
  }

  static mat4 frustum(float left, float right, float bottom, float top, float near, float far){
    mat4 ret = mat4();
    ret.make_identity_matrix();

    gmlFrustum((gmlMat4*)&ret, left, right, bottom, top, near, far);

    return ret;
  }

}

#endif //GML_PERSPECTIVE_PROJECTION_HPP
