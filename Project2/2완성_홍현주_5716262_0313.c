#include <stdio.h>
#include <stdlib.h>

typedef union {
    float f;           //float 타입의 변수
    unsigned int i;    //같은 메모리를 공유하는 unsigned int 타입의 변수
} FloatIntUnion;

//입력된 실수를 IEEE 754 표현으로 출력하는 함수
void printIEEE754(float num) {
    FloatIntUnion fi; //union 변수 선언
    fi.f = num;       //입력된 실수를 union에 저장

    unsigned int sign = (fi.i >> 31) & 0x1;     //1비트(부호 비트)

    unsigned int exponent = (fi.i >> 23) & 0xFF;    //8비트(지수 부분)

    unsigned int mantissa = fi.i & 0x7FFFFF;    //23비트(가수 부분)

    printf("부호 (1비트): %u\n", sign);

    printf("지수 (8비트): ");
    for (int i = 7; i >= 0; i--) {      //8개의 비트를 하나씩 분리하여 출력
        printf("%u ", (exponent >> i) & 0x1);
    }
    printf("\n");

    printf("가수 (23비트): ");
    for (int i = 22; i >= 0; i--) {     //23개의 비트를 하나씩 분리하여 출력
        printf("%u ", (mantissa >> i) & 0x1);
    }
    printf("\n");
}

int main() {
    float num;

    // 사용자로부터 실수를 입력받음
    printf("실수를 입력하세요: ");
    scanf_s("%f", &num);

    printIEEE754(num);

    return 0;
}
