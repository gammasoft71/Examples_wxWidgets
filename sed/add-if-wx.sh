#!/bin/env sh
#
# Apply the sed script to all CMakeLists.txt (except the root CMakeLists.txt).
#
find src/ -type f -iname "CMakeLists.txt" | xargs sed -i -f sed/add-if-wx.sed