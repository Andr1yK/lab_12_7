src_dir="./src"
search_dir="$src_dir/extends"
exported_file='./all_extends.txt'

echo "main.cpp" > $exported_file

IFS=''
while read line;
do
  echo $line >> $exported_file;
done < "$src_dir/main.cpp"

for entry in "$search_dir"/*
do
  echo "\n\n$entry" >> $exported_file;

  while read line;
  do
    echo $line >> $exported_file;
  done < $entry
done

echo $(< "$exported_file") | pbcopy

# pandoc -o output.docx -f markdown -t docx $exported_file