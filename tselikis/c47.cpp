#include <iostream>

int main() {
    using std::cout;
    using std::cin;

    unsigned int temp, urg, ack, syn, fin;

    cout << "Enter FIN bit: ";
    cin >> fin;
    cout << "Enter SYN bit: ";
    cin >> syn;
    cout << "Enter ACK bit: ";
    cin >> ack;
    cout << "Enter URG bit: ";
    cin >> urg;

    temp = fin + (syn << 1) + (ack << 4) + (urg << 5);

    cout << "\nEncoding: " << temp << '\n';

    fin = temp & 1;
    syn = (temp >> 1) & 1;
    ack = (temp >> 4) & 1;
    urg = (temp >> 5) & 1;
    cout << "FIN:" << fin << " SYN:" << syn << " ACK:" << ack << " URG:"
            << urg << '\n';

    return 0;
}