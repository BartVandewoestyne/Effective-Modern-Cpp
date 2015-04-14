#ifndef ENCODING_MECHANISM01_H
#define ENCODING_MECHANISM01_H

class Widget {};

Widget widgetFactory() { return Widget(); }  // function returning rvalue

template<typename T>
void func(T&& param) {}

#endif /* ENCODING_MECHANISM01_H */
