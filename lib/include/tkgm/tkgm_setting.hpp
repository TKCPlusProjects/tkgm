#ifndef tkgm_setting_hpp
#define tkgm_setting_hpp

#include <tkgm/tkgm_set_form_audio.hpp>
#include <tkgm/tkgm_set_form_control.hpp>
#include <tkgm/tkgm_set_form_video.hpp>

namespace tkht {
namespace tkgm {
extern shared_ptr<SetFormControl> control;
extern shared_ptr<SetFormVideo> video;
extern shared_ptr<SetFormAudio> audio;

vector<shared_ptr<SetForm>> Forms();

void Read();
void Write();
void Load();
} // namespace tkgm
} // namespace tkht

#endif /* tkgm_setting_hpp */
