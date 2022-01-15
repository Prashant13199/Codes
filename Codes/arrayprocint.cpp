#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>

int processArray(std::vector<int> &array) {
  int count=0;
  int sum;
  for(int i=0;i<array.size();i++){
    int j=i;
    sum=0;
    while(j<array.size()){
      if(array[j]%2==0){
        sum+=array[j];

      }else{
        break;
      }
      if(sum>=20){
        count++;
      }
      j++;
    }
  }
  return 0;
}

int main(void) {
  std::vector<int> array;
  int val;
  while (std::cin >> val) {
    if(val<0){
      break
    }
    array.push_back(val);
  }
  std::cout << processArray(array) << std::endl;
  return 0;
}

