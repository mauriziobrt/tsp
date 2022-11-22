#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd "/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/projects/dynamictsp"
  cp /Users/maurizioberta/Documents/Max\ 8/Packages/tsp/source/min-api/max-sdk-base/script/PkgInfo /Users/maurizioberta/Documents/Max\ 8/Packages/tsp/source/projects/dynamictsp/../../../externals/dynamictsp.mxo/Contents/PkgInfo
fi
if test "$CONFIGURATION" = "Release"; then :
  cd "/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/projects/dynamictsp"
  cp /Users/maurizioberta/Documents/Max\ 8/Packages/tsp/source/min-api/max-sdk-base/script/PkgInfo /Users/maurizioberta/Documents/Max\ 8/Packages/tsp/source/projects/dynamictsp/../../../externals/dynamictsp.mxo/Contents/PkgInfo
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd "/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/projects/dynamictsp"
  cp /Users/maurizioberta/Documents/Max\ 8/Packages/tsp/source/min-api/max-sdk-base/script/PkgInfo /Users/maurizioberta/Documents/Max\ 8/Packages/tsp/source/projects/dynamictsp/../../../externals/dynamictsp.mxo/Contents/PkgInfo
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd "/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/projects/dynamictsp"
  cp /Users/maurizioberta/Documents/Max\ 8/Packages/tsp/source/min-api/max-sdk-base/script/PkgInfo /Users/maurizioberta/Documents/Max\ 8/Packages/tsp/source/projects/dynamictsp/../../../externals/dynamictsp.mxo/Contents/PkgInfo
fi

