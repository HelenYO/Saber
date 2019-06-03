//
// Created by Елена on 2019-06-03.
//

#include <iostream>

void RemoveDups (char *pStr) {
    int index = 0;
    int ind = 0;
    while(pStr[index] != '\0') {
        if(pStr[index] != pStr[ind]) {
            std::cout << pStr[ind];
            ind = index;
        }
        index++;
    }
    if (index > 0) {
        std::cout << pStr[ind];
    }
    std::cout << std::endl;
}

int main() {
    RemoveDups("aassnnnnnkn");
    RemoveDups("gggttt445fjjt66j");
    RemoveDups("");
}