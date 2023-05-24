#include <tkgm/tkgm_setting.hpp>

namespace tkht {
namespace tkgm {
shared_ptr<SetFormControl> control = make_shared<SetFormControl>();
shared_ptr<SetFormVideo> video = make_shared<SetFormVideo>();
shared_ptr<SetFormAudio> audio = make_shared<SetFormAudio>();

vector<shared_ptr<SetForm>> Forms() {
  return {control,video,audio};
}

void Read() {
  for (shared_ptr<SetForm> form : Forms()) {
    form->Read();
  }
}
void Write() {
  for (shared_ptr<SetForm> form : Forms()) {
    form->Write();
  }
}
void Load() {
  for (shared_ptr<SetForm> form : Forms()) {
    form->Load();
  }
}
} // namespace tkgm
} // namespace tkht
