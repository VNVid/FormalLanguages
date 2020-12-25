#include "State.h"

bool operator<(const State& p, const State& q) {
  return (p.from < q.from) || (p.from == q.from && p.to < q.to) ||
         (p.from == q.from && p.to == q.to &&
          p.current_position < q.current_position) ||
         (p.from == q.from && p.to == q.to &&
          p.current_position == q.current_position &&
          p.origin_position < q.origin_position);
}