#include "lista.c"

int main(void)
{
    TLSE *lista = LSE_inicializa();
    int x;

    menu();
    scanf("%d", &x);

    while (x >= 0)
    {

        switch (x)
        {
        case 0:
            lista = LSE_free(lista);
            break;
        case 1:
            while (x > 0)
            {
                scanf("%d", &x);
                lista = LSE_add_ini(lista, x);
            }
            break;
        case 2:
            while (x > 0)
            {
                scanf("%d", &x);
                lista = LSE_add_ord(lista, x);
            }
            break;
        case 3:
            while (x > 0)
            {
                scanf("%d", &x);
                lista = LSE_add_fim(lista, x);
            }
            break;
        case 4:
            while (x > 0)
            {
                scanf("%d", &x);
                lista = LSE_rem(lista, x);
            }
            break;
        case 5:
            LSE_imp(lista);
            break;
        case 6:
            LSE_imp(lista);
            break;

        default:
            break;
        }

        LSE_imp(lista);
        printf("\n");
        menu();
        scanf("%d", &x);
    }

    return 0;
}