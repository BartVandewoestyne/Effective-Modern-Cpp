#ifndef COMPRESS_H
#define COMPRESS_H

enum class CompLevel { Low, Normal, High };  // compression
                                             // level

Widget compress(const Widget& w,             // make compressed
                CompLevel lev);              // copy of w

#endif  // COMPRESS_H
