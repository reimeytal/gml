#include <iostream>
#include <gml/gml.hpp>
#include <gml/gml.h>

int main(){

  gmlMat4 m1;
  gmlVec4 vec = {3.f, 2.f, 4.f, 1.f};
  gmlVec4 newVec;

  gmlCreateMat4(&m1, GML_COLUMN_MAJOR);
  gmlIdentityMat4(&m1);

  newVec = gmlMultiplyMat4Vec4(&m1, &vec);
  printf("(%f, %f, %f, %f)\n", GML_VEC4_TO_PARAMS(newVec));

  return 0;
}
