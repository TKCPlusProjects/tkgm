/// @file tkgm_sequlist.hpp
#ifndef tkgm_sequlist
#define tkgm_sequlist

#include <tkgm/tkgm_base.hpp>

namespace tkht
{
namespace tkgm
{
/// @brief 模组顺序
struct Sequlist: JSON {
  Sequlist(std::string path = std::string()) :
    JSON("sequlist.json", path) {
  }

  void clear();
  
  void move(unsigned int from, unsigned int to);
};
}
}

#endif
