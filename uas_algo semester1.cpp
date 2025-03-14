#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Fungsi untuk mengonversi angka menjadi kalimat terbilang
string numberToWords(int num);
string helper(int num);

int main() {
    while (true) {
        int nominal;
        cout << "Masukkan nilai nominal rupiah: ";
        
        // Validasi input untuk memastikan hanya angka yang diterima
        while (!(cin >> nominal)) {
            cout << "Input tidak valid. Silakan masukkan nilai nominal dalam bentuk angka: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (nominal < 0) {
            cout << "Nilai nominal tidak bisa negatif. Silakan masukkan nilai positif." << endl;
            continue;
        }

        cout << "Terbilang: " << numberToWords(nominal) << "Rupiah" << endl;

        char ulang;
        cout << "Apakah Anda ingin mengulang? (y/n): ";
        cin >> ulang;

        // Pastikan input hanya 'y', 'Y', 'n', atau 'N'
        if (ulang != 'y' && ulang != 'Y') break;
    }

    return 0;
}

// Fungsi untuk mengonversi angka menjadi kalimat terbilang
string numberToWords(int num) {
    const string lessThan20[] = {"", "Satu", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan", "Sepuluh", "Sebelas", "Dua Belas",
	 "Tiga Belas", "Empat Belas", "Lima Belas", "Enam Belas", "Tujuh Belas", "Delapan Belas", "Sembilan Belas"};
    const string tens[] = {"", "", "Dua Puluh", "Tiga Puluh", "Empat Puluh", "Lima Puluh", "Enam Puluh", "Tujuh Puluh", "Delapan Puluh", "Sembilan Puluh"};
    const string thousands[] = {"", "Ribu", "Juta", "Miliar", "Triliun"};

    if (num == 0) return "Nol";
    string result;

    int i = 0;
    while (num > 0) {
        if (num % 1000 != 0) {
            if (num % 1000 == 1 && i == 1) {
                result = "Seribu " + result;
            } else {
                result = helper(num % 1000) + thousands[i] + " " + result;
            }
        }
        num /= 1000;
        i++;
    }

    return result;
}

// Fungsi bantu untuk konversi angka kurang dari 1000
string helper(int num) {
    const string lessThan20[] = {"", "Satu", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan", "Sepuluh", "Sebelas", "Dua Belas",
	 "Tiga Belas", "Empat Belas", "Lima Belas", "Enam Belas", "Tujuh Belas", "Delapan Belas", "Sembilan Belas"};
    const string tens[] = {"", "", "Dua Puluh", "Tiga Puluh", "Empat Puluh", "Lima Puluh", "Enam Puluh", "Tujuh Puluh", "Delapan Puluh", "Sembilan Puluh"};

    if (num == 0) return "";
    else if (num < 20) return lessThan20[num] + " ";
    else if (num < 100) return tens[num / 10] + " " + lessThan20[num % 10] + " ";
    else return lessThan20[num / 100] + " Ratus " + helper(num % 100);
}

