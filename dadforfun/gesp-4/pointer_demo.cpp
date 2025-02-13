#include <iostream>
using namespace std;

void hello(int a) { cout << "hello" << a << endl; }

int main() {
  int var = 138;
  int *ptr = nullptr;
  if (ptr == nullptr) {
    cout << "NULL" << endl;
    ptr = &var;
  }
  char *a = "23";
  cout << *a << endl;
  cout << ptr << endl;
  cout << &var << endl;
  cout << &ptr << endl;
  cout << *ptr << endl;
  int **p_ptr = &ptr;
  cout << p_ptr << endl;
  cout << **p_ptr << endl;
  int arry[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *a_ptr = arry;
  for (int i = 0; i < 10; i++) {
    cout << (a_ptr + i) << endl;
    cout << *(a_ptr + i) << endl;
  }
  void (*p_fun)(int) = hello;
  p_fun(*ptr);
  return 0;
}