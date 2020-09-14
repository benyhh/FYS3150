#ifndef TridiagonalMatrixSolver_HPP
#define TridiagonalMatrixSolver_HPP
#include <fstream>
#include <armadillo>

using namespace std;
using namespace arma;

class TridiagonalMatrixSolver {
protected:
  int m_N;
  vec m_lambda, m_rho, m_v;
  ofstream m_ofile;

public:
  void initialize(int N, vec f(vec x));
  void write_to_file(string filename);
};

class Diagonalize : public TridiagonalMatrixSolver {
private:
  vec m_a, m_d;
  void forward_substitution();
  void backward_substitution();
public:
  void init(int N, vec f(vec x));
  void solve();
};

class JacobiMethod : public TridiagonalMatrixSolver {
private:
  vec m_a, m_d;
  void forward_substitution();
  void backward_substitution();
public:
  void init(int N, vec f(vec x));
  void solve();
};

#endif
