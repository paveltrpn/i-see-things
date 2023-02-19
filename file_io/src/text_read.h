
#ifndef __text_read_h__
#define __text_read_h__

#include <fstream>
#include <sstream>
#include <vector>

std::string textRead1(std::string fname);
std::string textRead2(std::string fname);
std::string textRead3(std::string fname);

std::pair<std::vector<std::string>, size_t> textReadToStrVec(std::string fname);

#endif