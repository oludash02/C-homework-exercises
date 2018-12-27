#ifndef PROBLEM3_H
#define PROBLEM3_H

typedef struct {
  double x;
  double y;
} Point;

typedef struct {
  Point a;
  Point b;
  Point c;
} Triangle;

const Triangle* getLarger(const Triangle* first, const Triangle* second);

#endif
