#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/olivia/MSD-CS6010/FinalProject/xcode
  make -f /Users/olivia/MSD-CS6010/FinalProject/xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/olivia/MSD-CS6010/FinalProject/xcode
  make -f /Users/olivia/MSD-CS6010/FinalProject/xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/olivia/MSD-CS6010/FinalProject/xcode
  make -f /Users/olivia/MSD-CS6010/FinalProject/xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/olivia/MSD-CS6010/FinalProject/xcode
  make -f /Users/olivia/MSD-CS6010/FinalProject/xcode/CMakeScripts/ReRunCMake.make
fi

