typedef struct {
    char NyAp[30];
    float nota;
}tAlum;

int aprobado(void *alum);

int filter(void *vec,int *ce, size_t tam,int (*filtro)(void *));
