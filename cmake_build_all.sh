#!/bin/bash

BUILDDIR=${1:-build}

BUILDDIR=${BUILDDIR} TOOLSET=clang++ BUILDMODE=RELEASE sh cmake_build.sh
BUILDDIR=${BUILDDIR} TOOLSET=clang++ BUILDMODE=DEBUG sh cmake_build.sh
BUILDDIR=${BUILDDIR} TOOLSET=g++ BUILDMODE=RELEASE sh cmake_build.sh
BUILDDIR=${BUILDDIR} TOOLSET=g++ BUILDMODE=DEBUG sh cmake_build.sh
