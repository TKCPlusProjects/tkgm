#include <tkgm/tkgm_set_form.hpp>

namespace tkht {
namespace tkgm {
bool SetForm::Read() {
  ifstream file(filename);
  if (!file.is_open()) {
    Err("打开选项配置文件失败");
    return false;
  }

  nlohmann::json json;
  file >> json;

  for (shared_ptr<SetItem> item : items) {
    switch (item->type) {
    case SetItem::Type_Checkbox: {
      (dynamic_pointer_cast<CheckboxItem>(item))->Set(json[item->name]);
    } break;
    case SetItem::Type_SliderInt: {
      (dynamic_pointer_cast<SliderIntItem>(item))->Set(json[item->name]);
    } break;
    case SetItem::Type_SliderFloat: {
      (dynamic_pointer_cast<SliderFloatItem>(item))->Set(json[item->name]);
    } break;
    case SetItem::Type_KeyButton: {
      (dynamic_pointer_cast<KeyButtonItem>(item))->Set(json[item->name]);
    } break;
    default:
      break;
    }
  }

  file.close();
  return true;
}

bool SetForm::Write() {
  ofstream file(filename);
  if (!file.is_open()) {
    Err("打开选项配置文件失败");
    return false;
  }

  nlohmann::json json;
  for (shared_ptr<SetItem> item : items) {
    switch (item->type) {
    case SetItem::Type_Checkbox: {
      json[item->name] = (dynamic_pointer_cast<CheckboxItem>(item))->Get();
    } break;
    case SetItem::Type_SliderInt: {
      json[item->name] = (dynamic_pointer_cast<SliderIntItem>(item))->Get();
    } break;
    case SetItem::Type_SliderFloat: {
      json[item->name] = (dynamic_pointer_cast<SliderFloatItem>(item))->Get();
    } break;
    case SetItem::Type_KeyButton: {
      json[item->name] = (dynamic_pointer_cast<KeyButtonItem>(item))->Get();
    } break;
    default:
      break;
    }
  }

  file << setw(4) << json << endl;

  file.close();
  return true;
}

bool SetForm::Load() {
  SetupMap();
  bool ret = Read();
  if (!ret) {
    SetupDefault();
    ret = Write();
  }
  return ret;
}
} // namespace tkgm
} // namespace tkht
