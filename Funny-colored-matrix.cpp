#include <windows.h>
#include <iostream>

using namespace std;

// j'avais envie de gagner en vitesse au niveau de la génération d'octets aléatoires dans un intervalle choisit


HCRYPTPROV prov;  // les descripteurs pour les CSP
int rand32() {
	if (prov == NULL)
		if (!CryptAcquireContext(&prov, NULL, NULL, PROV_RSA_FULL, CRYPT_SILENT | CRYPT_VERIFYCONTEXT))
			ExitProcess(1);

	int sortie;
    CryptGenRandom(prov, sizeof(sortie), (BYTE*)(&sortie)); // génère un buffer avec des octets aléatoires cryptographique

	return sortie & 0x7fffffff;
}


int main() {
	SetConsoleTitleA("Matrix-Rainbow"); // le titre

	HWND hwnd = GetConsoleWindow(); // le handle de la console
	MoveWindow(hwnd, 20, 20, 800, 400, TRUE); // redimensionne la console
	
	while (true) {
		int c = rand32() % 999; // entiers aléatoires (1000 - 1)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand32() % 15);
		cout << " " << c;

	}
}