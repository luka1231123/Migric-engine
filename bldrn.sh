#!/bin/sh

# Build and run the minimal engine.  This script first invokes
# build.sh to compile the core sources and then runs the resulting
# binary.
sh build.sh && sh run.sh