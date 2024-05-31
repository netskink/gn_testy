#!/usr/bin/env bash

GITROOT=`git rev-parse --show-toplevel`

export PATH=${GITROOT}/gn/out/:${PATH}