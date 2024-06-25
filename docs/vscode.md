# Notes particular to vscode

## Extensions installed

* TODO Highlight
	- highlights TODO in files
* c/c++
* c/c++ extension pack
* c/c++ themes
* CodeLLDB - for osx debugging of c/c++
* GN Language Server
* IntelliCode
* JSON formatter
* ninja-build
* Rainbow CSV
* Run on Save
* Vim
* XML Tools
* ANTLR4 grammar syntax support
	- https://github.com/mike-lischke/vscode-antlr4
* vscode diff
	- allows diffs of folders
	- https://github.com/l13/vscode-diff

## notes on launch and tasks json files

tips:

* `pwd` is helpful.  
* Args need to be a single string with no spaces, otherwise it will add a leading space.
	- ie instead of "-C out" do "-C" and "out".
* when building a command, it seems you need to have an args clause in tasks.json.

