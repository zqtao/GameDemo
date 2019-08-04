#ifndef GAMEDEMO_VERTEX_H
#define GAMEDEMO_VERTEX_H

#include <vector>

using namespace std;

typedef struct {
    float x;
    float y;
    float z;
} Vertex;

typedef struct {
    float x;
    float y;
} UV;

typedef struct {
    float x;
    float y;
    float z;
} Normal;

typedef struct Point{
    Vertex vertex;
    UV uv;
    Normal normal;
    bool operator<(const Point that) const {
        return memcmp((void*)this, (void*)&that, sizeof(Point))>0;
    };
} Point;

typedef struct {
    vector<Vertex> vertex;
    vector<UV> uv;
    vector<Normal> normal;
} Mesh;

#endif //GAMEDEMO_VERTEX_H
