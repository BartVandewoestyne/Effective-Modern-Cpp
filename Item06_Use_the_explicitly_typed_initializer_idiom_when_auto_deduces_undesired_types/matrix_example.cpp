/*
 * TODO: work out this Matrix example, it currently doesn't compile.
 */

class Matrix;

template<typename T1, typename T2>
class Sum {
  // TODO: implement implicit conversion from the proxy class to Matrix
  operator Matrix() const
  {
    return Matrix();
  }
};

class Matrix {
public:
  Sum<Matrix, Matrix> operator+(const Matrix& m1, const Matrix m2);
};

int main()
{
  Matrix m1, m2, m3, m4;

  // typed initializer idiom
  auto sum = static_cast<Matrix>(m1 + m2 + m3 + m4);
}
