//fifit syafaaty_21091397001

#include<iostream>
#include<list>
#include<cmath>
using namespace std;
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void radixSort(int *arr, int n, int max) {
   int i, j, m, p = 1, index, temp, count = 0;
   list<int> pocket[10];      
   //radix bil. desimal 10
   for(i = 0; i< max; i++) {
      m = pow(10, i+1);
      p = pow(10, i);
      for(j = 0; j<n; j++) {
         temp = arr[j]%m;
         index = temp/p;      
	//index array
         pocket[index].push_back(arr[j]);
      }
      count = 0;
      for(j = 0; j<10; j++) {
    //hapus list dan masukkan ke array
         while(!pocket[j].empty()) {
            arr[count] = *(pocket[j].begin());
            pocket[j].erase(pocket[j].begin());
            count++;
         }
      }
   }
}
int main() {
   int n, max;
   cout << "masukkan jumlah array: ";
   cin >> n;
   cout << "maksimum array: ";
   cin >> max;
   int arr[n]; 
   //buat array
   cout << "isi array :" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "data yang belum disorting: ";
   display(arr, n);
   radixSort(arr, n, max);
   cout << "data yang sudah disorting: ";
   display(arr, n);
}
