#include <iostream>
#include <gml/gml.hpp>
#include <gml/gml.h>

int main(){

  gml::mat4 m = gml::mat4();
  m.make_identity_matrix();
  m.scale(2, 0, 0);
  m.rotate(gml::to_radians(90), GML_X);
  m.print();
  m.rotate(gml::to_radians(70), GML_Y);
  m.print();

  return 0;
}
