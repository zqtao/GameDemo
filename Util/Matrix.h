#ifndef GAMEDEMO_MATRIX_H
#define GAMEDEMO_MATRIX_H

typedef struct {
    float x;
    float y;
    float z;
} Vector3f;

typedef struct {
    float m[4][4];
} Matrix;

void MatrixScale(Matrix* result, float x, float y, float z);
void MatrixTranslate(Matrix* result, float x, float y, float z);
void MatrixRotate(Matrix* result, float angle, float x, float y, float z);
void MatrixFrustum(Matrix* result, float left, float right, float bottom, float top, float nearZ, float farZ);
void MatrixPerspective(Matrix* result, float fovy, float aspect, float nearZ, float farZ);
void MatrixOrtho(Matrix* result, float left, float right, float bottom, float top, float nearZ, float farZ);
void MatrixMultiply(Matrix* result, Matrix* srcA, Matrix* srcB);
void MatrixLoadIdentity(Matrix* result);
void MatrixLookAt(Matrix* result, float posX, float posY, float posZ,
        float lookAtX, float lookAtY, float lookAtZ,
        float upX, float upY, float upZ);


#endif //GAMEDEMO_MATRIX_H
