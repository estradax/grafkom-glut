#ifndef COMMON_H_ 
#define COMMON_H_

struct vec2f {
  float x;
  float y;
};

struct vec2f vec2f_init(float, float);
struct vec2f vec2f_add(struct vec2f, struct vec2f);
struct vec2f vec2f_mul(struct vec2f, struct vec2f);

struct translate {
  struct vec2f point;
  struct vec2f end;
  struct vec2f r;
};

struct translate translate_init(struct vec2f, struct vec2f);
void translate_step(struct translate *);

#endif
