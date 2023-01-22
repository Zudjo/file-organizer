Clear-Host

g++ .\main.cpp .\classes\*.cpp -o main.exe -w

if ($?) {
  .\main.exe
}
