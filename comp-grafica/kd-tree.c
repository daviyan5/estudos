#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_K       10              // Máximo de dimensões
#define MAX_N       1000000         // Máximo de pontos
#define MAX_M       10000           // Máximo de consultas
#define MAX_COORD   100000          // Máximo de coordenadas

typedef struct KDNode{
    int axis;
    double *point;
    int index;
    struct KDNode *left, *right;
} KDNode;

KDNode *new_node(int k, double *point, int axis, int index){
    KDNode *node = (KDNode *) malloc(sizeof(KDNode));
    node->point  = (double *) malloc(k * sizeof(double));
    for(int i = 0; i < k; i++){
        node->point[i] = point[i];
    }
    node->axis   = axis;
    node->index  = index;
    node->left   = node->right = NULL;
    return node;
}

KDNode *build_kdtree(int k, int n, double **points){
    
    // Get index of the median element
    
    double **copy_points;
    copy_points = (double **) malloc(n * sizeof(double *));
    for(int i = 0; i < n; i++){
        copy_points[i] = (double *) malloc((k + 1) * sizeof(double));
        for(int j = 0; j < k; j++){
            copy_points[i][j] = points[i][j];
        }
        copy_points[i][k] = i;
    }
    KDNode *recursive_build(int i, int j, int d){
        if(i >= j) return NULL;
        int cmp_func(const void *a, const void *b){
            const double *point_a = *(const double **) a;
            const double *point_b = *(const double **) b;
            if(point_a[d] < point_b[d]) return -1;
            else if(point_a[d] > point_b[d]) return 1;
            else return 0;
        }
        qsort(copy_points + i, j - i, sizeof(double *), cmp_func);
        int m = (i + j) / 2;
        KDNode *node = new_node(k, copy_points[m], d, round(copy_points[m][k]));
        node->left  = recursive_build(i, m, (d + 1) % k);
        node->right = recursive_build(m + 1, j, (d + 1) % k);
        return node;
    }

    KDNode *root = recursive_build(0, n, 0);
    for(int i = 0; i < n; i++){
        free(copy_points[i]);
    }
    free(copy_points);

    return root;
}

double distance(int k, double *point1, double *point2){
    double sum = 0;
    for(int i = 0; i < k; i++){
        sum += (point1[i] - point2[i]) * (point1[i] - point2[i]); 
    }
    return sqrt(sum);
}

void nearest_neighbor(int k, KDNode *cur, double *point, KDNode **best){
    if(cur == NULL) return;

    double cur_dist  = distance(k, point, cur->point);
    double best_dist = (*best)? distance(k, point, (*best)->point) : INFINITY;
    if(cur_dist < best_dist){
        *best = cur;
        best_dist = cur_dist;
    }
    int h       = cur->axis;
    double del  = point[h] - cur->point[h];
    //printf("Best: %.2lf, cur: %d, del: %.2lf\n", best_dist, cur->index, del);

    nearest_neighbor(k, del <= 0 ? cur->left : cur->right, point, best);
    if(fabs(del) < best_dist) nearest_neighbor(k, del <= 0 ? cur->right : cur->left, point, best);
}


void free_kdtree(KDNode *cur){
    if(cur == NULL) return;
    free_kdtree(cur->left);
    free_kdtree(cur->right);
    free(cur->point);
    free(cur);
}

char *zero_padding(int i, int digits){
    char *string = (char *) malloc((digits + 2) * sizeof(char));
    int err = sprintf(string, "%0*d", digits, i);
    if(err < 0){
        printf("Erro na formatação do índice.\n");
        exit(1);
    }
    return string;
}

char *point_to_string(int k, double *point){
    char *string = (char *) malloc((k * 128 + 3) * sizeof(char));
    int err;
    string[0] = '(';
    string[1] = '\0';
    // Formata o primeiro número
    if(fabs(point[0]) > 10001) err = sprintf(string, "(%.2E", point[0]);
    if(point[0] < 0) err = sprintf(string, "(-%07.2lf", -point[0]);
    else err = sprintf(string, "( %07.2lf", point[0]);
    for(int i = 1; i < k; i++){
        char *aux;
        aux = (char *) malloc(128 * sizeof(char));
        aux[0] = '\0';
        // Se o |número| for > 10001, formata como %.2E
        if(fabs(point[i]) > 10001) err = sprintf(aux, ", %.2E", point[i]);
        if(point[i] < 0) err = sprintf(aux, ", -%07.2lf", -point[i]);
        else err = sprintf(aux, ",  %07.2lf", point[i]);

        strcat(string, aux);

        if(err < 1){
            printf("Erro na formatação do ponto.\n");
            exit(2);
        }
        free(aux);
    }
    strcat(string, ")");
    if(err < 1){
        printf("Erro na formatação do ponto.\n");
        exit(1);
    }
    return string;
}

int main(){
    // Número de dimensões
    int k; 
    int err;
    err = scanf("%d", &k);
    k = k % MAX_K;

    // Número de pontos
    int n;
    err = scanf("%d", &n);
    n = n % MAX_N;

    // Pontos
    double **points;
    points = (double **) malloc(n * sizeof(double *));

    // Leitura dos pontos
    for(int i = 0; i < n; i++){
        points[i] = (double *) malloc(k * sizeof(double));
        for(int j = 0; j < k; j++){
            double aux;
            err = scanf("%lf", &aux);
            points[i][j] = aux;
            if(fabs(points[i][j]) > MAX_COORD){
                printf("Erro: ponto p (%d, %d) com valor absoluto > %d.\n", i, j, MAX_COORD);
                exit(1);
            }
        }
    }

    // Construção da árvore
    KDNode *root = build_kdtree(k, n, points);
    printf("%d-D Árvore Construída, com %d pontos.\n", k, n);

    // Número de consultas
    int m;
    err = scanf("%d", &m);
    m = m % MAX_M;
    printf("%d consultas.\n", m);
    // Leitura das consultas
    for(int i = 0; i < m; i++){
        double *point = (double *) malloc(k * sizeof(double));
        for(int j = 0; j < k; j++){
            err = scanf("%lf", &point[j]);
            if(fabs(point[j]) > MAX_COORD){
                printf("Erro: ponto q (%d, %d) com valor absoluto > %d.\n", i, j, MAX_COORD);
                exit(1);
            }
        }
        KDNode *nearest = NULL;
        nearest_neighbor(k, root, point, &nearest);

        char *string_i;                     // Adicionar zeros à esquerda para que tenha ceil(log_11(m)) dígitos
        char *string_i_nearest;             // Adicionar zeros à esquerda para que tenha ceil(log_11(n)) dígitos
        char *string_point;                 // (%.3lf, %.2lf, ..., %.2lf) com k doubles
        char *string_nearest;               // (%.3lf, %.2lf, ..., %.2lf) com k doubles
        
        double min_d    = distance(k, point, nearest->point);

        string_i        = zero_padding(i, ceil(log10(m)));
        string_i_nearest= zero_padding(nearest->index, ceil(log10(n)));
        string_point    = point_to_string(k, point);
        string_nearest  = point_to_string(k, nearest->point);

        printf("Para a %s-ésima consulta ->\n\t%s ==> Index %s | %s | d: %07.2lf.\n", 
                string_i, string_point, string_i_nearest, string_nearest, min_d);
        // Brute-check
        free(point);
        free(string_i);
        free(string_point);
        free(string_nearest);
    }

    // Liberação de memória
    free_kdtree(root);
    for(int i = 0; i < n; i++){
        free(points[i]);
    }
    free(points);

    return 0;
}