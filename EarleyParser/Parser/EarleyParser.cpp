#include "EarleyParser.h"

bool EarleyParser::IsWordInLanguage(std::string word) {
  std::vector<std::set<State>> D(word.size() + 1);
  D[0].insert(State('Z', "S", 0, 0));

  for (size_t i = 0; i < word.size() + 1; i++) {
    Scan(i, D, word);
    bool changed1 = true, changed2 = true;
    while (changed1 || changed2) {
      changed1 = Predict(i, D, word);
      changed2 = Complete(i, D, word);
    }
  }

  if (D[word.size()].find(State('Z', "S", 1, 0)) != D[word.size()].end()) {
    return true;
  }
  return false;
}

void EarleyParser::Scan(size_t pos, std::vector<std::set<State>>& D,
                        const std::string& word) {
  if (pos == 0) {
    return;
  }
  for (auto state : D[pos - 1]) {
    if (state.current_position < state.to.size() &&
        state.to[state.current_position] == word[pos - 1]) {
      D[pos].insert(State(state.from, state.to, state.current_position + 1,
                          state.origin_position));
    }
  }
}
bool EarleyParser::Predict(size_t pos, std::vector<std::set<State>>& D,
                           const std::string& word) {
  std::vector<State> add;
  for (auto state : D[pos]) {
    if (state.current_position >= state.to.size()) {
      continue;
    }
    for (auto to : grammar_[state.to[state.current_position]]) {
      add.push_back(State(state.to[state.current_position], to, 0, pos));
    }
  }

  size_t prev_size = D[pos].size();
  for (auto state : add) {
    D[pos].insert(state);
  }

  if (prev_size == D[pos].size()) {
    return false;
  }
  return true;
}
bool EarleyParser::Complete(size_t pos, std::vector<std::set<State>>& D,
                            const std::string& word) {
  std::vector<State> add;
  for (auto state : D[pos]) {
    if (state.current_position == state.to.size()) {
      for (auto st : D[state.origin_position]) {
        if (st.current_position < st.to.size() &&
            st.to[st.current_position] == state.from) {
          add.push_back(State(st.from, st.to, st.current_position + 1,
                              st.origin_position));
        }
      }
    }
  }

  size_t prev_size = D[pos].size();
  for (auto state : add) {
    D[pos].insert(state);
  }

  if (prev_size == D[pos].size()) {
    return false;
  }
  return true;
}