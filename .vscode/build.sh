#!/bin/sh
# Compile every .cpp in the active file's folder into <out>.
#
# If that folder contains a `.deps` file, each non-empty, non-`#` line is
# treated as a path (relative to the workspace root) to a dependency folder
# whose headers are added to the include path (-I) and whose *.cpp files are
# compiled and linked in. Folders without a `.deps` build as before.
#
# Usage: build.sh <fileDirname> <workspaceFolder> <outPath>
set -e

DIR="$1"
WS="$2"
OUT="$3"

INCLUDES=""
EXTRA=""

DEPS="$DIR/.deps"
if [ -f "$DEPS" ]; then
  while IFS= read -r line || [ -n "$line" ]; do
    case "$line" in
      ''|\#*) continue ;;
    esac
    INCLUDES="$INCLUDES -I\"$WS/$line\""
    for depfile in "$WS/$line"/*.cpp; do
      case "$(basename "$depfile")" in main.cpp) continue ;; esac
      EXTRA="$EXTRA '$depfile'"
    done
  done < "$DEPS"
fi

mkdir -p "$WS/build"
CMD="/usr/bin/clang++ -std=c++17 -g -fcolor-diagnostics -fansi-escape-codes${INCLUDES} \"$DIR\"/*.cpp${EXTRA} -o \"$OUT\""
eval "$CMD"
