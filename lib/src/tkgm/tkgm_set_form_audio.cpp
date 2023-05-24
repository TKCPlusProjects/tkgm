#include <tkgm/tkgm_set_form_audio.hpp>

namespace tkht {
namespace tkgm {
void SetFormAudio::SetupMap() {
  items.push_back(volume_main);
  items.push_back(volume_music);
  items.push_back(volume_effect);
}

void SetFormAudio::SetupDefault() {
  volume_main->Set(100.0f);
  volume_music->Set(100.0f);
  volume_effect->Set(100.0f);
}
} // namespace tkgm
} // namespace tkht
