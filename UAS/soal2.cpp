#include <iostream>
#include <algorithm> // untuk sort()
#include <math.h>    // untuk floor()
using namespace std;

int main() {
    int N;

    cin >> N;
    if (N < 1 || N > 200) {
        cout << "jumlah kursi pada bioskop yang tersedia adalah antara 1 sampai 200" << endl;
        return 0;
    }
    int data[N];
    cout << "Masukkan " << N << " kursi5 (acak):\n";
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }
    sort(data, data + N);
    cout << "Kursi yang tersedia setelah diurutkan: ";
    for (int i = 0; i < N; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    return 0;

    int cari;
    cout << "\nMasukkan kursi yang ingin dicari: ";
    cin >> cari;

    int low = 0, high = N - 1, flag = 0;
    int posisi;
    float posisi1;

    // Proses Interpolation Search
    while (low <= high && cari >= data[low] && cari <= data[high]) {
        posisi1 = (float)(cari - data[low])/(data[high] - data[low]) * (high - low) + low;
        posisi = floor(posisi1);


        if(data[posisi] == cari){
            flag = 1;
            break;
        }
        
        if(data[posisi] > cari)
            high = posisi - 1;
        else
            low = posisi + 1;
        
    }


    cout << "\n\nSTATUS: ";
    if (flag == 1)
        cout << "kursi " << cari << " ditemukan pada indeks ke" << posisi << endl;
    else
        cout << "kursi " << cari << "opsi: kursi terdekat yang tersedia" << endl;

    return 0;

}    