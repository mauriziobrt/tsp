#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd "/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/projects/dynamictsp"
  make -f /Users/maurizioberta/Documents/Max\ 8/Packages/tsp/source/projects/dynamictsp/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd "/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/projects/dynamictsp"
  make -f /Users/maurizioberta/Documents/Max\ 8/Packages/tsp/source/projects/dynamictsp/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd "/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/projects/dynamictsp"
  make -f /Users/maurizioberta/Documents/Max\ 8/Packages/tsp/source/projects/dynamictsp/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd "/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/projects/dynamictsp"
  make -f /Users/maurizioberta/Documents/Max\ 8/Packages/tsp/source/projects/dynamictsp/CMakeScripts/ReRunCMake.make
fi

