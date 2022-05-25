file_name="$1"
define=$(echo $file_name | tr '[:lower:]' '[:upper:]')

set -o noclobber

code="#pragma once\n\
\n\
#ifndef _${define}_\n\
#define _${define}_\n\
\n\
void $file_name() {\n\
// code here\n\
}\n\
\n\
#endif // !_${define}_"

[ ! -d "./src/extends" ] && mkdir "./src/extends"

echo $code > src/extends/$file_name.cpp

echo "#include \"./extends/$file_name.cpp\"" | pbcopy &&
echo "\n\t#include \"./extends/$file_name.cpp\" - copied\n"
