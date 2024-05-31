# Python Setup


One concise document to setup Python

##  Python on osx

These are notes on how to setup a vs code installation using github codespaces for use with 
jupyter/inotebooks

### workflow

1. `cd src`
2.  `python3 -m venv venv`
3.  `source venv/bin/activate`
    - at this point you should notice your prompt has a prefix of `(venv)` meaning the venv is operational
4.  `pip install --upgrade pip`
5. `pip install -r requirements.txt`
    - this installs the common identified modules for code in this venv
6. add `.gitignore` for `venv` and for `.env`
    - this is so that git does not try to CM your modules nor your api keys in `.env`
    - `echo nbenv/nbenv/ >> .gitignore`
    - `echo .env >> .gitignore`
