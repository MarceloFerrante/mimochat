#include <iostream>
#include <email/email.h>
#include <encripta/encripta.h>
using namespace std;

int main() {
    cout << mimochat::conecta(12) << endl;
    encripta::enviaChave();
    return 0;
}
