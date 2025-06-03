#include <iostream>
#include <fstream>

int main() {
    const size_t N = 1000001;
    std::ofstream out("vetor_ordenado.bin", std::ios::binary);
    if (!out) {
        std::cerr << "Erro ao abrir o arquivo para escrita.\n";
        return 1;
    }

    for (size_t i = 0; i < N; ++i) {
        out.write(reinterpret_cast<const char*>(&i), sizeof(i));
    }

    out.close();
    std::cout << "Vetor ordenado gerado em 'vetor_ordenado.bin'.\n";
    return 0;
}
