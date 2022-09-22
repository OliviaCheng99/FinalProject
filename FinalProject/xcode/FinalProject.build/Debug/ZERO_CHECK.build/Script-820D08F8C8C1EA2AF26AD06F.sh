#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/olivia/FinalProject/FinalProject/xcode
  make -f /Users/olivia/FinalProject/FinalProject/xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/olivia/FinalProject/FinalProject/xcode
  make -f /Users/olivia/FinalProject/FinalProject/xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/olivia/FinalProject/FinalProject/xcode
  make -f /Users/olivia/FinalProject/FinalProject/xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/olivia/FinalProject/FinalProject/xcode
  make -f /Users/olivia/FinalProject/FinalProject/xcode/CMakeScripts/ReRunCMake.make
fi

