//
// Created by Елена on 2019-06-03.
//

#include <iostream>
#include <vector>

struct Digit {
    explicit Digit(int a) {
        data.resize(sizeof(a) * CHAR_BIT, false);
        for (long i = data.size() - 1; i >= 0 ; --i) {
            data[i] = (a & 1) == 1;
            a >>= 1;
        }
    }

    std::string to_string() {
        std::string ans(data.size(), '0');
        for (size_t i = 0; i < data.size(); ++i) {
            ans[i] = data[i] ? '1' : '0';
        }
        return ans;
    }

    friend std::ostream& operator << (std::ostream &out, Digit &digit) {
        out << digit.to_string();
        return out;
    }


private:
    std::vector<bool> data;
};

int main() {
    int a = -5;
    Digit b(a);
    std::cout << b;
}