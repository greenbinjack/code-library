#for linux
{
  "shell_cmd": "g++ $file -o $file_base_name && ./$file_base_name<input.txt> output.txt && rm $file_base_name",
  "working_dir": "$file_path",
  "selector": "source.c++"
}
#for windows
{
  "shell_cmd": "g++ -std=c++17 $file -o $file_base_name.exe && $file_base_name.exe <input.txt> output.txt && del $file_base_name.exe",
  "working_dir":"$file_path",
  "selector":"source.c++"
}