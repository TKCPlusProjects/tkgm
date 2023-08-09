/// @file tkgm_setting.hpp
#ifndef tkgm_setting
#define tkgm_setting

#include <tkgm/tkgm_base.hpp>

namespace tkht
{
namespace tkgm
{
/// @brief 设置
struct Setting : JSON {
  Setting(std::string path = std::string()) :
    JSON("setting.json", path) {
  }
};
}
}

#endif
