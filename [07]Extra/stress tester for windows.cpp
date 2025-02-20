#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <filesystem>

void execute(const std::string &command) {
    int result = system(command.c_str());
    if (result != 0) {
        std::cerr << "Error executing command: " << command << std::endl;
        exit(1);
    }
}

void cleanUp() {
    std::filesystem::remove("in.txt");
    std::filesystem::remove("out1.txt");
    std::filesystem::remove("out2.txt");
    std::filesystem::remove("diff.txt");
    std::filesystem::remove("candidate.exe");
    std::filesystem::remove("bruteforce.exe");
    std::filesystem::remove("generator.exe");
}

int main() {
    const int iterations = 100;  // Set fixed number of iterations

    // Compile the candidate, bruteforce, and generator code
    execute("g++ candidate.cpp -o candidate.exe");
    execute("g++ bruteforce.cpp -o bruteforce.exe");
    execute("g++ generator.cpp -o generator.exe");

    std::ofstream all("all.txt", std::ios::out | std::ios::trunc);

    for (int i = 1; i <= iterations; ++i) {
        std::cout << "Attempt " << i << "/" << iterations << std::endl;
        all << "Attempt " << i << "/" << iterations << "\n";

        // Generate input case
        execute("generator.exe > in.txt");

        // Log input to all.txt
        std::ifstream in("in.txt");
        all << in.rdbuf();
        in.close();

        // Run brute force and candidate solutions
        execute("bruteforce.exe < in.txt > out1.txt");
        execute("candidate.exe < in.txt > out2.txt");

        // Compare outputs
        if (system("fc out1.txt out2.txt > diff.txt") != 0) {
            std::cout << "\nTest case:\n";
            std::ifstream input("in.txt");
            std::cout << input.rdbuf() << std::endl;
            input.close();

            std::cout << "\nOutputs:\n";
            std::ifstream diff("diff.txt");
            std::cout << diff.rdbuf() << std::endl;
            diff.close();
            break;
        }
    }

    all.close();
    cleanUp();

    return 0;
}


// g++ stress.cpp -o stress.exe
// .\stress.exe
