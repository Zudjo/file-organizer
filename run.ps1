Clear-Host

g++ .\main.cpp .\classes\*.cpp -o main.exe

if ($?) {
  .\main.exe  
}
