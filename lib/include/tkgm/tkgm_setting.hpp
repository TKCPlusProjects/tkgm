/// @file tkgm_setting.hpp
#ifndef tkgm_setting
#define tkgm_setting

#include <tkgm/tkgm_base.hpp>

namespace tkht
{
namespace tkgm
{
/// @brief 设置
struct Setting: JSON {
  /// @brief 设置选项
  struct Item: JSON {
    /// @brief 设置选项类型
    enum Type {
      Keybutton,   ///< 按键绑定
      Checkbox,    ///< 勾选框
      Slideint,    ///< 整型数
      Slidefloat,  ///< 浮点数
    };
    /// @brief 选项类型
    Type type;

    /// @brief 选项序号
    std::vector<std::string> key_link;
    /// @brief 选项名称id
    std::string name;

    Item(std::vector<std::string> key_link, nlohmann::json json = nullptr);
  };

  /// @brief 设置选项
  /// @tparam T 值类型
  template <typename T> struct TypeItem: Item {
    T default_value, value;

    TypeItem(std::vector<std::string> key_link, nlohmann::json json): Item(key_link, json) {
      default_value = at("default");
      value = at("value");
    }

    virtual void SetValue(T new_value) {
      value = new_value;
      at("value") = value;
    }
    virtual void ResetValue() {
      value = default_value;
      at("value") = value;
    }
  };

  /// @brief 设置选项
  /// @tparam T 值类型
  template <typename T> struct IntervalTypeItem: TypeItem<T> {
    T min, max;

    IntervalTypeItem(std::vector<std::string> key_link, nlohmann::json json): TypeItem<T>(key_link, json) {
      min = at("min");
      max = at("max");
    }

    virtual void SetValue(T new_value) override {
      if (min <= new_value || new_value <= max) TypeItem<T>::SetValue(new_value);
      else if (new_value < min) TypeItem<T>::SetValue(min);
      else if (new_value > max) TypeItem<T>::SetValue(max);
    }
  };
  
  /// @brief 设置选项 按键绑定
  struct Keybutton: TypeItem<int> {
    Keybutton(std::vector<std::string> key_link, nlohmann::json json):TypeItem<int>(key_link, json) { type = Item::Type::Keybutton; }
  };
  /// @brief 设置选项 勾选框
  struct Checkbox: TypeItem<int> {
    Checkbox(std::vector<std::string> key_link, nlohmann::json json):TypeItem<int>(key_link, json) { type = Item::Type::Checkbox; }
  };
  /// @brief 设置选项 整型数
  struct Slideint: IntervalTypeItem<int> {
    Slideint(std::vector<std::string> key_link, nlohmann::json json):IntervalTypeItem<int>(key_link, json) { type = Item::Type::Slideint; }
  };
  /// @brief 设置选项 浮点数
  struct Slidefloat: IntervalTypeItem<float> {
    Slidefloat(std::vector<std::string> key_link, nlohmann::json json):IntervalTypeItem<float>(key_link, json) { type = Item::Type::Slidefloat; }
  };

  /// @brief 设置小组
  struct Group: JSON {
    /// @brief 小组名称id
    std::string name;
    /// @brief 选项列表
    std::vector<std::shared_ptr<Item>> item_list;

    Group(std::vector<std::string> key_link, nlohmann::json json);
  };

  /// @brief 设置选项卡
  struct Tab: JSON {
    /// @brief 选项卡名称id
    std::string name;
    /// @brief 小组列表
    std::vector<std::shared_ptr<Group>> group_list;

    Tab(std::vector<std::string> key_link, nlohmann::json json);
  };

  /// @brief 选项卡列表
  std::vector<std::shared_ptr<Tab>> tab_list;

  Setting(std::string path = std::string()) :
    JSON("setting.json", path) {
  }

  void clear();
  
  void merge(std::vector<std::string> key_link, Setting new_setting);
};
}
}

#endif
