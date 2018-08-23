int readNumber();
void writeAnswer(int x);
 
int main() {
    int x = readNumber();
    int y = readNumber();
    writeAnswer(x + y); // using operator+ to pass the sum of x and y to writeAnswer()
    return 0;
}