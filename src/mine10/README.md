# Purpose

This example builds a executable with two different compilers.  It also
demos code that requires c++ 23.




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

## apple clang

* [apple clang ref manual](https://opensource.apple.com/source/clang/clang-23/clang/tools/clang/docs/UsersManual.html)
* [clang ref manual](https://clang.llvm.org/docs/UsersManual.html)

Interesting, I modified the followig files to configure clang rather than g++.

* build/BUILDCONFIG.gn
	- default toolchain to be clang config
	- also added a mod to get general compiler settings use my compiler mod below
* build/BUILD.gn
	- Added a new compiler config where I specify
		- `-std=C++17` currently commented out
		- `-std=C++20` currently commented out
		- `-std=C++2b`
			- this corresponds to C++23
		- Added some color and escape code mods
* build/toolchain/BUILD.gn
	- Originally it has all the tools specified as the linux gcc equivalent.
	- Add an entirely duplicate with a "clang" key.
	- Afterwards just changed all the gcc/g++ keyworks to clang.

After these changes, the simple c++ single file which uses c++23 built without problems.

## Reference

```
$ vi ../../gn/docs/reference.md
```