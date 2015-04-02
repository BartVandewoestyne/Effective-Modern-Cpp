/*
 * Key idea:
 *
 *   The following code is completely legal and, at first sight, looks
 *   reasonable, but it contains no virtual function overrides - not a single
 *   derived class function that is tied to a base class function.
 */

class Base {
public:
  virtual void mf1() const;
  virtual void mf2(int x);
  virtual void mf3() &;
  void mf4() const;
};

class Derived: public Base {
public:
  virtual void mf1();
  virtual void mf2(unsigned int x);
  virtual void mf3() &&;
  void mf4() const;
};
