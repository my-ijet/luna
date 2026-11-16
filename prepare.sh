#!/usr/bin/env bash
set -eu

echo "Debug build"
cmake --preset debug
echo ""
echo "Release build"
cmake --preset release
