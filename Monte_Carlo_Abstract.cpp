#include <stdlib.h>
#include <stdio.h>

class Monte_Carlo{
  private:
    int init_price, strike, vol, int_rate, Mat, num_sim, num_steps;

  public:
    Monte_Carlo(int S_0, int K, int sigma, int r, int T, int M, int N){
      init_price = S_0;
      strike = K;
      vol = sigma;
      int_rate = r;
      Mat = T;
      num_sim = M;
      num_steps = N;
    }
    virtual int model_evolution(int S_0, int K, int sigma, int T);
    virtual int mode

}
