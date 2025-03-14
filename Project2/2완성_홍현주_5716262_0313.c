#include <stdio.h>
#include <stdlib.h>

typedef union {
    float f;           //float Ÿ���� ����
    unsigned int i;    //���� �޸𸮸� �����ϴ� unsigned int Ÿ���� ����
} FloatIntUnion;

//�Էµ� �Ǽ��� IEEE 754 ǥ������ ����ϴ� �Լ�
void printIEEE754(float num) {
    FloatIntUnion fi; //union ���� ����
    fi.f = num;       //�Էµ� �Ǽ��� union�� ����

    unsigned int sign = (fi.i >> 31) & 0x1;     //1��Ʈ(��ȣ ��Ʈ)

    unsigned int exponent = (fi.i >> 23) & 0xFF;    //8��Ʈ(���� �κ�)

    unsigned int mantissa = fi.i & 0x7FFFFF;    //23��Ʈ(���� �κ�)

    printf("��ȣ (1��Ʈ): %u\n", sign);

    printf("���� (8��Ʈ): ");
    for (int i = 7; i >= 0; i--) {      //8���� ��Ʈ�� �ϳ��� �и��Ͽ� ���
        printf("%u ", (exponent >> i) & 0x1);
    }
    printf("\n");

    printf("���� (23��Ʈ): ");
    for (int i = 22; i >= 0; i--) {     //23���� ��Ʈ�� �ϳ��� �и��Ͽ� ���
        printf("%u ", (mantissa >> i) & 0x1);
    }
    printf("\n");
}

int main() {
    float num;

    // ����ڷκ��� �Ǽ��� �Է¹���
    printf("�Ǽ��� �Է��ϼ���: ");
    scanf_s("%f", &num);

    printIEEE754(num);

    return 0;
}
