#include <iostream>
#include <gml/gml.hpp>

int main(){

  gmlVec3 v = {1, 2, 3};
  printf("%f, %f, %f", GML_VEC3_TO_PARAMS(v));

  return EXIT_SUCCESS;
}
