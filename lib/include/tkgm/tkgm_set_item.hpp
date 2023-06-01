#ifndef tkgm_set_item_hpp
#define tkgm_set_item_hpp

#include <tkgm/tkgm_base.hpp>

namespace tkht {
namespace tkgm {
class SetItem {
public:
  enum Type {
    Type_Unknow = 0,
    Type_Checkbox = 1,
    Type_SliderInt = 2,
    Type_SliderFloat = 3,
    Type_KeyButton = 4,
  };
  Type type = Type_Unknow;
  const char* name;
  const char* title;
  const char* label;

  virtual ~SetItem() {}
  SetItem(Type _type, const char* _name, const char* _title)
      : type(_type), name(_name), title(_title) {
        label = ("##" + string(title)).c_str();
      }
};

template <typename T> class SetItemTmpl : public SetItem {
public:
  T value;

  SetItemTmpl(Type _type, const char* _name, const char* _title) : SetItem(_type, _name, _title) {}

  virtual void OnSet(){};
  virtual void Set(T _value) {
    value = _value;
    OnSet();
  }

  virtual void OnGet(){};
  virtual const T Get() {
    OnGet();
    return value;
  }
};

class CheckboxItem : public SetItemTmpl<bool> {
public:
  CheckboxItem(const char* _name, const char* _title) : SetItemTmpl(Type_Checkbox, _name, _title) {}
};

class SliderIntItem : public SetItemTmpl<int> {
public:
  int min, max;
  SliderIntItem(const char* _name, const char* _title, int _min, int _max)
      : SetItemTmpl(Type_SliderInt, _name, _title), min(_min), max(_max) {}
};

class SliderFloatItem : public SetItemTmpl<float> {
public:
  float min, max;
  SliderFloatItem(const char* _name, const char* _title, float _min, float _max)
      : SetItemTmpl(Type_SliderFloat, _name, _title), min(_min), max(_max) {}
};

class KeyButtonItem : public SetItemTmpl<ImGuiKey> {
public:
  const char *name;
  KeyButtonItem(const char* _name, const char* _title) : SetItemTmpl(Type_KeyButton, _name, _title) {}
  void OnSet() override { name = value == 0 ? "None" : ImGui::GetKeyName(value); }
};
} // namespace tkgm
} // namespace tkht

#endif /* tkgm_set_item_hpp */
