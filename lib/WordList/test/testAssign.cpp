/*
 *
 * Rob Deans
 * Lab 2
 * 2/2/2023
 *
 * */
#include "../WordList.cpp"
#include <cassert>
int main() {
  {
    WordList wl1;
    wl1.addWord("test");
    WordList & wl2 = wl1;
    wl2 = wl1;
    assert(&wl2 == &wl1);
  }
  {
    WordList wl1;
    wl1.addWord("test");
    WordList wl2 = wl1;
    assert(&wl1 != &wl2);
  }
}
