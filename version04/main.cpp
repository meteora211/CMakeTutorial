#include <iostream>
#include <cmaketutorial.h>

float add(float a, float b);

int main() {
  std::cout << "hello" << std::endl;

  std::cout << "version: " << HELLO_VERSION_MAJOR << "." << HELLO_VERSION_MINOR << std::endl;

  std::cout << add(72.1f, 73.8f) << std::endl;
}
