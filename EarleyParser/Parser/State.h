#ifndef STATE_H
#define STATE_H

#include <string>

/*
Each state is a tuple (X → α • β, i), consisting of

    the production currently being matched (X → α β) = (to → from)
    the current position in that production (represented by the dot)
    the position i in the input at which the matching of this production began:
the origin position
*/

struct State {
  char from;
  std::string to;
  size_t current_position;
  size_t origin_position;
  State(char from, std::string to, size_t cur_pos, size_t or_pos)
      : to(to),
        from(from),
        current_position(cur_pos),
        origin_position(or_pos) {}
};

bool operator<(const State& p, const State& q);

#endif
