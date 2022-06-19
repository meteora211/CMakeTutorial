#include <iostream>

float float_add(float a, float b) {
  return a + b;
  /* return c; */
}

int main() {
  /* float a = 5.1; */
  /* float b = 3.2; */

  float c = float_add(5.1, 3.2);
  std::cout << "result: " << c << std::endl;
}
