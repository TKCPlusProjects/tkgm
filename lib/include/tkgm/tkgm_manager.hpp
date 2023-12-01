/// @file tkgm_manager.hpp
#ifndef tkgm_manager
#define tkgm_manager

#include <tkgm/tkgm_base.hpp>
#include <tkgm/tkgm_sequlist.hpp>
#include <tkgm/tkgm_module.hpp>
#include <tkgm/tkgm_localization.hpp>
#include <tkgm/tkgm_setting.hpp>

namespace tkht
{
namespace tkgm
{
/// @brief 管理器
class Manager {
TKHT_SIGNLETON(Manager);
private:
  /// @brief 模组表
  std::map<std::string, Module> module_map;
  /// @brief 本地化数据表
  std::map<std::string, Localization> localization_map;
  /// @brief 设置数据表
  std::map<std::string, Setting> setting_map;
public:
  /// @brief 模组顺序
  Sequlist sequlist;
  /// @brief 本地化数据
  Localization localization;
  /// @brief 设置数据
  Setting setting;
  
  /// @brief 清空数据
  void clear();
  /// @brief 加载数据
  void load(std::filesystem::path path = std::filesystem::path("."));
  /// @brief 保存模组顺序
  void save_sequlist();
  /// @brief 保存设置数据
  void save_setting();

  /// @brief 合并模组数据
  void merge();

  /// @brief 移动模组顺序
  /// @param from 起始位置
  /// @param to 目标位置
  void move(unsigned int from, unsigned int to);
};
}
}

#endif
