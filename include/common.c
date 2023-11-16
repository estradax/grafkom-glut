#include "common.h"

#include <math.h>

struct vec2f vec2f_init(float x, float y) {
  struct vec2f ret = {x, y};
  return ret;
}

struct vec2f vec2f_add(struct vec2f a, struct vec2f b) {
  struct vec2f ret = {a.x + b.x, a.y + b.y};
  return ret;
}

struct vec2f vec2f_mul(struct vec2f a, struct vec2f b) {
  struct vec2f ret = {a.x * b.x, a.y * b.y};
  return ret;
}

struct translate translate_init(struct vec2f point, struct vec2f end) {
  struct translate ret;
  ret.point = point;
  ret.end = end;

  float dx = ret.end.x - ret.point.x;
  float dy = ret.end.y - ret.point.y;

  float abs_dx = fabsf(dx);
  float abs_dy = fabsf(dy);

  float r = abs_dy;
  if (abs_dx > abs_dy) {
    r = abs_dx; 
  }

  ret.r.x = dx / r;
  ret.r.y = dy / r;

  return ret;
}

void translate_step(struct translate *a) {
  if (a->point.x < a->end.x) {
    a->point.x += a->r.x / 100;
  }
  if (a->point.y < a->end.y) {
    a->point.y += a->r.y / 100;
  } 
}
