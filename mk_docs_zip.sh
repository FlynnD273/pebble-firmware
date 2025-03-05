#!/usr/bin/env bash
output="PebbleSDK-4.3_docs.zip"

cd build || exit
mkdir aplite
cp -r doxygen-new/xml/ aplite/
ln -s aplite basalt 
ln -s aplite chalk 
ln -s aplite diorite 
# cp -r aplite basalt
# cp -r aplite chalk
# cp -r aplite diorite
if [[ -f $output ]]; then
  rm $output
fi
7z a $output aplite basalt chalk diorite
rm -r aplite basalt chalk diorite
cd ..
