#! /bin/bash

git config --global user.email "javierc@noreply.com"
git config --global user.name "JavierC"
wget https://huggingface.co/datasets/ccoffee20/trinity-installer/resolve/main/patches.zip
unzip patches.zip
cd libc-shim
git config --global user.email "javierc@noreply.com"
git config --global user.name "JavierC"
git am *.patch
cd ..
cd mcpelauncher-client 
git config --global user.email "javierc@noreply.com"
git config --global user.name "JavierC"
git am ../mcpe-client/*.patch
cd ..
cd libjnivm
git config --global user.email "javierc@noreply.com"
git config --global user.name "JavierC"
git am *.patch
cd ..
cd game-window
git apply ../fix-non-latin-layout.patch
cd ..
