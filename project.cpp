#include <iostream>
#include <string>
using namespace std;
class otel {
	string* musteri_adi[100], * soyadi[100];
	int toplam, sayac1, sayac2;
	enum statu {	//enum fonksiyonu ozellikleri belirtilen nesne olu�turmak i�in kullan�ld�.
		bos, dolu
	}odalar[45];
public:
	otel();
	void oda_isletme();
	void oda_rezervasyonu();
	void oda_bosaltma();
	void musterilerin_sayisi();
	void yatak_odasi_raparu();
	void seminer_odasi_raparu();
	void gelir();
};
otel::otel() {
	sayac1 = 0;
	sayac2 = 0;
	toplam = 0;
	oda_isletme();		//yap�c� fonsiyon direkt �a��r�laca��ndan i�ine oda isletme yaz�ld�
}
void otel::oda_isletme() {
	for (int a = 1; a < 46; a++) {
		odalar[a] = bos;
	}
	int sayi;
	do {
		cout << "\n\n\t\t---Murphy Otel---\n" << endl;
		cout << "\t\t1.Oda rezervasyonu" << endl;
		cout << "\t\t2.Oda bosaltma" << endl;
		cout << "\t\t3.Dolu oda sayisi" << endl;
		cout << "\t\t4.Yatak odasi raparu" << endl;
		cout << "\t\t5.Seminer odasi raporu" << endl;
		cout << "\t\t6.Gunluk toplam gelir" << endl;
		cout << "\t\t7.Cikis yap..." << endl;
		cout << "\nIslem seciniz : ";
		cin >> sayi;
		//alinan degerin switch case yap�s� ile olasiklar� degerlendirilir.
		switch (sayi)
		{
		case 1: oda_rezervasyonu();
			break;
		case 2: oda_bosaltma();
			break;
		case 3: musterilerin_sayisi();
			break;
		case 4: yatak_odasi_raparu();
			break;
		case 5: seminer_odasi_raparu();
			break;
		case 6: gelir();
			break;
		case 7: exit(1);		//cikis yaptirir
			break;
		default:
			cout << "Gecersiz islem ! Lutfen dogru deger giriniz ." << endl;
		}
	} while (sayi != 7);
}
void otel::oda_rezervasyonu() {
	int sayi, x2, i = 1, j = 6, k = 16;
	string ad, o_ad;
	cout << "\n\t\t- Lutfen bir oda tipi seciniz -\n" << endl;
	cout << "\n\t\t1. 1 kisilik oda (40 Tl)" << endl;
	cout << "\n\t\t2. 2 kisilik oda (60 Tl)" << endl;
	cout << "\n\t\t3. Seminer odasi (300 Tl)" << endl;
	cin >> sayi;
	switch (sayi)
	{
	case 1:
		for (j = 6; j < 16; j++) {
			if (odalar[j] != dolu) {
				odalar[j] = dolu;
				cout << "Adiniz : ";
				cin >> ad;
				cout << "Soyadiniz : ";
				cin >> o_ad;
				cout << "Kac gun kalacaksiniz : ";
				cin >> x2;
				toplam += x2 * 40;
				sayac2++;
				musteri_adi[j] = new string;
				*musteri_adi[j] = ad;
				soyadi[j] = new string;
				*soyadi[j] = o_ad;
				break;
			}
			if (j == 16) {
				cout << "Maalesef butun 1 kisilik odalar dolu." << endl;
				break;
			}
		}
		break;
	case 2:
		for (; k < 46; k++) {
			if (odalar[k] != dolu) {
				odalar[k] = dolu;
				cout << "Adiniz : ";
				cin >> ad;
				cout << "Soyadiniz : ";
				cin >> o_ad;
				cout << "Kac gun kalacaksiniz : ";
				cin >> x2;
				toplam += x2 * 60;
				sayac2++;
				musteri_adi[k] = new string;
				*musteri_adi[k] = ad;
				soyadi[k] = new string;
				*soyadi[k] = o_ad;
				break;
			}
			if (k == 46) {
				cout << "Maalesef tum odalar dolu .\n" << endl;
				break;
			}
		}
		break;
	case 3:
		for (; i < 6; i++) {
			if (odalar[i] != dolu) {
				odalar[i] = dolu;
				cout << "Adiniz : ";
				cin >> ad;
				cout << "Soyadiniz : ";
				cin >> o_ad;
				cout << "Kac gun kalacaksiniz : ";
				cin >> x2;
				toplam += x2 * 300;
				sayac1++;
				musteri_adi[i] = new string;
				*musteri_adi[i] = ad;
				soyadi[i] = new string;
				*soyadi[i] = o_ad;
				break;
			}
			if (i == 6) {
				cout << "Maalesef tum seminer odalari dolu ." << endl;
				break;
			}
		}
		break;
	default:cout << "Gecersiz secim lutfen dogru secim yapiniz.";
	}
}
void otel::oda_bosaltma() {
	cout << "Bosaltacaginiz oda numarasi: ";
	int sayi;
	cin >> sayi;
	if (odalar[sayi] == dolu) {
		if ((sayi > 0) && (sayi < 6)) {
			odalar[sayi] = bos;
			delete musteri_adi[sayi];
			delete soyadi[sayi];
			sayac1--;
			cout << "Oda silindi !" << endl;
		}
		else
			if ((sayi > 5) && (sayi < 46)) {
				odalar[sayi] = bos;
				delete musteri_adi[sayi];
				delete soyadi[sayi];
				sayac2--;
				cout << "Oda silindi !" << endl;
			}
	}
	else cout << "Lutfen oda numarasini dogru giriniz ." << endl;
}
void otel::musterilerin_sayisi() {
	cout << "Dolu oda sayisi : " << sayac1 + sayac2 << endl;
}
void otel::yatak_odasi_raparu() {
	if (sayac2 == 0) {
		cout << "Butun odalar bos." << endl;
	}
	else {
		cout << "Oda numarasi Musteri adi Musteri soyadi" << endl;
		cout << "=======================================" << endl;
		for (int i = 6; i < 36; i++) {
			if (odalar[i] == dolu) {
				cout << i << "\t\t" << musteri_adi[i] << "\t\t" << soyadi[i] << endl;
			}
		}
	}
}
void otel::seminer_odasi_raparu() {
	if (sayac1 == 6) {
		cout << "Butun seminer odalari dolu." << endl;
	}
	else {
		cout << 5 - sayac1 << " tane seminer odasi bos." << endl;
		for (int i = 1; i < 6; i++) {
			if (odalar[i] == dolu) {
				cout << "Seminer odasi " << i << " dolu." << endl;
			}
		}
	}
}
void otel::gelir() {
	cout << "Gelir : " << toplam;
}
int main() {
	otel a;
}