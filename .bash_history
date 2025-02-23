$ pacman -S mingw-w64-ucrt-x86_64-gcc
pacman -S mingw-w64-ucrt-x86_64-gcc
pacman -S mingw-w64-x86_64-flex mingw-w64-x86_64-bison mingw-w64-x86_64-gcc
pacman -S mingw-w64-x86_64-flex mingw-w64-x86_64-bison mingw-w64-x86_64-gcc
pacman -Sy
pacman -S msys/flex msys/bison
pacman -S mingw-w64-x86_64-gcc
flex --version
bison --version
gcc -version
gcc --version
pacman -Syu
pacman -S mingw-w64-x86_64-flex mingw-w64-x86_64-bison mingw-w64-x86_64-gcc
pacman -Syu
pacman -S mingw-w64-x86_64-flex mingw-w64-x86_64-bison mingw-w64-x86_64-gcc
flex --version
bison --version
gcc --version
cd cminus/
ls
nano cminus.l
nano cminus.y
mv "/c/Users/bruna/Downloads/1739927178593+cminus.l" ~/cminus/
ls -l
rm ~/cminus/cminus.l
ls -l
mv ~/cminus/1739927178593+cminus.l  ~/cminus/cminus.l
ls -l
cp "/c/Users/bruna/Downloads/1739927178593+cminus.y" ~/cminus/
ls -l
mv ~/cminus/1739927178593+cminus.y ~/cminus/cminus.y
ls -l
rm ~/cminus/cminus.y
ls -l
mv ~/cminus/1739927178593+cminus.y ~/cminus/cminus.y
ls -l
mv ~/cminus/1739927178593+cminus.y ~/cminus/cminus.y
cp "/c/Users/bruna/Downloads/1739927178593+cminus.y" ~/cminus/
ls -l
mv ~/cminus/1739927178593+cminus.y ~/cminus/cminus.y
ls -l
bison -d cminus.y 
flex cminus.l
gcc -Wno-unused-function -o cminus main.c symboltable.c semantic.c ast.c cminus.tab.c lex.yy.c -Wall
