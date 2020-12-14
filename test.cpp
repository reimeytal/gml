#include <iostream>
#include <gml/gml.hpp>
#include <gml/gml.h>

int main(){

  gml::mat4 m(GML_COLUMN_MAJOR);
  m.make_identity_matrix();

  printf("%f\n", m[0][0]);

  return 0;
}
