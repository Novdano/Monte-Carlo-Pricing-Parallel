#include <iostream>
#include <cstdlib>
#include <random>
#include <vector>
#include <math.h>



double MC_Call(double S_0, double K, double r, double sigma, double T, size_t M, size_t N){
  std::default_random_engine generator;
  std::normal_distribution<double> distribution(0.0, 1.0);
  double total_payoff = 0.0;
  double delta_t = T/N;
  for (size_t i = 0; i<M; i++){
    double S = S_0;
    for(size_t n = 0; n<N; n++){
      S = S + S*r*delta_t + S* sigma * std::pow(delta_t,0.5) * distribution(generator);
    }
    if (S>=K){
      total_payoff += S-K;
    }
  }
  return pow((1 + r * (T/N)), -N) * (total_payoff/M);
}

int main(int argc, char** argv) {
  double res = MC_Call(50, 50, 0.0175, 0.02, 1, 100, 100);
  printf("%.5f", res);
  return res;

}
