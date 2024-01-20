#include <stdint.h>

#include <bit>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

using namespace std;

static void toZ64(const std::string& n64FilePath) {
  string z64FilePath(n64FilePath);
  size_t pos = n64FilePath.rfind(".n64");
  if (pos == string::npos) {
    stringstream ss;
    ss << "Error: " << n64FilePath << " is not a .n64 file" << endl;
    throw runtime_error(ss.str());
  }
  z64FilePath.replace(pos, z64FilePath.length(), ".z64");
  if (filesystem::exists(z64FilePath)) {
    cout << z64FilePath << " exists, skipping\n";
    return;
  }

  const auto fsize = filesystem::file_size(n64FilePath);
  std::unique_ptr<char[]> iobuf(new char[fsize]);
  
  ifstream n64(n64FilePath, ios::in|ios::binary);
  n64.seekg(0);
  n64.read(iobuf.get(), fsize);
  for (int i=0; i < fsize-1; i+=2) {
    std::swap(iobuf[i], iobuf[i+1]);
  }
  ofstream z64(z64FilePath, ios::out|ios::binary);
  z64.seekp(0);
  z64.write(iobuf.get(), fsize);
  cout << z64FilePath << " saved to disk\n";
}


int main(int argc, char** argv) {
  for (int i=1; i < argc; ++i) {
    toZ64(argv[i]);
  }
  return 0;
}
