# Purpose

This takes the last model and moves the CSV code and puts in a .so
so the deps argument of `gn desc out //:main deps --tree` can be 
examined.


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

Now, we can see the deps tree.

```
$ gn desc out //:main  deps --tree
//src/CSV:csv
```

`gn desc out` will show the flags, but to limit the output to just the flags

```
$ gn desc out //:main  cflags     
-std=c++2b
-fcolor-diagnostics
-g
```

and for csv, we can't use the shortcut.

```
$ gn desc out //src/CSV:csv  cflags
-std=c++2b
-fcolor-diagnostics
-g
```

Use `--blame` to see where the flags come from.

```
$ gn desc out //src/CSV:csv  cflags --blame
From //build:jfd_compiler_config
     (Added by //build/BUILDCONFIG.gn:25)
  -std=c++2b
  -fcolor-diagnostics
  -g
```

#  To get a list of targets

```
$ gn ls out "//*"                        
//:main
//src/CSV:csv
```

# List paths between targets

```
$ gn path out //:main //src/CSV:csv  
//:main --[private]-->
//src/CSV:csv

1 non-data path found. It is not public.
```

# List references to a target, config, file

## target
```
$ gn refs out //src/CSV:csv 
//:main
```

## config
```
$ gn refs out //build:jfd_compiler_config
//:main
//src/CSV:csv
```

See the mine12/BUILD.gn file for an example of where the print function
is used to dump the config variables for the main executable.

```
$ gn gen out
["//build:compiler_defaults", "//build:jfd_compiler_config", "//build:executable_ldconfig", ":myconfig"]
```

Note if you add the -v flag, it shows that after loading //BUILD.gn, it shows this same output as it
prints `Running //BUILD.gn with toolchain //build/toolchain:clang`

```
gn gen -v out
Using source root /Users/davis/progs/github/gn_testy/src/mine12
Got dotfile /Users/davis/progs/github/gn_testy/src/mine12/.gn
Using build dir //out/
Loading //build/BUILDCONFIG.gn
Loading //BUILD.gn
Running["//build:compiler_defaults", "//build:jfd_compiler_config", "//build:executable_ldconfig", ":myconfig"]
 //BUILD.gn with toolchain //build/toolchain:clang
Defining target //:main(//build/toolchain:clang)
Defining config //:myconfig(//build/toolchain:clang)
Loading //build/BUILD.gn (referenced from //build/BUILDCONFIG.gn:22)
Loading //build/toolchain/BUILD.gn (referenced from //BUILD.gn:2)
Loading //src/CSV/BUILD.gn (referenced from //BUILD.gn:8)
Running //build/BUILD.gn with toolchain //build/toolchain:clang
Defining config //build:compiler_defaults(//build/toolchain:clang)
Defining config //build:executable_ldconfig(//build/toolchain:clang)
Defining config //build:jfd_compiler_config(//build/toolchain:clang)
Running //src/CSV/BUILD.gn with toolchain //build/toolchain:clang
Defining target //src/CSV:csv(//build/toolchain:clang)
Running //build/toolchain/BUILD.gn with toolchain //build/toolchain:clang
Defining toolchain //build/toolchain:gcc
Defining toolchain //build/toolchain:clang
Computing //src/CSV:csv(//build/toolchain:clang)
Computing //:main(//build/toolchain:clang)
Build graph constructed in 5ms
Done. Made 2 targets from 5 files in 14ms
```



## file
```
$ gn refs out //src/CSV:csv.h
//src/CSV:csv
```

I tried to find the compiler setting but I kept getting an error message:

```
The input matches no targets, configs, or files
```

# check a gn build system

```
$ gn check out
```

This scans source files and verifies that mentioned include files
are present.

# Large Codebase techniques

This is almost lifted from the presentation verbatim.

* deps vs public_deps
	- control how you expose dependencies
* visibility
	- limit what can depend on you
* assert_no_deps
	- you can specify that other components can not use this component.
* testonly
	- this component can not be linking into production code.
* list public headers in "public"
	- other headers become "private"

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



