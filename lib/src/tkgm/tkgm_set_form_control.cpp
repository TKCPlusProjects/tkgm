#include <tkgm/tkgm_set_form_control.hpp>

namespace tkht {
namespace tkgm {
void SetFormControl::Listen(shared_ptr<KeyButtonItem>listening) {
  this->listening = listening;
}
bool SetFormControl::Listening() {
  if (listening == nullptr) return false;
  
  for (ImGuiKey key = ImGuiKey_NamedKey_BEGIN; key < ImGuiKey_NamedKey_END; key = (ImGuiKey)(key + 1)) {
    if (ImGui::IsKeyPressed(key)) {
      switch (key) {
      case ImGuiKey_Enter: break;
      case ImGuiKey_Escape: listening->Set(ImGuiKey_None); break;
      default: listening->Set(key); break;
      }
      listening = nullptr;
    }
  }
  return true;
}

void SetFormControl::SetupMap() {
  items.push_back(move_up);
  items.push_back(move_down);
  items.push_back(move_left);
  items.push_back(move_right);
}

void SetFormControl::SetupDefault() {
  move_up->Set(ImGuiKey_W);
  move_down->Set(ImGuiKey_S);
  move_left->Set(ImGuiKey_A);
  move_right->Set(ImGuiKey_D);
}
} // namespace tkgm
} // namespace tkht
