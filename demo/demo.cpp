#include <tkgm/tkgm.hpp>

int main(int argc, char** argv) {
  using namespace tkht;
  using namespace tkht::tkgm;

  Debug = true;
  SubscribeSignalList({SIGSEGV, SIGABRT});

  std::filesystem::path local(argv[0]);
  
  std::string path = local.parent_path().append("modules/core/localization.json").string();

  if (std::filesystem::path(path).filename() == std::string("localization.json")) {
    std::ifstream ifs(path);
    if (ifs.is_open()) {
      nlohmann::json data = nlohmann::json::parse(ifs);

      for (const auto& item : data.items()) { 
        if (item.value().is_object()) {
          for (const auto& _item : item.value().items()) { 
            std::cout << "Key: " << _item.key() << ", Value: " << _item.value() << std::endl;  
          }
        } else {
          std::cout << "Key: " << item.key() << ", Value: " << item.value() << std::endl;  
        }
      }  
      
      ifs.close();
    } else {
      Err("文件打开失败: %s", path.c_str());
    }
  }

  return 1;
}