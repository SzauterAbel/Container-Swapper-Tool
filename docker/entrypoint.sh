#!/bin/bash

echo "Environment variables:"
echo "CC=$CC"
echo "CXX=$CXX"
echo "LDFLAGS=$LDFLAGS"
echo "CXXFLAGS=$CXXFLAGS"

if [ $# -gt 0 ]; then
  exec "$@"
else
  /bin/bash
fi