#include <fstream>
#include <iostream>
#include <string>

const std::string PATH_WAL = "/home/poiso/.cache/wal/colors";
const std::string PATH_CFG = "/home/poiso/.config/mango/config.conf";
const std::string PATH_NEW_CFG = "/home/poiso/.config/mango/config.new.conf";

std::string getColor1();
std::string getColor5();
void replace_colors(std::string, std::string);

int main() {
  std::string c5 = getColor5();
  std::string c1 = getColor1();
  replace_colors(c1, c5);
}

void replace_colors(std::string color1, std::string color5) {
  std::ifstream cfg(PATH_CFG);
  std::ofstream modified_cfg(PATH_NEW_CFG);
  std::string tmp;
  if (!cfg || !modified_cfg) {
    std::cout << "Error opening a file" << std::endl;
  }
  cfg >> tmp;
  cfg >> tmp;
  modified_cfg << "bordercolor=" + color5 + "\n";
  modified_cfg << "focuscolor=" + color1;
  std::string str;
  while (std::getline(cfg, str)) {
    modified_cfg << str + "\n";
  }
  cfg.close();
  modified_cfg.close();
  std::remove("/home/poiso/.config/mango/config.conf");
  std::rename("/home/poiso/.config/mango/config.new.conf",
              "/home/poiso/.config/mango/config.conf");
}

std::string getColor1() {
  std::ifstream ifile;
  std::string color1;
  ifile.open(PATH_WAL);
  if (ifile.is_open()) {
    std::getline(ifile, color1);
    std::getline(ifile, color1);
  }
  ifile.close();
  color1.erase(0, 1);
  color1 = "0x" + color1 + "ff";
  return color1;
}

std::string getColor5() {
  std::ifstream ifile;
  std::string color5;
  ifile.open(PATH_WAL);
  if (ifile.is_open()) {
    for (int i = 0; i < 6; i++) {
      std::getline(ifile, color5);
    }
  }
  ifile.close();
  color5.erase(0, 1);
  color5 = "0x" + color5 + "ff";
  return color5;
}
