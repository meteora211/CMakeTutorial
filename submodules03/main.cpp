#include <iostream>
#include <adder.h>
#include <xbyak/xbyak.h>

struct Code : Xbyak::CodeGenerator {
  Code(int x) {
    mov(eax, x);
    ret();
  }
};

int main() {
  std::cout << "hello" << std::endl;

  std::cout << add(72.1f, 73.8f) << std::endl;

  Code c(5);
  int (*f)() = c.getCode<int (*)()>();
  std::cout << "ret=" << f() << std::endl;
}
