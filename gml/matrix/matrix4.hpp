#ifndef GML_MATRIX4_HPP
#define GML_MATRIX4_HPP
#include <cstring>

#include <gml/matrix/matrix4.h>
#include <gml/vector/vector4.hpp>

namespace gml{
  class mat4{
  protected:
    float data[16];
    uint8_t major;
  public:
    mat4() = delete;
    
    mat4(uint8_t major)
      :major(major)
    {
      memset(data, 0, sizeof(float) * 16);
    }

    inline void make_identity_matrix(){
      gmlIdentityMat4((gmlMat4*)this);
    }

    inline void print() const{
      gmlPrintMat4((gmlMat4*)this);
    }

    mat4 operator+(mat4& otherMat){
      mat4 ret(this->major);
      gmlAddMat4((gmlMat4*)this, (gmlMat4*)&otherMat, (gmlMat4*)&ret);
      return ret;
    }

    mat4 operator*(mat4& otherMat){
      mat4 ret(this->major);
      gmlMultiplyMat4((gmlMat4*)this, (gmlMat4*)&otherMat, (gmlMat4*)&ret);
      return ret;
    }

    vec4 operator*(vec4& otherVec){
      return vec4(gmlMultiplyMat4Vec4((gmlMat4*)this, (gmlVec4*)&otherVec));
    }

    vec4 operator[](uint8_t i){
      return (vec4)gmlMat4GetRow((gmlMat4*)this, i);
    }
  };
}

#endif //GML_MATRIX4_HPP
