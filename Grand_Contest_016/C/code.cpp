#include <iostream>
#include <vector>
using namespace std;

void struct_array(int a[], int W, int w)
{
  int s[501] = {0};
  for (int xt = W; xt > W - w; --xt) {
    if (xt % w == 0) {
      for (int x = w; x < W; x += w) {
        s[x] = s[x-w] - 1;
      }
    } else {
      s[xt] = 1;
      for (int x = xt - w; x > 0; x -= w) {
        s[x] = s[x+w] + 1;
      }
    }
  }

  for (int i = 0; i < W; ++i) {
    a[i] = s[i+1] - s[i];
  }
}

int main(int argc, char *argv[])
{
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  if (H % h == 0 && W % w == 0) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;

  int a[501] = {0};

  if (W % w == 0) {
    struct_array(a, H, h);
    for (int y = 0; y < H; ++y) {
      for (int x = 0; x < W; ++x) {
        cout << a[y];
        cout << ((x == W - 1)? "\n" : " ");
      }
    }
  } else {
    struct_array(a, W, w);
    for (int y = 0; y < H; ++y) {
      for (int x = 0; x < W; ++x) {
        cout << a[x];
        cout << ((x == W - 1)? "\n" : " ");
      }
    }
  }

  return 0;
}
