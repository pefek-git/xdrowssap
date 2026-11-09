#include <iostream>
#include <string>
#include <random>
using namespace std;

string generatePassword(int length){
  const string chars = "abcdefghijklmnoprstuvxyz""ABCDEFGHIJKLMNOPRSTUVXYZ""0123456789""!@#$%^&*";

  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dist(0, chars.size() - 1);
  
  string password;

  for (int i = 0; i < length; i++){
    password += chars[dist(gen)];
  }

  return password;
}
