#include <iostream>
#include <limits>

int main() {

    std::cout
        << "type\t\t│ min()\t\t\t│ max()\n"
        << "char\t\t│ "
        << std::numeric_limits<char>::min() << "\t\t\t│ "
        << std::numeric_limits<char>::max() << '\n'

        << "short\t\t│ "
        << std::numeric_limits<short>::min() << "\t\t│ "
        << std::numeric_limits<short>::max() << '\n'

        << "int\t\t│ "
        << std::numeric_limits<int>::min() << "\t\t│ "
        << std::numeric_limits<int>::max() << '\n'

        << "long\t\t│ "
        << std::numeric_limits<long>::min() << "\t│ "
        << std::numeric_limits<long>::max() << '\n'

        << "long long\t│ "
        << std::numeric_limits<long long>::min() << "\t│ "
        << std::numeric_limits<long long>::max() << '\n'

        << "float\t\t│ "
        << std::numeric_limits<float>::min() << "\t\t│ "
        << std::numeric_limits<float>::max() << '\n'

        << "double\t\t│ "
        << std::numeric_limits<double>::min() << "\t\t│ "
        << std::numeric_limits<double>::max() << '\n'

        << "long double\t│ "
        << std::numeric_limits<long double>::min() << "\t\t│ "
        << std::numeric_limits<long double>::max() << '\n'

        << "unsigned int\t│ "
        << std::numeric_limits<unsigned int>::min() << "\t\t\t│ "
        << std::numeric_limits<unsigned int>::max() << '\n';
    
    return 0;
}