#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

#pragma warning(disable : 4996)

struct word {
	char* data;
};

struct sentence {
	struct word* data;
	int word_count;//denotes number of words in a sentence
};

struct paragraph {
	struct sentence* data;
	int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
	struct paragraph* data;
	int paragraph_count;//denotes number of paragraphs in a document
};

struct document get_document(char* text) {
	struct document res;
	int p = 0, s = 0, w = 0, l = 0;
	res.data = (struct paragraph*) malloc(sizeof(struct paragraph) * 1024);
	res.data[p].data = (struct sentence*) malloc(sizeof(struct sentence) * 1024);
	res.data[p].data[s].data = (struct word*) malloc(sizeof(struct word) * 1024);
	res.data[p].data[s].data[w].data = (char*)malloc(sizeof(char) * 1024);

	for (int i = 0; text[i] != '\0'; ++i) {
		char cur = text[i];
		if (cur == ' ' || cur == '.' || cur == '\n') {
			res.data[p].data[s].data[w].data[l++] = '\0';
			res.data[p].data[s].data[w].data = (char*)
				realloc(res.data[p].data[s].data[w].data, sizeof(char) * l);
			++w;
			l = 0;
			if (cur == '.' || cur == '\n') {
				res.data[p].data[s].data = (struct word*)
					realloc(res.data[p].data[s].data, sizeof(struct word) * w);
				res.data[p].data[s].word_count = w;
				s += cur == '.' ? 1 : 0;
				w = 0;

				if (cur == '\n') {
					res.data[p].data = (struct sentence*)
						realloc(res.data[p].data, sizeof(struct sentence) * s);
					res.data[p].sentence_count = s;
					res.data[++p].data = (struct sentence*)malloc(sizeof(struct sentence) * 1024);
					s = 0;
				}
				res.data[p].data[s].data = (struct word*)malloc(sizeof(struct word) * 1024);
			}
			res.data[p].data[s].data[w].data = (char*)malloc(sizeof(char) * 1024);
		}
		else   res.data[p].data[s].data[w].data[l++] = cur;
	}
	res.data[p].data = (struct sentence*)
		realloc(res.data[p].data, sizeof(struct sentence) * s);
	res.data[p].sentence_count = s;
	res.paragraph_count = ++p;
	return res;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
	return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
	return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
	return Doc.data[k - 1];
}


void print_word(struct word w) {
	printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
	for (int i = 0; i < sen.word_count; i++) {
		print_word(sen.data[i]);
		if (i != sen.word_count - 1) {
			printf(" ");
		}
	}
}

void print_paragraph(struct paragraph para) {
	for (int i = 0; i < para.sentence_count; i++) {
		print_sentence(para.data[i]);
		printf(".");
	}
}

void print_document(struct document doc) {
	for (int i = 0; i < doc.paragraph_count; i++) {
		print_paragraph(doc.data[i]);
		if (i != doc.paragraph_count - 1)
			printf("\n");
	}
}

char* get_input_text() {
	int paragraph_count;
	scanf("%d", &paragraph_count);

	char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
	memset(doc, 0, sizeof(doc));
	getchar();
	for (int i = 0; i < paragraph_count; i++) {
		scanf("%[^\n]%*c", p[i]);
		strcat(doc, p[i]);
		if (i != paragraph_count - 1)
			strcat(doc, "\n");
	}

	char* returnDoc = (char*)malloc((strlen(doc) + 1) * (sizeof(char)));
	strcpy(returnDoc, doc);
	return returnDoc;
}

//int main()
//{
//	char* text = get_input_text();
//	struct document Doc = get_document(text);
//
//	int q;
//	scanf("%d", &q);
//
//	while (q--) {
//		int type;
//		scanf("%d", &type);
//
//		if (type == 3) {
//			int k, m, n;
//			scanf("%d %d %d", &k, &m, &n);
//			struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
//			print_word(w);
//		}
//
//		else if (type == 2) {
//			int k, m;
//			scanf("%d %d", &k, &m);
//			struct sentence sen = kth_sentence_in_mth_paragraph(Doc, k, m);
//			print_sentence(sen);
//		}
//
//		else {
//			int k;
//			scanf("%d", &k);
//			struct paragraph para = kth_paragraph(Doc, k);
//			print_paragraph(para);
//		}
//		printf("\n");
//	}
//
//}