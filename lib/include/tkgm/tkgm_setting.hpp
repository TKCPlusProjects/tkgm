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
  struct Item {
    /// @brief 设置选项类型
    enum Type {
      Keybutton,   ///< 按键绑定
      Checkbox,    ///< 勾选框
      Slideint,    ///< 整型数
      Slidefloat,  ///< 浮点数
    };
    /// @brief 选项类型
    Type type;

    /// @brief 选项名称id
    std::string name;
    /// @brief JSON指针
    std::shared_ptr<nlohmann::json> json_ptr;

    Item(nlohmann::json json = nullptr);
  };

  /// @brief 设置选项
  /// @tparam T 值类型
  template <typename T> struct TypeItem: Item {
    T default_value, value;

    TypeItem(nlohmann::json json): Item(json) {
      default_value = json["default"];
      value = json["value"];
    }

    virtual void SetValue(T new_value) {
      value = new_value;
      json_ptr->at("value") = value;
    }
    virtual void ResetValue() {
      value = default_value;
      json_ptr->at("value") = value;
    }
  };

  /// @brief 设置选项
  /// @tparam T 值类型
  template <typename T> struct IntervalTypeItem: TypeItem<T> {
    T min, max;

    IntervalTypeItem(nlohmann::json json): TypeItem<T>(json) {
      min = json["min"];
      max = json["max"];
    }

    virtual void SetValue(T new_value) override {
      if (min <= new_value || new_value <= max) TypeItem<T>::SetValue(new_value);
      else if (new_value < min) TypeItem<T>::SetValue(min);
      else if (new_value > max) TypeItem<T>::SetValue(max);
    }
  };
  
  /// @brief 设置选项 按键绑定
  struct Keybutton: TypeItem<int> {
    Keybutton(nlohmann::json json):TypeItem<int>(json) { type = Item::Type::Keybutton; }
  };
  /// @brief 设置选项 勾选框
  struct Checkbox: TypeItem<int> {
    Checkbox(nlohmann::json json):TypeItem<int>(json) { type = Item::Type::Checkbox; }
  };
  /// @brief 设置选项 整型数
  struct Slideint: IntervalTypeItem<int> {
    Slideint(nlohmann::json json):IntervalTypeItem<int>(json) { type = Item::Type::Slideint; }
  };
  /// @brief 设置选项 浮点数
  struct Slidefloat: IntervalTypeItem<float> {
    Slidefloat(nlohmann::json json):IntervalTypeItem<float>(json) { type = Item::Type::Slidefloat; }
  };

  /// @brief 设置小组
  struct Group {
    /// @brief 小组名称id
    std::string name;
    /// @brief 选项列表
    std::vector<std::shared_ptr<Item>> item_list;

    Group(nlohmann::json json);
  };

  /// @brief 设置选项卡
  struct Tab {
    /// @brief 选项卡名称id
    std::string name;
    /// @brief 小组列表
    std::vector<std::shared_ptr<Group>> group_list;

    Tab(nlohmann::json json);
  };

  /// @brief 选项卡列表
  std::vector<std::shared_ptr<Tab>> tab_list;

  Setting(std::string path = std::string()) :
    JSON("setting.json", path) {
  }

  void merge(Setting new_setting);
};
}
}

#endif
