#ifndef tkgm_set_form_control_hpp
#define tkgm_set_form_control_hpp

#include <tkgm/tkgm_set_form.hpp>

namespace tkht {
namespace tkgm {
class SetFormControl : public SetForm {
public:
  shared_ptr<KeyButtonItem>move_up = make_shared<KeyButtonItem>("move_up", "Move Up");
  shared_ptr<KeyButtonItem>move_down = make_shared<KeyButtonItem>("move_down", "Move Down");
  shared_ptr<KeyButtonItem>move_left = make_shared<KeyButtonItem>("move_left", "Move Left");
  shared_ptr<KeyButtonItem>move_right = make_shared<KeyButtonItem>("move_right", "Move Right");

  shared_ptr<KeyButtonItem>listening = nullptr;

  SetFormControl() : SetForm("Control", "control.form") {}

  void Listen(shared_ptr<KeyButtonItem>listening);
  bool Listening();

  void SetupMap() override;
  void SetupDefault() override;
};
} // namespace tkgm
} // namespace tkht

#endif /* tkgm_set_form_control_hpp */
