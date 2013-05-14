#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char DENTAKU_NUM[10] = {
	1 << 0 | 1 << 2 | 1 << 3 | 1 << 4 | 1 << 5 | 1 << 6, //0
	1 << 4 | 1 << 6, //1
	1 << 0 | 1 << 1 | 1 << 2 | 1 << 4 | 1 << 5, //2
	1 << 0 | 1 << 1 | 1 << 2 | 1 << 4 | 1 << 6, //3
	1 << 1 | 1 << 3 | 1 << 4 | 1 << 6, //4
	1 << 0 | 1 << 1 | 1 << 2 | 1 << 3 | 1 << 6, //5
	1 << 0 | 1 << 1 | 1 << 2 | 1 << 3 | 1 << 5 | 1 << 6, //6
	1 << 2 | 1 << 4 | 1 << 6, //7
	1 << 0 | 1 << 1 | 1 << 2 | 1 << 3 | 1 << 4 | 1 << 5 | 1 << 6, //8
	1 << 1 | 1 << 2 | 1 << 3 | 1 << 4 | 1 << 6 //9
};

char TEMPLATE[50] = " %s \n%s %s\n %s \n%s %s\n %s \n";

void parse_dentaku(char *num, int len, char (*array)[5]) {
	/*
	 * char *num
	 *   電卓のように表示すべき文字
	 *   [0-9]{1,5}
	 * int len
	 *   文字の長さ1-5
	 * 出力
	 *   要素数5のchar配列
	 */
	int i;

	if (len > 6 || len < 1) {
		fprintf(stderr, "out of range\n");
		exit(1);
	}
	
	for (i = 0; i < len; i++) {
		if (num[i] < '0' || num[i] > '9') {
			fprintf(stderr, "CHAR out of range\n");
			exit(1);
		}
		(*array)[i] = DENTAKU_NUM[num[i]-'0'];
	}
}

void print_dentaku(char array[5], int len) {
	/*
	 * char array[5]
	 *   電卓文字
	 * int len
	 *   文字の長さ1-5
	 * 出力
	 *   printfでnumを電卓っぽく表示
	 *
	 *   2
	 *  3 4
	 *   1
	 *  5 6
	 *   0
	 *   この配列を上から順に0-7にすればよかった・・・
	 *   おかげでくそ長くなった
	 */

	int bits[7] = {0};
	int i;

	for (i = 0; i < len; i++) {
		if ((array[i] & 1) == 1) {
			bits[6] = 1;
		} else {
			bits[6] = 0;
		}
		if (((array[i] >> 1) & 1) == 1) {
			bits[3] = 1;
		} else {
			bits[3] = 0;
		}
		if (((array[i] >> 2) & 1) == 1) {
			bits[0] = 1;
		} else {
			bits[0] = 0;
		}
		if (((array[i] >> 3) & 1) == 1) {
			bits[1] = 1;
		} else {
			bits[1] = 0;
		}
		if (((array[i] >> 4) & 1) == 1) {
			bits[2] = 1;
		} else {
			bits[2] = 0;
		}
		if (((array[i] >> 5) & 1) == 1) {
			bits[4] = 1;
		} else {
			bits[4] = 0;
		}
		if (((array[i] >> 6) & 1) == 1) {
			bits[5] = 1;
		} else {
			bits[5] = 0;
		}

		printf(TEMPLATE,
				(bits[0]) ? "-" : " ", 
				(bits[1]) ? "|" : " ", 
				(bits[2]) ? "|" : " ", 
				(bits[3]) ? "-" : " ", 
				(bits[4]) ? "|" : " ", 
				(bits[5]) ? "|" : " ", 
				(bits[6]) ? "-" : " ");
	}

}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "argc must be 2");
		exit(1);
	}

	char array[5];

	// argv[1]をぱーすして要素5の配列に
	int len = strlen(argv[1]);
	parse_dentaku(argv[1], len, &array);
	
	// 要素5の配列の電卓的表示
	print_dentaku(array, len);
	return 0;
}
