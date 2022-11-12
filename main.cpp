#include "image.hpp"
#include "resize.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Need 1 argument" << std::endl;
    std::cerr << "Usage: ./resize image.jpg" << std::endl;
    return 0;
  }
  std::string src_name(argv[1]);
  auto image = LoadImage(src_name);
  float ratio = 2.f;
  auto image_after_resize = ResizeImage(image, ratio);

  int name_len = src_name.find_last_of('.');
  std::string dst_name = src_name.substr(0, name_len) + std::string("_2x") +
                         src_name.substr(name_len);

  StoreImage(image_after_resize, dst_name);
  return 0;
}