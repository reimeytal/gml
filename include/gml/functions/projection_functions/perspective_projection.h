#ifndef GML_PERSPECTIVE_PROJECTION_H
#define GML_PERSPECTIVE_PROJECTION_H

#include <gml/matrix/matrix4.h>
#include <cmath>

static void gmlPerspective(float fov, float aspect_ratio, float* left, float* right, float* bottom, float* top, float near){
  *top = tan(fov/2)*near;
  *right = aspect_ratio * (*top);
  *left = -(*right);
  *bottom = -(*top);
}

static void gmlFrustum(gmlMat4* mat, float left, float right, float bottom, float top, float near, float far){
  gmlMat4SetElem(mat, 0, 0, (2*near)/(right-left));
  gmlMat4SetElem(mat, 0, 3, (-1*near*(right+left))/(right-left));
  gmlMat4SetElem(mat, 1, 1, (2*near)/(top-bottom));
  gmlMat4SetElem(mat, 1, 3, (-1*near*(top+bottom))/(top-bottom));

  gmlMat4SetElem(mat, 2, 2, (-1*(far+near))/(far-near));
  gmlMat4SetElem(mat, 2, 3, (2*far*near)/(near-far));

  gmlMat4SetElem(mat, 3, 2, -1);
  gmlMat4SetElem(mat, 3, 3, 0);
}

#endif //GML_PERSPECTIVE_PROJECTION_H
