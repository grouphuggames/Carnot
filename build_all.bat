@echo off

cd build
cmake ../
msbuild CarnotEngine.sln /property:Configuration=Release
cd ..
