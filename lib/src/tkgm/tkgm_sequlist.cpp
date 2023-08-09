#include <tkgm/tkgm_sequlist.hpp>

namespace tkht
{
namespace tkgm
{
void Sequlist::move(unsigned int from, unsigned int to) {
  if (from == to || from >= size() || to >= size()) {
    Err("Sequlist移动顺序编号异常: %u -> %u", from, to);
    return;
  }

  insert(begin() + to, at(from));
  erase(begin() + from + 1);
}
}
}
