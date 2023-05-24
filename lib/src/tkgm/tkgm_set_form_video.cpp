#include <tkgm/tkgm_set_form_video.hpp>

namespace tkht {
namespace tkgm {
void SetFormVideo::SetupMap() {
  items.push_back(window_width);
  items.push_back(window_height);
  items.push_back(hertz);
  items.push_back(velocity_iterations);
  items.push_back(position_iterations);
  items.push_back(draw_shapes);
  items.push_back(draw_joints);
  items.push_back(draw_aabbs);
  items.push_back(draw_contactpoints);
  items.push_back(draw_contactnormals);
  items.push_back(draw_contactimpulse);
  items.push_back(draw_frictionimpulse);
  items.push_back(draw_coms);
  items.push_back(draw_stats);
  items.push_back(draw_profile);
  items.push_back(enable_warmstarting);
  items.push_back(enable_substepping);
  items.push_back(enable_continuous);
  items.push_back(enable_sleep);
}

void SetFormVideo::SetupDefault() {
  window_width->Set(1080);
  window_height->Set(720);
  hertz->Set(60.0f);
  velocity_iterations->Set(8);
  position_iterations->Set(3);
  draw_shapes->Set(true);
  draw_joints->Set(true);
  draw_aabbs->Set(false);
  draw_contactpoints->Set(false);
  draw_contactnormals->Set(false);
  draw_contactimpulse->Set(false);
  draw_frictionimpulse->Set(false);
  draw_coms->Set(false);
  draw_stats->Set(false);
  draw_profile->Set(false);
  enable_warmstarting->Set(true);
  enable_continuous->Set(true);
  enable_substepping->Set(false);
  enable_sleep->Set(true);
}
} // namespace tkgm
} // namespace tkht
