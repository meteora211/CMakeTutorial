#include <iostream>
#include <adder.h>
#include <xbyak/xbyak.h>

struct FloatAdd : Xbyak::CodeGenerator {
  FloatAdd() {
    mov(eax, 1);
    ret();
  }
};

class AddFunc : public Xbyak::CodeGenerator {
    void operator=(const AddFunc&);
public:
    AddFunc()
    {
        /* mov(eax, ptr [esp + 4]); */
        /* add(eax, y); */
        /* lea(rax, ptr [rdi + y]); */
        movss(xmm0, rdi);
        movss(xmm1, rsi);
        /* movss(xmm1, y); */
        addss(xmm0, xmm1);
        /* movss(rax, xmm0); */
        ret();
    }
    float (*get() const)(float, float) { return getCode<float(*)(float, float)>(); }
};

int main() {
  std::cout << "hello" << std::endl;

  std::cout << add(72.1f, 73.8f) << std::endl;

  AddFunc a;
  float (*f)(float, float) = a.get();
  /* float (*f)(float, float) = c.getCode<float (*)(float, float)>(); */
  std::cout << "ret=" << f(5.1, 3.2) << std::endl;
}
