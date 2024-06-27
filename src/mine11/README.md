# Purpose

This demos the use of a file used as input during runtime.


See also:

```
$ gn help runtime_deps
$ gn help deps
$ gn help data
```

See below on the desc notes.


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

# To get a description of the main executable

This shows what configs are in play, what the output is named, flags
used by the compiler, etc.

```
$ gn desc out //:main 
```

This variant will reveal that at runtime, it uses the `data/data.csv`
file.

```
$ gn desc out //:main runtime_deps
main
../data/data.csv
```

The reason it prefixes the leading double dots, is because the gn command is run
from the out subdirectory and that is where it finds `main` executable and
relative to there is the `data` directory.



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



