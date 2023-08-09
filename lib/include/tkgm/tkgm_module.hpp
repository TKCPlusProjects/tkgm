/// @file tkgm_module.hpp
#ifndef tkgm_module
#define tkgm_module

#include <tkgm/tkgm_base.hpp>

namespace tkht
{
namespace tkgm
{
/// @brief 模组
struct Module: JSON {
  Module(std::string path = std::string()) :
    JSON("module.json", path) {
  }
};
}
}

#endif
