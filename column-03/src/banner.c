#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void banner(char *data, int len) {
	/*
	 * char *data
	 *   データは[0-9x \n]
	 *   \nの前は[x ]
	 *   [x ]の前の文字は[0-9]{1,}
	 * int len
	 *   データ長, null文字含まない長さ
	 * 出力
	 *   データをprintfで出力する。
	 */
	int i, j, k, num;
	char buf[32];

	for (i = 0, j = 0; i < len; i++) {
		switch (data[i]) {
			case 'x':
			case ' ':
				buf[j] = '\0';
				num = atoi(buf);
				for (k = 0; k < num; k++) {
					printf("%c", data[i]);
				}
				j = 0;
				break;
			case '\n':
				printf("\n");
				break;
			default:
				if (data[i] < '0' || data[i] > '9') {
					fprintf(stderr, "data format error: %c is not allowed in data", data[i]);
					exit(1);
				}
				buf[j++] = data[i];
				break;
		}
	}
}

int main(int argc, char *argv[]) {
	/*
	 * 3x\n
	 * 1 1x1 \n
	 * 1 1x1 \n
	 * 3x\n
	 * のような形でデータを持つ
	 */
	char data[40] = "3x\n1 1x1 \n1 1x1 \n3x\n";
	int len = strlen(data);
	banner(data, len);
	
	return 0;
}
