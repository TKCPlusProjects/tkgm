/// @file tkgm_localization.hpp
#ifndef tkgm_localization
#define tkgm_localization

#include <tkgm/tkgm_base.hpp>

namespace tkht
{
namespace tkgm
{
/// @brief 本地化对照表
struct Localization: JSON {
private:
  /// @brief 语言
  std::string language = "Chinese";
public:
  Localization(std::string path = std::string()) :
    JSON("localization.json", path) {
  }

  /// @brief 切换语言
  /// @param language 语言
  void check(std::string language);

  /// @brief 取文本
  /// @param id 文本id 
  /// @return 文本
  std::string string(std::string id);
};
}
}

#endif
