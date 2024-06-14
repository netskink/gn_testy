# Purpose

This example builds a executable with 
* a static library 
* a shared library (*.so)
* the libs are in a subdir
* more complex config
* group directive
* second executable 
* adds mix of C and C++
	- using this guide https://isocpp.org/wiki/faq/mixing-c-and-cpp



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

This example uses a `/usr/bin/g++` to compile code, but in reality its
apple xcode - clang.  Verify via:

```
$ g++ --version
Apple clang version 15.0.0 (clang-1500.3.9.4)
Target: arm64-apple-darwin23.5.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
```


## Reference

```
$ vi ../../gn/docs/reference.md
```