#ifndef GML_MATRIX4_H
#define GML_MATRIX4_H

#define GML_ROW_MAJOR    0
#define GML_COLUMN_MAJOR 1

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include <gml/vector/vector4.h>

typedef struct{
  float data[16];
  uint8_t major;
} gmlMat4;

void gmlCreateMat4(gmlMat4* mat, uint8_t major){
  if(major > 1){
    return;
  }
  *mat = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, major};
}

float gmlMat4GetElem(gmlMat4* mat, uint8_t i, uint8_t j){ //row, column
  if(j >= 4 || i >= 4){
    return 0.0f;
  }
  switch(mat->major){
    case GML_ROW_MAJOR:
      return mat->data[i * 4 + j];
    case GML_COLUMN_MAJOR:
      return mat->data[i + j*4];
    default:
      return 0.0f;
  }
}

float* gmlMat4GetElemPointer(gmlMat4* mat, uint8_t i, uint8_t j){ //row, column
  if(j >= 4 || i >= 4){
    return NULL;
  }
  switch(mat->major){
    case GML_ROW_MAJOR:
      return &mat->data[i * 4 + j];
    case GML_COLUMN_MAJOR:
      return &mat->data[i + j * 4];
    default:
      return NULL;
  }
}

void gmlMat4SetElem(gmlMat4* mat, uint8_t i, uint8_t j, float value){ //row, column, value
  *(gmlMat4GetElemPointer(mat, i, j)) = value;
}

gmlVec4 gmlMat4GetRow(gmlMat4* mat, uint8_t i){
  return {gmlMat4GetElem(mat, i, 0), gmlMat4GetElem(mat, i, 1), gmlMat4GetElem(mat, i, 2), gmlMat4GetElem(mat, i, 3)};
}

gmlVec4 gmlMat4GetColumn(gmlMat4* mat, uint8_t j){
  return {gmlMat4GetElem(mat, 0, j), gmlMat4GetElem(mat, 1, j), gmlMat4GetElem(mat, 2, j), gmlMat4GetElem(mat, 3, j)};
}

void gmlIdentityMat4(gmlMat4* mat){
  for(uint8_t i=0;i<4;i++){
    gmlMat4SetElem(mat, i, i, 1.0f);
  }
}

void gmlMat4RowToColumn(gmlMat4* mat){
  if(mat->major == GML_COLUMN_MAJOR){
    return;
  }

  gmlMat4 ret;
  gmlCreateMat4(&ret, GML_COLUMN_MAJOR);

  for(uint8_t i=0;i<4;i++){
    for(uint8_t j=0;j<4;j++){
      gmlMat4SetElem(&ret, i, j, gmlMat4GetElem(mat, i, j));
    }
  }
  *mat = ret;
}

void gmlMat4ColumnToRow(gmlMat4* mat){
  if(mat->major == GML_ROW_MAJOR){
    return;
  }

  gmlMat4 ret;
  gmlCreateMat4(&ret, GML_ROW_MAJOR);

  for(uint8_t i=0;i<4;i++){
    for(uint8_t j=0;j<4;j++){
      gmlMat4SetElem(&ret, i, j, gmlMat4GetElem(mat, i, j));
    }
  }
  *mat = ret;
}

void gmlAddMat4(gmlMat4* mat1, gmlMat4* mat2, gmlMat4* result){
  for(uint8_t i=0;i<4;i++){
    for(uint8_t j=0;j<4;j++){
      gmlMat4SetElem(result, i, j, gmlMat4GetElem(mat1, i, j) + gmlMat4GetElem(mat2, i, j));
    }
  }
}

void gmlMultiplyMat4(gmlMat4* mat1, gmlMat4* mat2, gmlMat4* result){
  for(uint8_t j=0;j<4;j++){
    for(uint8_t i=0;i<4;i++){
      gmlMat4SetElem(result, i, j, gmlVec4DotProduct(gmlMat4GetRow(mat2, i), gmlMat4GetColumn(mat1, j)));
    }
  }
}

gmlVec4 gmlMultiplyMat4Vec4(gmlMat4* mat, gmlVec4* vec){
  gmlVec4 ret;
  ret.x = gmlVec4DotProduct(gmlMat4GetRow(mat, 0), *vec);
  ret.y = gmlVec4DotProduct(gmlMat4GetRow(mat, 1), *vec);
  ret.z = gmlVec4DotProduct(gmlMat4GetRow(mat, 2), *vec);
  ret.w = gmlVec4DotProduct(gmlMat4GetRow(mat, 3), *vec);
  return ret;
}

void gmlPrintMat4(gmlMat4* mat){
  for(uint8_t i=0;i<4;i++){
    printf("| %10f %10f %10f %10f |\n", GML_VEC4_TO_PARAMS(gmlMat4GetRow(mat, i)));
  }
  fflush(stdout);
}

#endif //GML_MATRIX4_H
