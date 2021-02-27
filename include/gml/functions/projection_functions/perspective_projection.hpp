#ifndef GML_PERSPECTIVE_PROJECTION_HPP
#define GML_PERSPECTIVE_PROJECTION_HPP

#include <gml/matrix/matrix4.hpp>
#include <gml/functions/projection_functions/perspective_projection.h>

namespace gml{

  static mat4 perspective_projection(float left, float right, float bottom, float top, float near, float far, uint8_t return_major=GML_COLUMN_MAJOR){
    mat4 ret(return_major);
    ret.make_identity_matrix();

    gmlPerspectiveProjection((gmlMat4*)&ret, left, right, bottom, top, near, far);

    return ret;
  }

}

#endif //GML_PERSPECTIVE_PROJECTION_HPP
