# Purpose

This demos the use of a file used as input during runtime.




# usage

```
#$ gn gen -C out
# equivalent
$ gn gen -C out
$ ninja -v -C out
$ ./out/main
```

# To clean 

```
$ ninja -v -C out -t clean
```

# Notes


## apple clang

This code can be switched to use native clang or the gcc clang clone.  Change the comment in `build/BUILDCONFIG.gn`.

* [apple clang ref manual](https://opensource.apple.com/source/clang/clang-23/clang/tools/clang/docs/UsersManual.html)
* [clang ref manual](https://clang.llvm.org/docs/UsersManual.html)


## GN Reference

```
$ vi ../../gn/docs/reference.md
```

## Idea for CSV code

Used practice of programming book as guide for the CSV code

* [book homepage](http://www.cs.princeton.edu/~bwk/tpop.webpage/)
* [code reference](https://www.cs.princeton.edu/~bwk/tpop.webpage/csvgetlinec++.c)



