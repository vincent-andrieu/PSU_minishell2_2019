#!/bin/bash

echo ls -l | ./mysh > test/mdr
echo ls -l | tcsh > test/lol
diff test/mdr test/lol
echo $?

echo -------------------------------------

echo ./my_segfault | ./mysh > test/mdr
echo ./my_segfault | tcsh > test/lol
diff test/mdr test/lol
echo $?

echo -------------------------------------

echo setenv | ./mysh > test/mdr
echo setenv | tcsh > test/lol
diff test/mdr test/lol
echo $?

echo -------------------------------------

echo "setenv mdr" | ./mysh > test/mdr
echo "setenv mdr" | tcsh > test/lol
diff test/mdr test/lol
echo $?

echo -------------------------------------

echo "setenv *mdr" | ./mysh > test/mdr
echo "setenv *mdr" | tcsh > test/lol
diff test/mdr test/lol
echo $?

echo -------------------------------------

echo "setenv m*dr" | env -i ./mysh > test/mdr
echo "setenv m*dr" | env -i tcsh > test/lol
diff test/mdr test/lol
echo $?

echo -------------------------------------

echo "setenv *mdr" | env -i ./mysh > test/mdr
echo "setenv *mdr" | env -i tcsh > test/lol
diff test/mdr test/lol
echo $?

echo -------------------------------------

echo "setenv m*dr" | ./mysh > test/mdr
echo "setenv m*dr" | tcsh > test/lol
diff test/mdr test/lol
echo $?

echo -------------------------------------

echo "setenv mdr lol" | ./mysh > test/mdr
echo "setenv mdr lol" | tcsh > test/lol
diff test/mdr test/lol
echo $?

echo -------------------------------------

echo "cd .." | env -i ./mysh > test/mdr
echo "cd .." | env -i tcsh > test/lol
diff test/mdr test/lol
echo $?

echo -------------------------------------

echo "cd -" | env -i ./mysh > test/mdr
echo "cd -" | env -i tcsh > test/lol
diff test/mdr test/lol
echo $?

echo -------------------------------------

echo "cd" | env -i ./mysh > test/mdr
echo "cd" | env -i tcsh > test/lol
diff test/mdr test/lol
echo $?

echo -------------------------------------

echo "cd ~" | env -i ./mysh > test/mdr
echo "cd ~" | env -i tcsh > test/lol
diff test/mdr test/lol
echo $?

echo -------------------------------------

echo "cd .." | ./mysh > test/mdr
echo "cd .." | tcsh > test/lol
diff test/mdr test/lol
echo $?

echo -------------------------------------

echo "cd -" | ./mysh > test/mdr
echo "cd -" | tcsh > test/lol
diff test/mdr test/lol
echo $?

echo -------------------------------------

echo "cd" | ./mysh > test/mdr
echo "cd" | tcsh > test/lol
diff test/mdr test/lol
echo $?

echo -------------------------------------

echo "cd ~" | ./mysh > test/mdr
echo "cd ~" | tcsh > test/lol
diff test/mdr test/lol
echo $?

echo -------------------------------------

echo "cd /root" | ./mysh > test/mdr
echo "cd /root" | tcsh > test/lol
diff test/mdr test/lol
echo $?

echo -------------------------------------

echo "cd nopath" | ./mysh > test/mdr
echo "cd nopath" | tcsh > test/lol
diff test/mdr test/lol
echo $?

echo -------------------------------------

echo "clear" | env -i ./mysh > test/mdr
echo "clear" | env -i tcsh > test/lol
diff test/mdr test/lol
echo $?

echo -------------------------------------

echo "rejifdihsf" | ./mysh > test/mdr
echo "rejifdihsf" | tcsh > test/lol
diff test/mdr test/lol
echo $?