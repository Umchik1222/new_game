mkdir build
cd build

cmake ../.. -G "Unix Makefiles"
make
mv ./mygame.exe ../