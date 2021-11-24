@echo off


cd deps/glew-2.1.0/build/vc12
msbuild glew.sln /property:Configuration=Release;Platform=x64

cd ../../../../build

cmake ../
msbuild CarnotEngine.sln /property:Configuration=Release;Platform=x64
cd ..
