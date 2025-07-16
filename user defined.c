//box through tunnel
 
#include <stdio.h>

typedef struct {
    int length;
    int width;
    int height;
} box;

int calculateVOL(box m) {
    return m.length * m.width * m.height;
}

int boxwillpass(box m) {
    return m.height < 41;
}

int main() {
    int n;
    scanf("%d", &n);

    box dimensions[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &dimensions[i].length, &dimensions[i].width, &dimensions[i].height);
    }

    for (int i = 0; i < n; i++) {
        if (boxwillpass(dimensions[i])) {
            int volume = calculateVOL(dimensions[i]);
            printf("%d\n", volume);
        }
    }

    return 0;
}

//Small Triangles, Large Triangles

#include<stdio.h>
#include<math.h>
typedef struct {

    int a,b,c;
    }triangle;

    double calculateAREA(triangle t){
    double p = (t.a + t.b + t.c) / 2.0;
    return sqrt(p * ( p-t.a ) * ( p-t.b ) * ( p-t.c ));

    }
int main()
{
     int n;
     scanf("%d", &n);
     triangle t[n];
     for ( int i=0 ; i<n ; i++)
     {
         scanf("%d %d %d", &t[i].a , &t[i].b , &t[i].c);
     }
     for ( int i =0 ; i<n-1 ; i++)
     {
         for (int j=0 ; j < n-i-1 ; j++){
            if (calculateAREA(t[i]) > calculateAREA (t[j+1]))
            {
                triangle temp = t[i];
                t[j] = t[j+1];
                t[j+1] = temp;
            }
         }
     }
     for( int i = 0 ; i< n ; i++ ){
        printf("%d %d %d \n", t[i].a , t[i].b , t[i].c);
     }
}
//Structuring the Document
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 1005
// الاوتبوت مش راضي يظبط معايا ومش عارف المشكله حتي حاولت ب chatgpt بيقولي ان مفيش مشاكل فالكود
struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;
};

struct paragraph {
    struct sentence* data;
    int sentence_count;
};

struct document {
    struct paragraph* data;
    int paragraph_count;
};

char** split_string(char* str, const char* delimiter, int* count) {
    char** result = NULL;
    *count = 0;
    char* token = strtok(str, delimiter);
    while (token != NULL) {
        result = realloc(result, sizeof(char*) * (*count + 1));
        result[*count] = token;
        (*count)++;
        token = strtok(NULL, delimiter);
    }
    return result;
}

struct document get_document(char* text) {
    struct document doc;
    int para_count;
    char** paragraphs = split_string(text, "\n", &para_count);

    doc.paragraph_count = para_count;
    doc.data = malloc(sizeof(struct paragraph) * para_count);

    for (int i = 0; i < para_count; i++) {
        int sent_count;
        char** sentences = split_string(paragraphs[i], ".", &sent_count);
        doc.data[i].sentence_count = sent_count;
        doc.data[i].data = malloc(sizeof(struct sentence) * sent_count);

        for (int j = 0; j < sent_count; j++) {
            int word_count;
            char** words = split_string(sentences[j], " ", &word_count);
            doc.data[i].data[j].word_count = word_count;
            doc.data[i].data[j].data = malloc(sizeof(struct word) * word_count);

            for (int k = 0; k < word_count; k++) {
                doc.data[i].data[j].data[k].data = malloc(strlen(words[k]) + 1);
                strcpy(doc.data[i].data[j].data[k].data, words[k]);
            }
        }
    }

    return doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document doc, int k, int m, int n) {
    return doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document doc, int k, int m) {
    return doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document doc, int k) {
    return doc.data[k - 1];
}

void print_word(struct word w) {
    printf("%s\n", w.data);
}

void print_sentence(struct sentence s) {
    for (int i = 0; i < s.word_count; i++) {
        printf("%s", s.data[i].data);
        if (i < s.word_count - 1) printf(" ");
    }
    printf("\n");
}

void print_paragraph(struct paragraph p) {
    for (int i = 0; i < p.sentence_count; i++) {
        for (int j = 0; j < p.data[i].word_count; j++) {
            printf("%s", p.data[i].data[j].data);
            if (j < p.data[i].word_count - 1) printf(" ");
        }
        printf(".");
    }
    printf("\n");
}

int main() {
    int paragraph_count;
    scanf("%d\n", &paragraph_count);

    char document_text[MAX_CHARACTERS * 5] = "";
    char paragraph_lines[5][MAX_CHARACTERS];

    for (int i = 0; i < paragraph_count; i++) {
        fgets(paragraph_lines[i], MAX_CHARACTERS, stdin);
        if (paragraph_lines[i][strlen(paragraph_lines[i]) - 1] == '\n') {
            paragraph_lines[i][strlen(paragraph_lines[i]) - 1] = '\0';
        }
    }

    for (int i = 0; i < paragraph_count; i++) {
        strcat(document_text, paragraph_lines[i]);
        if (i < paragraph_count - 1) strcat(document_text, "\n");
    }

    struct document doc = get_document(document_text);

    int query_count;
    scanf("%d", &query_count);

    for (int i = 0; i < query_count; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int k;
            scanf("%d", &k);
            print_paragraph(kth_paragraph(doc, k));
        } else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            print_sentence(kth_sentence_in_mth_paragraph(doc, k, m));
        } else if (type == 3) {
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            print_word(kth_word_in_mth_sentence_of_nth_paragraph(doc, k, m, n));
        }
    }

    return 0;
}
