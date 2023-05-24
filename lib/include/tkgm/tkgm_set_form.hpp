#ifndef tkgm_set_form_hpp
#define tkgm_set_form_hpp

#include <tkgm/tkgm_set_item.hpp>

#include <fstream>
#include <nlohmann/json.hpp>

namespace tkht {
namespace tkgm {
class SetForm {
public:
  const char* name;
  const char* filename;
  vector<shared_ptr<SetItem>> items;

  SetForm(const char* name, const char* filename) : name(name), filename(filename) {}

  virtual void SetupMap() = 0;
  virtual void SetupDefault() = 0;

  bool Read();
  bool Write();
  bool Load();
};
} // namespace tkgm
} // namespace tkht

#endif /* tkgm_set_form_hpp */
