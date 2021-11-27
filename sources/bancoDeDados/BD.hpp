template <class FN> void ordena(FN extrai) {
    sort(bancoInterno.begin(), bancoInterno.end(),
         [extrai](BD::dados &a, BD::dados &b) {
             return lexicographical_compare(
                     extrai(a).begin(), extrai(a).end(),
                     extrai(b).begin(), extrai(b).end(),
                     [](const char &char1, const char &char2) {
                         return tolower(char1) < tolower(char2);
                     });
         });
}