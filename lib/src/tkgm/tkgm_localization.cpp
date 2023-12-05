#include <tkgm/tkgm_localization.hpp>

namespace tkht
{
namespace tkgm
{
void Localization::clear() {
  JSON::clear();
}

void Localization::merge(Localization new_localization) {
  merge_patch(new_localization);
}

void Localization::check(std::string language) {
  if (contains(language)) {
    this->language = language;
  }
}

std::string Localization::string(std::string id) {
  return at(language)[id];
}
}
}
