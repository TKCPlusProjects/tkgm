#ifndef tkgm_set_form_audio_hpp
#define tkgm_set_form_audio_hpp

#include <tkgm/tkgm_set_form.hpp>

namespace tkht {
namespace tkgm {
class SetFormAudio : public SetForm {
public:
  shared_ptr<SliderFloatItem> volume_main =
      make_shared<SliderFloatItem>("volume_main", "Volume Main", 0.0f, 100.0f); // 主音量
  shared_ptr<SliderFloatItem> volume_music =
      make_shared<SliderFloatItem>("volume_music", "Volume Music", 0.0f, 100.0f); // 音乐音量
  shared_ptr<SliderFloatItem> volume_effect =
      make_shared<SliderFloatItem>("volume_effect", "Volume Effect", 0.0f, 100.0f); // 音效音量

  SetFormAudio() : SetForm("Audio", "audio.form") {}

  void SetupMap() override;
  void SetupDefault() override;
};
} // namespace tkgm
} // namespace tkht

#endif /* tkgm_set_form_audio_hpp */
