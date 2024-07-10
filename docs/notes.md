# notes on gn

Using [this](https://github.com/o-lim/generate-ninja) repo for gn in order to avoid using depot_tools to get
gn.

Ahh, this is a very old version of gn and hasn't been modified in five years.  I could not get it
to build even after dorking with the python files to accept current versions of xode.

[Here](https://gn.googlesource.com/gn/) is the official repo.

[fuchsia gn ref](https://fuchsia.dev/fuchsia-src/development/build/build_system/intro)

# installation of gn 

1. git clone git@github.com:o-lim/generate-ninja.git
	- this failed to build on osx 
2. git clone https://gn.googlesource.com/gn
	* cd gn
	* python build/gen.py
	* ninja -C out
	* ./out/gn_unittests
3. Do this to setup environment
	* GITROOT=`git rev-parse --show-toplevel`
	* cd ${GITROOT}
	* . ./bin/setenv.sh
	

# ldd on osx

```
$ otool -L <exe_name>
```

# ldd on USS

NOTE: the space before `LISTLOAD`

```
$ echo " LISTLOAD" | amblist ../../../dynamic_build/out/zos_s390x.release/d8 | grep lib.*\.so
```

