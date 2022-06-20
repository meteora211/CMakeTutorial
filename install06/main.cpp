#include <iostream>
#include <lib_configure.h>

#ifdef USE_XBYAK
class AddFunc : public Xbyak::CodeGenerator {
    void operator=(const AddFunc&);
public:
    AddFunc()
    {
      /* movsd(xmm0, ptr [rsp + 8]); */
      /* movsd(ptr [rsp + 8], xmm0); */
      /* mov(rax, ptr [rsp + 8]); */
      /* mov(rax, ptr [rsp + 8]); */
      /* addss(xmm0, ptr [rsp + 16]); */
      /* movss(rax, xmm0); */
      /* add(eax, y); */
      /* lea(rax, ptr [rdi + y]); */
      /* movss(xmm0, ptr[rdi]); */
      /* movss(xmm1, rsi); */
      /* movss(xmm1, y); */
      /* addss(xmm0, xmm1); */
      /* mov(rax, rdi); */
      /* movq(rax, xmm0); */
      /* ret(); */


      // INT ADD
      mov(eax, edi);
      add(eax, esi);
      ret();
    }
    /* double (*get() const)(double*) { return getCode<double(*)(double, double)>(); } */
    /* float (*get() const)(float, float) { return getCode<float(*)(float, float)>(); } */
    int (*get() const)(int, int) { return getCode<int(*)(int, int)>(); }
};
#endif

int main() {
  std::cout << "hello" << std::endl;

#ifdef USE_ADDER
  std::cout << add(72.1f, 73.8f) << std::endl;
#else
  std::cout << "do not use adder." << std::endl;
#endif

#ifdef USE_XBYAK
  AddFunc a;
  /* double (*f)(double, double) = a.get(); */
  /* float (*f)(float, float) = a.get(); */
  int (*f)(int, int) = a.get();
  std::cout << "ret=" << f(3, 5) << std::endl;
#else
  std::cout << "do not use xybak" << std::endl;
#endif
}
